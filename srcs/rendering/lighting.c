/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:32:59 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/21 12:55:58 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "color.h"
#include "util.h"


t_vect	reverse_color(t_vect color)
{
	t_vect c;

	c.x = 1 - color.x;
	c.y = 1 - color.y;
	c.z = 1 - color.z;

	return (c);
}

t_vect	sky_color(t_vect c, t_scene *scene)
{
	t_vect	sky;
	t_al	*al;

	sky = color(0, 0, 0);
	al = scene->ambient_light;
	if (al)
		sky = mix_color(al->color, c, al->r, 0);
	c = mix_color(c, sky, 0.7, 1);
	return (c);
}

// -----------------   original
t_vect	ambient_light(t_pixel *p, t_scene *s, t_vect c)
{
	t_al	*al;
	t_vect	result;

	al = s->ambient_light;
	if (!al || p->i > 0)
		return (p->c);
	result = multi_vect(al->color, al->r);
	result = sub_vect(result, reverse_color(c));
	return (result);
}

t_vect	point_light(t_pixel *p, t_scene *s, t_payload *load, t_ray *ray)
{
	t_light	*light;
	t_vect	obj_color;
	double	i;

	light = s->lights;
	obj_color = get_object_color(load->obj);
	p->c = ambient_light(p, s, obj_color);
	while (light)
	{
		light->light_dir = normalize(sub_vect(light->center, ray->orig));
		if (!obj_block(*ray, s, light))
		{
			i = fmax(dot_product(load->world_norm, light->light_dir), 0.0);
			obj_color = multi_vect(obj_color, (i * light->b));
			p->c = add_vect(p->c, multi_vect(obj_color, p->multiplier));
		}
		light = light->next;
	}
	return (p->c);
}

t_vect	lighting(t_pixel *p, t_scene *s, t_payload *load, t_ray *ray)
{
	t_light	*light;
	t_vect	obj_color;
	t_vect	result;
	double	intense;

	result = color(0,0,0);
	light = s->lights;
	obj_color = get_object_color(load->obj);
	result = ambient_light(p, s, obj_color);
	while (light)
	{
		light->light_dir = normalize(sub_vect(light->center, ray->orig));
		if (!obj_block(*ray, s, light))
		{
			// Normal lighting;
			// intense = fmax(dot_product(load->world_norm, light->light_dir), 0.0);
			// intense = intense * light->b * p->multiplier;

			// Phong lighting;
			t_vect reflect_dir = normalize(reflect(light->light_dir, load->world_norm));
			t_vect view_dir = normalize(sub_vect(load->world_pos, ray->orig));
            intense = pow(fmax(dot_product(reflect_dir, view_dir), 0.0), 2) * light->b * p->multiplier;

            // Mixing light
            result = add_vect(result, multi_vect(light->color, intense));
		}
		light = light->next;
	}
	result = sub_vect(result, reverse_color(obj_color));
	if (p->i > 0)
		result = sub_vect(p->c, multi_vect(reverse_color(result), p->multiplier));
	return (result);
}