/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 00:56:24 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/15 18:14:24 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>
#include "vector.h"

double	to_radian(double degree)
{
	return (degree * M_PI / 180);
}

void	print_vect(t_vect v)
{
	printf("(%lf, %lf, %lf)\n", v.x, v.y, v.z);
}
