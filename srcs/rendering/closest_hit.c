/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:29:02 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/16 01:20:04 by csantivi         ###   ########.fr       */
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

void	closest_hit_cy(t_ray ray, double hit_d, t_cylinder *cy, t_payload *load)
{
	t_vect	origin = sub_vect(ray.orig, cy->center);
	// t_vect	origin = ray.orig;
	load->world_pos = add_vect(origin, multi_vect(ray.dir, hit_d));
	// load->world_norm = multi_vect(ray.dir, -1);
	load->world_pos = add_vect(load->world_pos, cy->center);

	double t = dot_product((sub_vect(load->world_pos, cy->center)), cy->dir);
	t_vect pt = add_vect(cy->center, multi_vect(cy->dir, t));
	load->world_norm = normalize(sub_vect(load->world_pos, pt));

	// load->world_norm = normalize(vect(load->world_pos.x - cy->center.x, load->world_pos.y, load->world_pos.z - cy->center.z));
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
	else if (obj->id == CYLINDER)
		closest_hit_cy(ray, hit_d, (t_cylinder *) obj->content, &load);
	return (load);
}
