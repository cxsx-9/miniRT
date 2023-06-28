/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:21:20 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/25 19:54:32 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H


# include "minirt_define.h"
# include "vector.h"
# include "ray.h"

typedef struct s_screen
{
	double	horizontal;
	double	vertical;
} t_screen;


typedef struct s_camera
{
	t_vect			pos;
	t_vect			rot;	// 3d normalized orientation vector. In range [-1,1] for each x,y,z axis
	double			fov;	// FOV : Horizontal field of view in degrees in range [0,180]
	double			aspect_ratio;
	t_screen		screen;
	t_ray			*ray;
}	t_camera;

void	calculate_ray(t_camera *camera);

#endif