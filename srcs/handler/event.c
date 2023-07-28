/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:24:09 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/28 17:21:58 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include "camera.h"
#include "utils.h"

int	close_event(void *param)
{
	t_minirt	*minirt;
	int			i;

	minirt = (t_minirt *) param;
	free_cam(minirt->cam);
	free_scene(minirt->scene);
	i = minirt->status;
	if (minirt != NULL)
		free(minirt);
	exit(i);
}

static int	movement(int keycode, t_minirt *minirt)
{
	if (keycode == KEY_A)
		move_left(minirt->cam);
	else if (keycode == KEY_S)
		move_backward(minirt->cam);
	else if (keycode == KEY_D)
		move_right(minirt->cam);
	else if (keycode == KEY_W)
		move_forward(minirt->cam);
	else if (keycode == KEY_Q)
		move_down(minirt->cam);
	else if (keycode == KEY_E)
		move_up(minirt->cam);
	else
		return (0);
	return (1);
}

int	handle_keypress(int keycode, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *) param;
	if (movement(keycode, minirt))
		return (0);
	else if (keycode == LEFT_ARROW)
		pitch_cw(minirt->cam);
	else if (keycode == RIGHT_ARROW)
		pitch_ccw(minirt->cam);
	else if (keycode == UP_ARROW)
		roll_cw(minirt->cam);
	else if (keycode == DOWN_ARROW)
		roll_ccw(minirt->cam);
	else if (keycode == LEFT_SQUARE_BRACKETS)
		minirt->cam->fov -= 1;
	else if (keycode == RIGHT_SQUARE_BRACKETS)
		minirt->cam->fov += 1;
	else if (keycode == KEY_MINUS)
	{
		if (minirt->cam->bounces > 1)
			minirt->cam->bounces -= 1;
	}
	else if (keycode == KEY_PLUS)
		minirt->cam->bounces += 1;
	return (0);
}

int	handle_keyrelease(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		close_event(param);
	return (0);
}

int	loop_event(void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *) param;
	calculate_ray(minirt->cam);
	draw(minirt);
	return (0);
}
