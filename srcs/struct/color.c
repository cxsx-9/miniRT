/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:53:22 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/18 18:09:23 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	color(int r, int g, int b)
{
	t_vect	color;

	color.x = r / 255.0;
	color.y = g / 255.0;
	color.z = b / 255.0;
	return (color);
}

int	get_color(t_vect color)
{
	int	r;
	int	g;
	int	b;

	r = (int)(color.x * 255.0);
	g = (int)(color.y * 255.0);
	b = (int)(color.z * 255.0);
	if (color.x > 1)
		r = 255;
	else if (color.x < 0)
		r = 0;
	if (color.y > 1)
		g = 255;
	else if (color.y < 0)
		g = 0;
	if (color.z > 1)
		b = 255;
	else if (color.z < 0)
		b = 0;
	return (r << 16 | g << 8 | b);
}

t_vect	mix_color(t_vect color1, t_vect color2, double ratio, double mode)
{
	t_vect	color;

	color.x = (color1.x * ratio) + (color2.x * (1 - ratio));
	color.y = (color1.y * ratio) + (color2.y * (1 - ratio));
	color.z = (color1.z * ratio) + (color2.z * (1 - ratio));
	if (mode == 0)
		color = multi_vect(color, ratio);
	else
		color = multi_vect(color, mode);
	return (color);
}
