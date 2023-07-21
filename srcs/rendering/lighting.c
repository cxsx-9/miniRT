/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:32:59 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/21 18:43:01 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "color.h"
#include "util.h"

t_vect	rev_color(t_vect color)
{
	t_vect	c;

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

t_vect	ambient_light(t_pixel *p, t_scene *s, t_vect c)
{
	t_al	*al;
	t_vect	result;

	al = s->ambient_light;
	if (!al || p->i > 0)
		return (p->c);
	result = multi_vect(al->color, al->r);
	result = sub_vect(result, rev_color(c));
	return (result);
}

double	phong_light(t_pixel *p, t_payload *load, t_light *light, t_ray *ray)
{
	double	diffuse;
	double	specular;
	t_vect	reflect_dir;
	t_vect	view_dir;

	diffuse = fmax(dot_product(load->world_norm, light->light_dir), 0.0);
	reflect_dir = normalize(reflect(light->light_dir, load->world_norm));
	view_dir = normalize(sub_vect(load->world_pos, ray->orig));
	specular = pow(fmax(dot_product(reflect_dir, view_dir), 0.0), 12);
	return ((diffuse + specular) / 2 * light->b * p->multiplier);
}

t_vect	lighting(t_pixel *p, t_scene *s, t_payload *load, t_ray *ray)
{
	t_light	*light;
	t_vect	obj_color;
	t_vect	result;
	double	intense;

	result = color(0, 0, 0);
	light = s->lights;
	obj_color = get_object_color(load->obj);
	result = ambient_light(p, s, obj_color);
	while (light)
	{
		light->light_dir = normalize(sub_vect(light->center, ray->orig));
		if (!obj_block(*ray, s, light))
		{
			intense = phong_light(p, load, light, ray);
			result = add_vect(result, multi_vect(light->color, intense));
		}
		light = light->next;
	}
	result = sub_vect(result, rev_color(obj_color));
	if (p->i > 0)
		result = sub_vect(p->c, multi_vect(rev_color(result), p->multiplier));
	return (result);
}

// Normal light  (diffuse)
// intense = fmax(dot_product(load->world_norm, light->light_dir), 0.0);
// intense = intense * light->b * p->multiplier;