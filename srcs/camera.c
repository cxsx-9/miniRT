/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:34:16 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/28 22:09:21 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "camera.h"
#include "stdlib.h"
#include "stdio.h"
#include "utils.h"

t_ray	*resize_ray()
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray) * WIN_HEIGHT * WIN_WIDTH);
	return (ray);
}

double calculate_z(double fov)
{
	return (1 / tan(to_radian(fov) / 2));
}

void	calculate_ray(t_camera *camera)
{
	int	x;
	int	y;
	double z;
	t_ray	ray;
	double	xx;
	double	yy;

	camera->ray = resize_ray();
	z = calculate_z(camera->fov);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			xx = (double) x / (double) WIN_WIDTH * 2.0 - 1.0;
			yy = -((double) y / (double) WIN_HEIGHT * 2.0 - 1.0);

			xx *= camera->aspect_ratio;

			ray.orig = camera->pos;

			ray.dir = vect(xx, yy, z);
			
			camera->ray[x + y * WIN_WIDTH] = ray;
			x++;
		}
		y++;
	}
}