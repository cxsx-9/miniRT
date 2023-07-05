/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:51:32 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/02 01:26:24 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vector.h"

t_vect	vect(double x, double y, double z)
{
	t_vect	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vect	*new_vect(double x, double y, double z)
{
	t_vect	*v;

	v = malloc(sizeof(t_vect));
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

t_vect	add_vect(t_vect v, t_vect u)
{
	return (vect(v.x + u.x, v.y + u.y, v.z + u.z));
}

t_vect	sub_vect(t_vect v, t_vect u)
{
	return (vect(v.x - u.x, v.y - u.y, v.z - u.z));
}

t_vect	multi_vect(t_vect v, double c)
{
	return (vect(v.x * c, v.y * c, v.z * c));
}

t_vect	divide_vect(t_vect v, double c)
{
	if (c == 0)
	{
		perror("cannot divide by 0\n");
		return (v);
	}
	return (vect(v.x / c, v.y / c, v.z / c));
}

double	dot_product(t_vect v, t_vect u)
{
	return (v.x * u.x + v.y * u.y + v.z * u.z);
}

t_vect	cross_product(t_vect v, t_vect u)
{
	t_vect	vect;

	vect.x = v.y * u.z - v.z * u.y;
	vect.y = v.z * u.x - v.x * u.z;
	vect.z = v.x * u.y - v.y * u.x;
	return (vect);
}

double	dist_vect(t_vect v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

void	print_vect(t_vect v)
{
	printf("(%lf, %lf, %lf)\n", v.x, v.y, v.z);
}

/*
 * convert vector to 1 unit vector
 */

t_vect	normalize(t_vect v)
{
	return (divide_vect(v, dist_vect(v)));
}