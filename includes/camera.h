/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:21:20 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/28 17:12:18 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector.h"
# include "ray.h"

typedef struct s_camera
{
	t_vect			pos;
	t_vect			forward;
	t_vect			right;
	t_vect			up;
	double			fov;
	double			aspect_ratio;
	int				bounces;
	t_ray			*ray;
}	t_camera;

void	calculate_ray(t_camera *camera);

// moving
void	move_forward(t_camera *camera);
void	move_backward(t_camera *camera);
void	move_left(t_camera *camera);
void	move_right(t_camera *camera);
void	move_up(t_camera *camera);
void	move_down(t_camera *camera);

// rotate
void	pitch_cw(t_camera *camera);
void	pitch_ccw(t_camera *camera);
void	roll_cw(t_camera *camera);
void	roll_ccw(t_camera *camera);

#endif