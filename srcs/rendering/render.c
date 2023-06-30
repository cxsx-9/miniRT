/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:47:35 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/29 22:17:23 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"
#define DBL_MAX 1.7976931348623158e+308

// int	ray_trace(t_minirt *minirt, t_ray ray)
// {
// 	t_sphere* spheres[2];
// 	spheres[0] = (t_sphere*) minirt->objs->content;
// 	spheres[1] = (t_sphere*) minirt->objs->next->content;

// 	for (int i = 0; i < 2; i++)
// 	{
// 		t_sphere* sphere = spheres[i];
// 		// ray.orig = sub_vect(ray.orig, sphere->center);
// 		t_vect origin = sub_vect(ray.orig, sphere->center);

// 		double a = dot_product(ray.dir, ray.dir);
// 		double b = 2 * dot_product(origin, ray.dir);
// 		double c = dot_product(origin, origin) - sphere->r * sphere->r;

// 		// check discriminant
// 		double discriminant = b * b - 4.0 * a * c;
// 		if (discriminant < 0)
// 			continue;

// 		// (-b +- sqrt(discriminant)) / (2.0 * a)
// 		double t0 = (-b + sqrt(discriminant)) / (2.0 * a);
// 		double closestT = (-b - sqrt(discriminant)) / (2.0 * a);
// 		if (t0 < 0 && closestT < 0)
// 			continue;

// 		t_vect hit_point = add_vect(origin, multi_vect(ray.dir, closestT));

// 		t_vect normal = normalize(hit_point);

// 		t_vect light_dir = normalize(vect(1, 1, 1));

// 		double d = MAX(dot_product(normal, multi_vect(light_dir, -1)), 0.0); // = cos(angle)
// 		t_color color;
// 		color.r = sphere->color.r * d;
// 		color.g = sphere->color.g * d;
// 		color.b = sphere->color.b * d;
// 		return (get_color(color));
// 	}
// 	return (get_color(color(135, 206, 235)));
// }

int	ray_trace(t_minirt *minirt, t_ray ray)
{
	t_obj *objs = minirt->objs;
	t_sphere *closest_sphere = NULL;
	double hit_distance = DBL_MAX;

	while (objs != NULL)
	{
		t_sphere* sphere = (t_sphere*) objs->content;
		// ray.orig = sub_vect(ray.orig, sphere->center);
		t_vect origin = sub_vect(ray.orig, sphere->center);

		double a = dot_product(ray.dir, ray.dir);
		double b = 2 * dot_product(origin, ray.dir);
		double c = dot_product(origin, origin) - sphere->r * sphere->r;

		// check discriminant
		double discriminant = b * b - 4.0 * a * c;
		// printf("Im here\n");
		if (discriminant < 0){
			objs = objs->next;
			continue;
		}

		// (-b +- sqrt(discriminant)) / (2.0 * a)
		double t0 = (-b + sqrt(discriminant)) / (2.0 * a);
		double closestT = (-b - sqrt(discriminant)) / (2.0 * a);
		if (t0 < 0 && closestT < 0)
		{
			objs = objs->next;
			continue;
		}
		// printf("%lf\n", closestT);
		if (closestT < hit_distance)
		{
			hit_distance = closestT;
			closest_sphere = sphere;
			objs = objs->next;
			continue;
		}
		objs = objs->next;
	}

	if (closest_sphere == NULL)
		return (get_color(color(135, 206, 235)));
	
	t_vect origin = sub_vect(ray.orig, closest_sphere->center);
	t_vect hit_point = add_vect(origin, multi_vect(ray.dir, hit_distance));

	t_vect normal = normalize(hit_point);

	t_vect light_dir = normalize(vect(-1, -1, -1));

	double d = MAX(dot_product(normal, multi_vect(light_dir, -1)), 0.0); // = cos(angle)
	t_color color;
	color.r = closest_sphere->color.r * d;
	color.g = closest_sphere->color.g * d;
	color.b = closest_sphere->color.b * d;
	return (get_color(color));
}

void draw(t_minirt *minirt)
{
	int			x;
	int			y;
	// t_ray		ray;

	// t_sphere *sphere = (t_sphere*)minirt->objs->content;
	x = -1;
	while (x++ < WIN_WIDTH - 1)
	{
		y = -1;
		while (y++ < WIN_HEIGHT - 1)
		{
			// setting primary ray
			// ray.orig = minirt->cam->pos;
			// ray.dir = vect(((double) x / (double) WIN_WIDTH) * 2 - 1, ((double) y / (double) WIN_HEIGHT) * 2 - 1, 1);
			// img_pix_put(&minirt->img, x, y, ray_trace(minirt, ray));

			img_pix_put(&minirt->img, x, y, ray_trace(minirt, minirt->cam->ray[x + y * WIN_WIDTH]));
			// img_pix_put(&minirt->img, x, y, get_color(color(135, 206, 235)));
		}
	}
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img.img, 0, 0);
}