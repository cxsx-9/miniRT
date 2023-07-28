/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:42:38 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/28 16:33:14 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

int	hit_plane(t_plane *p, t_ray ray, double *closestT)
{
	double	denom;

	denom = dot_product(p->dir, ray.dir);
	if (fabs(denom) > EPSILON)
	{
		*closestT = dot_product(sub_vect(p->center, ray.orig), p->dir) / denom;
		if (*closestT > EPSILON)
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

int	cylinder_caps(t_cylinder *cy, t_ray ray, double *cT, double t)
{
	double	denom;
	t_vect	p;
	t_vect	v;
	double	d2;

	denom = dot_product(cy->dir, ray.dir);
	if (fabs(denom) > EPSILON)
	{
		if (t >= cy->h / 2)
			*cT = dot_product(sub_vect(cy->top, ray.orig), cy->dir) / denom;
		else if (t <= -cy->h / 2)
			*cT = dot_product(sub_vect(cy->bottom, ray.orig), cy->dir) / denom;
		if (*cT > EPSILON)
		{
			p = add_vect(ray.orig, multi_vect(ray.dir, *cT));
			if (t >= cy->h / 2)
				v = sub_vect(p, cy->top);
			else
				v = sub_vect(p, cy->bottom);
			d2 = dot_product(v, v);
			if (sqrtf(d2) <= cy->r)
				return (1);
		}
	}
	return (0);
}

int	hit_cylinder(t_cylinder *cy, t_ray ray, double *closestT)
{
	t_vect	originxdir;
	t_vect	rdxdir;
	t_vect	v;
	double	discriminant;
	double	t;

	originxdir = cross_product(sub_vect(ray.orig, cy->center), cy->dir);
	rdxdir = cross_product(ray.dir, cy->dir);
	v.x = dot_product(rdxdir, rdxdir);
	v.y = 2 * dot_product(rdxdir, originxdir);
	v.z = dot_product(originxdir, originxdir) - (cy->r * cy->r);
	discriminant = v.y * v.y - 4.0 * v.x * v.z;
	if (discriminant < 0)
		return (0);
	*closestT = (-v.y - sqrt(discriminant)) / (2.0 * v.x);
	if (*closestT < 0)
		*closestT = (-v.y + sqrt(discriminant)) / (2.0 * v.x);
	t = dot_product((sub_vect(add_vect(ray.orig, \
			multi_vect(ray.dir, *closestT)), cy->center)), normalize(cy->dir));
	if (t >= cy->h / 2 || t <= -cy->h / 2)
	{
		*closestT = DBL_MAX;
		return (cylinder_caps(cy, ray, closestT, t));
	}
	return (1);
}

double	get_closestt(t_obj *obj, t_ray ray, double *closestT)
{
	if (obj->id == SPHERE)
		return (hit_sphere((t_sphere *) obj->content, ray, closestT));
	if (obj->id == PLANE)
		return (hit_plane((t_plane *) obj->content, ray, closestT));
	if (obj->id == CYLINDER)
		return (hit_cylinder((t_cylinder *) obj->content, ray, closestT));
	return (0);
}
