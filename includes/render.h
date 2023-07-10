/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:48:34 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/08 16:38:55 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "minirt.h"

typedef struct s_payload
{
	t_obj	*obj;
	double	hit_distance;
	t_vect	world_pos;
	t_vect	world_norm;
}	t_payload;

void	draw(t_minirt *minirt);
// t_vect	per_pixel(t_camera *camera, t_scene *scene, t_ray ray);
// t_vect ray_trace(t_camera *camera, t_scene *scene, t_ray);

#endif