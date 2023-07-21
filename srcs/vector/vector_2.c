/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:11:06 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/16 14:43:49 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vector.h"

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

t_vect	color_vect(t_vect v, t_vect u)
{
	t_vect	vect;

	vect.x = v.x * u.x;
	vect.y = v.y * u.y;
	vect.z = v.z * u.z;
	return (vect);
}

double	dist_vect(t_vect v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

/*
 * convert vector to 1 unit vector
 */

t_vect	normalize(t_vect v)
{
	return (divide_vect(v, dist_vect(v)));
}
