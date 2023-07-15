/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:21:20 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/16 01:33:58 by csantivi         ###   ########.fr       */
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
void	move_forward(t_camera *camera, int speed);
void	move_backward(t_camera *camera, int speed);
void	move_left(t_camera *camera, int speed);
void	move_right(t_camera *camera, int speed);
void	move_up(t_camera *camera, int speed);
void	move_down(t_camera *camera, int speed);

// rotate
void	pitch_cw(t_camera *camera, double speed);
void	pitch_ccw(t_camera *camera, double speed);
void	roll_cw(t_camera *camera, double speed);
void	roll_ccw(t_camera *camera, double speed);

#endif