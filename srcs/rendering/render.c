/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:47:35 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/28 17:16:48 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include "color.h"

t_payload	ray_trace(t_scene *scene, t_ray ray)
{
	t_obj	*objs;
	t_obj	*closest_obj;
	double	hit_distance;
	double	closest_t;

	objs = scene->objs;
	closest_obj = NULL;
	hit_distance = DBL_MAX;
	while (objs != NULL)
	{
		if (get_closestt(objs, ray, &closest_t)
			&& (closest_t > 0 && closest_t < hit_distance))
		{
			hit_distance = closest_t;
			closest_obj = objs;
		}
		objs = objs->next;
	}
	if (closest_obj == NULL)
		return (miss());
	return (get_closest_hit(ray, hit_distance, closest_obj));
}

t_vect	get_object_color(t_obj *obj)
{
	if (obj->id == SPHERE)
		return (((t_sphere *)obj->content)->color);
	if (obj->id == PLANE)
		return (((t_plane *)obj->content)->color);
	if (obj->id == CYLINDER)
		return (((t_cylinder *)obj->content)->color);
	return (color(0, 0, 0));
}

int	obj_block(t_ray ray, t_scene *scene, t_light *light)
{
	t_obj	*objs;
	double	closest_t;
	double	hit_distance;

	ray.dir = light->light_dir;
	objs = scene->objs;
	hit_distance = dist_vect(sub_vect(light->center, ray.orig));
	while (objs != NULL)
	{
		if (get_closestt(objs, ray, &closest_t)
			&& (closest_t > 0 && closest_t < hit_distance))
			return (1);
		objs = objs->next;
	}
	return (0);
}

t_vect	per_pixel(t_camera *camera, t_scene *scene, int x, int y)
{
	t_pixel		pixel;
	t_ray		ray;
	t_payload	load;

	pixel.c = color(0, 0, 0);
	ray = camera->ray[x + y * WIN_WIDTH];
	pixel.multiplier = 1.0;
	pixel.i = 0;
	while (pixel.i < camera->bounces)
	{
		load = ray_trace(scene, ray);
		if (load.hit_distance < 0)
			return (sky_color(pixel.c, scene));
		ray.orig = new_ray_origin(&load);
		pixel.c = lighting(&pixel, scene, &load, &ray);
		pixel.multiplier *= 0.3;
		ray.dir = reflect(ray.dir, load.world_norm);
		pixel.i++;
	}
	return (pixel.c);
}

void	draw(t_minirt *minirt)
{
	t_vect	color;
	int		x;
	int		y;

	x = -1;
	while (x++ < WIN_WIDTH - 1)
	{
		y = -1;
		while (y++ < WIN_HEIGHT - 1)
		{
			color = per_pixel(minirt->cam, minirt->scene, x, y);
			img_pix_put(&minirt->img, x, y, get_color(color));
		}
	}
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img.img, 0, 0);
}
