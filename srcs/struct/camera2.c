/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:45:37 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/28 17:12:27 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "utils.h"

void	move_forward(t_camera *camera)
{
	camera->pos = add_vect(camera->pos, camera->forward);
}

void	move_backward(t_camera *camera)
{
	camera->pos = sub_vect(camera->pos, camera->forward);
}

void	move_right(t_camera *camera)
{
	camera->pos = add_vect(camera->pos, camera->right);
}

void	move_left(t_camera *camera)
{
	camera->pos = sub_vect(camera->pos, camera->right);
}

void	move_up(t_camera *camera)
{
	camera->pos = add_vect(camera->pos, camera->up);
}
