/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:24:09 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/30 11:53:37 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

int i = 0;

int close_event(void *param )
{
	t_minirt	*minirt;
	t_camera	*cam;
	t_obj		*objs;
	t_obj		*tmp_obj;

	minirt = (t_minirt*) param;
	cam = minirt->cam;
	objs = minirt->objs;
	if (cam)
	{
		free(cam->ray);
		free(cam);
	}
	while (objs)
	{
		tmp_obj = objs->next;
		free(objs->content);
		free(objs);
		objs = tmp_obj;
	}
	// mlx_destroy_image(minirt->mlx, minirt->img.img);
	// mlx_destroy_window(minirt->mlx, minirt->win);
	// free(minirt->mlx);
	free(minirt);
	exit(0);
	// return (0);
}

// int mouse_event(int button, int x, int y, void *param)
// {
// 	button = (int) button;
// 	x = (int) x;
// 	y = (int) y;
// 	param = (void *) param;
//     printf("%d\n", button);
// 	return (0);
// }

// int	key_event(int keycode, void *param)
// {
// 	t_minirt *minirt;
	
// 	minirt = (t_minirt *) param;
// 	// printf("keycode -> %d\n", keycode);
// 	if (keycode == KEY_ESC)
// 		exit(0);
// 	else if (keycode == LEFT_SQUARE_BRACKETS)
// 		minirt->cam->fov -= 2;
// 	else if (keycode == RIGHT_SQUARE_BRACKETS)
// 		minirt->cam->fov += 2;
// 	calculate_ray(minirt->cam);
// 	draw(minirt);
// 	return (0);
// }

int handle_keypress(int keycode, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt*) param;
	// printf("keypresed -> %d\n", keycode);
	if (keycode == LEFT_SQUARE_BRACKETS)
		minirt->cam->fov -= 1;
	else if (keycode == RIGHT_SQUARE_BRACKETS)
		minirt->cam->fov += 1;
	else if (keycode == KEY_A)
		minirt->cam->pos.x -= 0.5;
	else if (keycode == KEY_S)
		minirt->cam->pos.z += 0.5;
	else if (keycode == KEY_D)
		minirt->cam->pos.x += 0.5;
	else if (keycode == KEY_W)
		minirt->cam->pos.z -= 0.5;
	else if (keycode == KEY_Q)
		minirt->cam->pos.y -= 0.5;
	else if (keycode == KEY_E)
		minirt->cam->pos.y += 0.5;
	return (0);
}

int handle_keyrelease(int keycode, void *param)
{
	// printf("keyreleased -> %d\n", keycode);
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int loop_event(void *param)
{
	t_minirt *minirt;

	minirt = (t_minirt*) param;
	calculate_ray(minirt->cam);
	draw(minirt);
	// printf("%d\n", i++);
	// printf("fov = %lf\n", minirt->camera->fov);
	// printf("camera position = (%lf, %lf, %lf)\n", minirt->camera->pos.x, minirt->camera->pos.y, minirt->camera->pos.z);
	return (0);
}