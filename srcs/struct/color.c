/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:53:22 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/25 15:59:49 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	color(int r, int g, int b)
{
	t_color color;

	color.r = r / 255.0;
	color.g = g / 255.0;
	color.b = b / 255.0;
	return (color);
}

int	get_color(t_color color)
{
	int r;
	int g;
	int b;

	r = (int)(color.r * 255.0);
	g = (int)(color.g * 255.0);
	b = (int)(color.b * 255.0);
	return (r << 16 | g << 8 | b);
}