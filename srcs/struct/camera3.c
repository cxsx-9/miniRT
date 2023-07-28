/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:45:23 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/28 17:13:48 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "utils.h"

t_vect	rotate_vector(t_vect vector, t_vect axis, double theta)
{
	t_vect	rot_vector;
	double	cos_theta;
	double	sin_theta;

	axis = normalize(axis);
	sin_theta = sin(theta);
	cos_theta = cos(theta);
	rot_vector = multi_vect(vector, cos_theta);
	rot_vector = add_vect(rot_vector, \
				multi_vect(cross_product(axis, vector), sin_theta));
	rot_vector = add_vect(rot_vector, \
				multi_vect(multi_vect(axis, \
				dot_product(axis, vector)), 1 - cos_theta));
	return (rot_vector);
}

void	pitch_cw(t_camera *camera)
{
	camera->forward = rotate_vector(camera->forward, camera->up, 0.02);
	camera->right = cross_product(camera->forward, vect(0, 1, 0));
	camera->up = cross_product(camera->right, camera->forward);
}

void	pitch_ccw(t_camera *camera)
{
	camera->forward = rotate_vector(camera->forward, camera->up, -0.02);
	camera->right = cross_product(camera->forward, vect(0, 1, 0));
	camera->up = cross_product(camera->right, camera->forward);
}

void	roll_cw(t_camera *camera)
{
	camera->forward = rotate_vector(camera->forward, camera->right, 0.02);
	camera->right = cross_product(camera->forward, vect(0, 1, 0));
	camera->up = cross_product(camera->right, camera->forward);
}

void	roll_ccw(t_camera *camera)
{
	camera->forward = rotate_vector(camera->forward, camera->right, -0.02);
	camera->right = cross_product(camera->forward, vect(0, 1, 0));
	camera->up = cross_product(camera->right, camera->forward);
}
