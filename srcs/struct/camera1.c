/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:34:16 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/28 17:11:29 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "utils.h"

void	resize_ray(t_ray **ray)
{
	if (*ray != NULL)
		free(*ray);
	*ray = malloc(sizeof(t_ray) * WIN_HEIGHT * WIN_WIDTH);
}

double	calculate_z(double fov)
{
	return (1 / tan(to_radian(fov) / 2));
}

void	calculate_ray(t_camera *c)
{
	t_vect	v;
	t_ray	ray;
	double	xx;
	double	yy;

	v.z = calculate_z(c->fov);
	v.y = 0;
	while (v.y < WIN_HEIGHT)
	{
		v.x = 0;
		while (v.x < WIN_WIDTH)
		{
			xx = v.x / (double) WIN_WIDTH * 2.0 - 1.0;
			yy = - (v.y / (double) WIN_HEIGHT * 2.0 - 1.0);
			xx *= c->aspect_ratio;
			ray.orig = c->pos;
			ray.dir = add_vect(add_vect(multi_vect(c->right, xx), \
					multi_vect(c->up, yy)), multi_vect(c->forward, v.z));
			c->ray[(int) v.x + (int) v.y * WIN_WIDTH] = ray;
			v.x++;
		}
		v.y++;
	}
}

void	free_camera(t_camera *camera)
{
	if (camera->ray != NULL)
		free(camera->ray);
	if (camera != NULL)
		free(camera);
}

void	move_down(t_camera *camera)
{
	camera->pos = sub_vect(camera->pos, camera->up);
}
