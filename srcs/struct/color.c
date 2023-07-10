/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:53:22 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/08 17:30:09 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	color(int r, int g, int b)
{
	t_vect color;

	color.x = r / 255.0;
	color.y = g / 255.0;
	color.z = b / 255.0;
	return (color);
}

int	get_color(t_vect color)
{
	int r;
	int g;
	int b;

	r = (int)(color.x * 255.0);
	g = (int)(color.y * 255.0);
	b = (int)(color.z * 255.0);
	return (r << 16 | g << 8 | b);
}