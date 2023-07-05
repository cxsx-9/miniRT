/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:34:16 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/02 01:25:45 by tkraikua         ###   ########.fr       */
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
			if (camera->forward.x == 0 && camera->forward.y == 1 && camera->forward.z == 0)
				ray.dir = vect(xx, -z, yy);
			ray.dir = add_vect( add_vect( multi_vect(camera->right, xx) , multi_vect(camera->up, yy)), multi_vect(camera->forward, z) );
			// ray.dir = vect(xx, yy, -z);
			
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

// movement

void	move_forward(t_camera *camera, int speed)
{
	camera->pos = add_vect(camera->pos, camera->forward);
}

void	move_backward(t_camera *camera, int speed)
{
	camera->pos = sub_vect(camera->pos, camera->forward);
}

void	move_right(t_camera *camera, int speed)
{
	camera->pos = add_vect(camera->pos, camera->right);
}

void	move_left(t_camera *camera, int speed)
{
	camera->pos = sub_vect(camera->pos, camera->right);
}

void	move_up(t_camera *camera, int speed)
{
	camera->pos = add_vect(camera->pos, camera->up);
}

void	move_down(t_camera *camera, int speed)
{
	camera->pos = sub_vect(camera->pos, camera->up);
}

// rotate

t_vect	rotate_vector(t_vect vector, t_vect axis, double theta)
{
	axis = normalize(axis);

	double cos_theta = cos(theta);
	double sin_theta = sin(theta);

	t_vect rot_vector = multi_vect(vector, cos_theta);
	rot_vector = add_vect(rot_vector, multi_vect(cross_product(axis, vector), sin_theta));
	rot_vector = add_vect(rot_vector, multi_vect(multi_vect(axis, dot_product(axis,vector)), 1 - cos_theta));
	return (rot_vector);
}

void	pitch_cw(t_camera *camera, double speed)
{
	camera->forward = rotate_vector(camera->forward, camera->up, 0.02);
	camera->right = cross_product(camera->forward, vect(0, 1, 0));
	camera->up = cross_product(camera->right, camera->forward);
}

void	pitch_ccw(t_camera *camera, double speed)
{
	camera->forward = rotate_vector(camera->forward, camera->up, -0.02);
	camera->right = cross_product(camera->forward, vect(0, 1, 0));
	camera->up = cross_product(camera->right, camera->forward);
}

void	roll_cw(t_camera *camera, double speed)
{
	camera->forward = rotate_vector(camera->forward, camera->right, 0.02);
	camera->right = cross_product(camera->forward, vect(0, 1, 0));
	camera->up = cross_product(camera->right, camera->forward);
}

void	roll_ccw(t_camera *camera, double speed)
{
	camera->forward = rotate_vector(camera->forward, camera->right, -0.02);
	camera->right = cross_product(camera->forward, vect(0, 1, 0));
	camera->up = cross_product(camera->right, camera->forward);
}