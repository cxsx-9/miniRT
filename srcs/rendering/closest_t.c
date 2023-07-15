/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:42:38 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/15 14:19:25 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

int	hit_plane(t_plane *p, t_ray ray, double *closestT)
{
	double	denom;

	denom = dot_product(p->dir, ray.dir);
	if (fabs(denom) > 0.0001)
	{
		*closestT = dot_product(sub_vect(p->center, ray.orig), p->dir) / denom;
		if (*closestT > 0.0001)
			return (1);
	}
	return (0);
}

int	hit_sphere(t_sphere *sphere, t_ray ray, double *closestT)
{
	t_vect	origin;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	origin = sub_vect(ray.orig, sphere->center);
	a = dot_product(ray.dir, ray.dir);
	b = 2 * dot_product(origin, ray.dir);
	c = dot_product(origin, origin) - sphere->r * sphere->r;
	discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0)
		return (0);
	*closestT = (-b - sqrt(discriminant)) / (2.0 * a);
	if (*closestT < 0)
			*closestT = (-b + sqrt(discriminant)) / (2.0 * a);
	return (1);
}

double	get_closestt(t_obj *obj, t_ray ray, double *closestT)
{
	if (obj->id == SPHERE)
		return (hit_sphere((t_sphere *) obj->content, ray, closestT));
	else if (obj->id == PLANE)
		return (hit_plane((t_plane *) obj->content, ray, closestT));
	else
		return (0);
}
