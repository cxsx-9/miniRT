/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:47:35 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/11 21:00:30 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"
# include "render.h"
# include "color.h"

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

void	closest_hit_sphere(t_ray ray, double hit_distance, t_sphere *sphere, t_payload *payload)
{
	t_vect origin = sub_vect(ray.orig, sphere->center);
	payload->world_pos = add_vect(origin, multi_vect(ray.dir, hit_distance));
	payload->world_norm = normalize(payload->world_pos);						
	payload->world_pos = add_vect(payload->world_pos, sphere->center);
}

void	closest_hit_plane(t_ray ray, double hit_distance, t_plane *plane, t_payload *payload)
{
	// printf("HIT PLANE! ");
	payload->world_norm = plane->dir;
	payload->world_pos = add_vect(ray.orig ,multi_vect(ray.dir, hit_distance));
}

int	hit_plane(t_plane *p, t_ray ray, double *closestT)
{
	double	denom;

	// printf("HIT PLANE! [1]  ");
	denom = dot_product(p->dir, ray.dir);
	if (fabs(denom) > 0.0001)
	{
			// printf("[1] ");
		*closestT = dot_product(sub_vect(p->center, ray.orig), p->dir) / denom;
		if (*closestT > 0.0001)
		{
			return (1);
		}
	}
	// printf("[0] ");
	return (0);
}

int	hit_sphere(t_sphere *sphere, t_ray ray, double *closestT)
{
	t_vect origin = sub_vect(ray.orig, sphere->center);

	double a = dot_product(ray.dir, ray.dir);
	double b = 2 * dot_product(origin, ray.dir);
	double c = dot_product(origin, origin) - sphere->r * sphere->r;

	// check discriminant
	double discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0)
		return (0);
	*closestT = (-b - sqrt(discriminant)) / (2.0 * a);
	if (*closestT < 0)
			*closestT = (-b + sqrt(discriminant)) / (2.0 * a);
	return (1);
}

t_payload	get_closest_hit(t_ray ray, double hit_distance, t_obj *obj)
{
	t_payload	payload;

	payload.obj = obj;
	payload.hit_distance = hit_distance;
	if (obj->id == SPHERE)
		closest_hit_sphere(ray, hit_distance, (t_sphere *) obj->content, &payload);
	else if (obj->id == PLANE)
		closest_hit_plane(ray, hit_distance, (t_plane *) obj->content, &payload);
	return (payload);
}

double	get_closestT(t_obj *obj, t_ray ray, double *closestT)
{
	if (obj->id == SPHERE)
		return (hit_sphere((t_sphere *) obj->content, ray, closestT));
	else if (obj->id == PLANE)
		return (hit_plane((t_plane *) obj->content, ray, closestT));
	else
		return (0);
}

t_payload	ray_trace(t_camera *camera, t_scene *scene, t_ray ray)
{
	t_obj		*objs = scene->objs;
	t_obj		*closest_obj = NULL;
	double	hit_distance = DBL_MAX;
	double	closestT;

	while (objs != NULL)
	{
		if (get_closestT(objs, ray, &closestT) &&
			(closestT > 0 && closestT < hit_distance))
		{
			hit_distance = closestT;
			closest_obj = objs;
		}
		objs = objs->next;
	}
	if (closest_obj == NULL)
		return (miss(ray));
	return (get_closest_hit(ray, hit_distance, closest_obj));
}

t_vect reflect(t_vect incident, t_vect norm)
{
	return (sub_vect(incident, multi_vect(norm,  2.0 * dot_product(incident, norm))));
}

t_vect	get_object_color(t_obj *obj)
{
	if (obj->id == SPHERE)
		return(((t_sphere*)obj->content)->color);
	if (obj->id == PLANE)
		return(((t_plane*)obj->content)->color);
	return (color(0,0,0));
}

// double	set_color_range(double color)
// {
// 	if (color > 1.0)
// 		return (1.0);
// 	else if (color < 0.0)
// 		return (0.0);
// 	else
// 		return (color);
// }

// t_vect	set_color(t_vect color)
// {
// 	t_vect	new_color;

// 	new_color.x = set_color_range(color.x);
// 	new_color.y = set_color_range(color.y);
// 	new_color.z = set_color_range(color.z);
// 	return (new_color);
// }

t_vect	per_pixel(t_camera *camera, t_scene *scene, int x, int y)
{
	t_vect		c = color(0, 0, 0);
	t_ray		ray;
	t_payload	payload;

	ray = camera->ray[x + y * WIN_WIDTH];
	double multiplier = 1.0;
	
	int bounces = 2;
	for (int i = 0; i < bounces; i++)
	{
		payload = ray_trace(camera, scene, ray);
		if (payload.hit_distance < 0){
			t_vect sky_color = color(0, 0, 0);
			c = add_vect(c, multi_vect(sky_color, multiplier));
			break;
		}

		t_vect light_dir = normalize(vect(-1, -1, -1));
		double lightIntensity = MAX(dot_product(payload.world_norm, multi_vect(light_dir, -1)), 0.0); // = cos(angle)
		
		t_vect obj_color = multi_vect(get_object_color(payload.obj), lightIntensity);
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

	x = -1;
	while (x++ < WIN_WIDTH - 1)
	{
		y = -1;
		while (y++ < WIN_HEIGHT - 1)
		{
			t_vect color;
			color = per_pixel(minirt->cam, minirt->scene, x, y);
			img_pix_put(&minirt->img, x, y, get_color(color));
		}
	}
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img.img, 0, 0);
}