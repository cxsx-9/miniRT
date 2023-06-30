/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:34:16 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/29 19:53:15 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	resize_ray(t_ray **ray)
{
	if (*ray != NULL)
		free(*ray);
	*ray = malloc(sizeof(t_ray) * WIN_HEIGHT * WIN_WIDTH);
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

	// resize_ray(&camera->ray);
	z = calculate_z(camera->fov);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			xx = (double) x / (double) WIN_WIDTH * 2.0 - 1.0;
			yy = - ((double) y / (double) WIN_HEIGHT * 2.0 - 1.0);

			xx *= camera->aspect_ratio;

			ray.orig = camera->pos;

			ray.dir = vect(xx, yy, -z);
			
			camera->ray[x + y * WIN_WIDTH] = ray;
			x++;
		}
		y++;
	}
}

void	free_camera(t_camera *camera)
{
	if (camera->ray != NULL)
		free(camera->ray);
	if (camera != NULL)
		free(camera);
}