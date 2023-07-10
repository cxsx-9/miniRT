/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:47:35 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/10 16:20:07 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"
# include "render.h"
# include "color.h"

// t_vect	ray_trace(t_minirt *minirt, t_ray ray)
// {
// 	t_obj *objs = minirt->objs;
// 	t_sphere *closest_sphere = NULL;
// 	double hit_distance = DBL_MAX;

// 	while (objs != NULL)
// 	{
// 		t_sphere* sphere = (t_sphere*) objs->content;
// 		// ray.orig = sub_vect(ray.orig, sphere->center);
// 		t_vect origin = sub_vect(ray.orig, sphere->center);

// 		double a = dot_product(ray.dir, ray.dir);
// 		double b = 2 * dot_product(origin, ray.dir);
// 		double c = dot_product(origin, origin) - sphere->r * sphere->r;

// 		// check discriminant
// 		double discriminant = b * b - 4.0 * a * c;
// 		// printf("Im here\n");
// 		if (discriminant < 0){
// 			objs = objs->next;
// 			continue;
// 		}

// 		// (-b +- sqrt(discriminant)) / (2.0 * a)
// 		double t0 = (-b + sqrt(discriminant)) / (2.0 * a);
// 		double closestT = (-b - sqrt(discriminant)) / (2.0 * a);
// 		if (t0 < 0 && closestT < 0)
// 		{
// 			objs = objs->next;
// 			continue;
// 		}
// 		// printf("%lf\n", closestT);
// 		if (closestT < hit_distance)
// 		{
// 			hit_distance = closestT;
// 			closest_sphere = sphere;
// 			objs = objs->next;
// 			continue;
// 		}
// 		objs = objs->next;
// 	}

// 	if (closest_sphere == NULL)
// 		return (color(135, 206, 235));

// 	t_vect origin = sub_vect(ray.orig, closest_sphere->center);
// 	t_vect hit_point = add_vect(origin, multi_vect(ray.dir, hit_distance));

// 	t_vect normal = normalize(hit_point);

// 	t_vect light_dir = normalize(vect(-1, -1, -1));

// 	double d = MAX(dot_product(normal, multi_vect(light_dir, -1)), 0.0); // = cos(angle)
// 	t_vect color;
// 	color.x = closest_sphere->color.x * d;
// 	color.y = closest_sphere->color.y * d;
// 	color.z = closest_sphere->color.z * d;
// 	return (color);
// }

t_payload	miss(t_ray ray)
{
	t_payload payload;

	payload.hit_distance = -1;
	return (payload);
}

t_payload	closest_hit(t_ray ray, double hit_distance, t_obj *obj)
{
	t_payload	payload;
	t_sphere *closest_sphere;

	payload.hit_distance = hit_distance;
	payload.obj = obj;
	closest_sphere = (t_sphere*) obj->content;
	t_vect origin = sub_vect(ray.orig, closest_sphere->center);
	payload.world_pos = add_vect(origin, multi_vect(ray.dir, hit_distance));
	payload.world_norm = normalize(payload.world_pos);
	payload.world_pos = add_vect(payload.world_pos, closest_sphere->center);
	// payload.world_norm = normalize(sub_vect(payload.world_pos, closest_sphere->center));
	return (payload);
}

t_payload	ray_trace(t_camera *camera, t_scene *scene, t_ray ray)
{
	t_obj		*objs = scene->objs;
	t_obj		*closest_obj = NULL;
	// t_sphere	*closest_sphere = NULL;
	double	hit_distance = DBL_MAX;

	while (objs != NULL)
	{
		// payload = dist_obj(ray, scene, obj);
		t_sphere* sphere = (t_sphere*) objs->content;
		t_vect origin = sub_vect(ray.orig, sphere->center);

		double a = dot_product(ray.dir, ray.dir);
		double b = 2 * dot_product(origin, ray.dir);
		double c = dot_product(origin, origin) - sphere->r * sphere->r;

		// check discriminant
		double discriminant = b * b - 4.0 * a * c;
		if (discriminant < 0){
			objs = objs->next;
			continue;
		}

		// (-b +- sqrt(discriminant)) / (2.0 * a)
		// double t0 = (-b + sqrt(discriminant)) / (2.0 * a);
		double closestT = (-b - sqrt(discriminant)) / (2.0 * a);
		if (closestT < 0)
			closestT = (-b + sqrt(discriminant)) / (2.0 * a);
		// if (t0 < 0 && closestT < 0)
		// {
		// 	objs = objs->next;
		// 	continue;
		// }
		// printf("%lf\n", closestT);
		if (closestT > 0 && closestT < hit_distance)
		{
			hit_distance = closestT;
			closest_obj = objs;
			objs = objs->next;
			continue;
		}
		objs = objs->next;
	}
	if (closest_obj == NULL)
		return (miss(ray));
	return (closest_hit(ray, hit_distance, closest_obj));
}

t_vect reflect(t_vect incident, t_vect norm)
{
	return (sub_vect(incident, multi_vect(norm,  2.0 * dot_product(incident, norm))));
}

t_vect	per_pixel(t_camera *camera, t_scene *scene, int x, int y)
{
	t_vect		c = color(0, 0, 0);
	t_ray		ray;
	t_payload	payload;

	ray = camera->ray[x + y * WIN_WIDTH];
	double multiplier = 1.0;
	
	int bounces = 3;
	for (int i = 0; i < bounces; i++)
	{
		payload = ray_trace(camera, scene, ray);
		if (payload.hit_distance < 0){
			// t_vect sky_color = color(135, 206, 235);
			t_vect sky_color = color(0, 0, 0);
			// c = sky_color;
			c = add_vect(c, multi_vect(sky_color, multiplier));
			break;
			// return sky_color;
		}

		t_vect light_dir = normalize(vect(-1, -1, -1));
		double lightIntensity = MAX(dot_product(payload.world_norm, multi_vect(light_dir, -1)), 0.0); // = cos(angle)
		
		t_vect obj_color = ((t_sphere*)payload.obj->content)->color;
		obj_color = multi_vect(obj_color, lightIntensity);
		// c = multi_vect(((t_sphere*)payload.obj->content)->color, lightIntensity);
		c = add_vect(c, multi_vect(obj_color, multiplier));
		
		multiplier *= 0.7;

		ray.orig = add_vect(payload.world_pos, multi_vect(payload.world_norm, 0.0001));
		// ray.orig = payload.world_pos;
		ray.dir = reflect(ray.dir, payload.world_norm);
	}
	return (c);
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

			t_vect color;
			color = per_pixel(minirt->cam, minirt->scene, x, y);
			// color = ray_trace(minirt, minirt->cam->ray[x + y * WIN_WIDTH]);

			img_pix_put(&minirt->img, x, y, get_color(color));
			// img_pix_put(&minirt->img, x, y, ray_trace(minirt, minirt->cam->ray[x + y * WIN_WIDTH]));
			// img_pix_put(&minirt->img, x, y, get_color(color(135, 206, 235)));
		}
	}
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img.img, 0, 0);
}