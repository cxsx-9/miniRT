/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:29:02 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/15 18:06:08 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

t_payload	miss(t_ray ray)
{
	t_payload	payload;

	payload.hit_distance = -1;
	return (payload);
}

void	closest_hit_sp(t_ray ray, double hit_d, t_sphere *s, t_payload *l)
{
	t_vect	origin;

	origin = sub_vect(ray.orig, s->center);
	l->world_pos = add_vect(origin, multi_vect(ray.dir, hit_d));
	l->world_norm = normalize(l->world_pos);
	l->world_pos = add_vect(l->world_pos, s->center);
}

void	closest_hit_pl(t_ray ray, double hit_d, t_plane *p, t_payload *l)
{
	l->world_norm = p->dir;
	l->world_pos = add_vect(ray.orig, multi_vect(ray.dir, hit_d));
}

t_payload	get_closest_hit(t_ray ray, double hit_d, t_obj *obj)
{
	t_payload	load;

	load.obj = obj;
	load.hit_distance = hit_d;
	if (obj->id == SPHERE)
		closest_hit_sp(ray, hit_d, (t_sphere *) obj->content, &load);
	else if (obj->id == PLANE)
		closest_hit_pl(ray, hit_d, (t_plane *) obj->content, &load);
	return (load);
}
