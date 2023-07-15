/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:32:59 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/15 23:23:18 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "color.h"
#include "util.h"

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

t_vect	ambient_light(t_pixel *p, t_scene *s, t_payload *load)
{
	t_al	*al;
	t_vect	obj_color;

	al = s->ambient_light;
	if (!al || p->i > 0)
		return (p->c);
	obj_color = get_object_color(load->obj);
	return (mix_color(al->color, obj_color, al->r, 0));
}

t_vect	point_light(t_pixel *p, t_scene *s, t_payload *load, t_ray *ray)
{
	t_light	*light;
	t_vect	obj_color;
	double	i;

	light = s->lights;
	while (light)
	{
		light->light_dir = normalize(sub_vect(light->center, ray->orig));
		if (!obj_block(*ray, s, light))
		{
			i = fmax(dot_product(load->world_norm, light->light_dir), 0.0);
			obj_color = multi_vect(get_object_color(load->obj), (i * light->b));
			p->c = add_vect(p->c, multi_vect(obj_color, p->multiplier));
		}
		light = light->next;
	}
	return (p->c);
}
