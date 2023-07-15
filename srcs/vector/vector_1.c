/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:51:32 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/15 18:11:49 by csantivi         ###   ########.fr       */
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
