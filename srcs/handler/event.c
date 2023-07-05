/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:24:09 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/05 22:20:30 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include "camera.h"

int i = 0;

int close_event(void *param )
{
	t_minirt	*minirt;
	t_camera	*cam;
	t_obj		*objs;
	t_obj		*tmp_obj;

	minirt = (t_minirt*) param;
	cam = minirt->cam;
	objs = minirt->scene->objs;
	free(cam->ray);
	free(cam);
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
		move_left(minirt->cam, 1);
	else if (keycode == KEY_S)
		move_backward(minirt->cam, 1);
	else if (keycode == KEY_D)
		move_right(minirt->cam, 1);
	else if (keycode == KEY_W)
		move_forward(minirt->cam, 1);
	else if (keycode == KEY_Q)
		move_down(minirt->cam, 1);
	else if (keycode == KEY_E)
		move_up(minirt->cam, 1);
	else if (keycode == LEFT_ARROW)
		pitch_cw(minirt->cam, 0.02);
	else if (keycode == RIGHT_ARROW)
		pitch_ccw(minirt->cam, 0.02);
	else if (keycode == UP_ARROW)
		roll_cw(minirt->cam, 0.02);
	else if (keycode == DOWN_ARROW)
		roll_ccw(minirt->cam, 0.02);
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
	// minirt->cam->rot = normalize(minirt->cam->rot);
	// minirt->cam->right = cross_product(vect(0, 1, 0), minirt->cam->rot);
	// minirt->cam->up = cross_product(minirt->cam->rot, minirt->cam->right);
	calculate_ray(minirt->cam);
	draw(minirt);
	// printf("%d\n", i++);
	// printf("fov = %lf\n", minirt->cam->fov);
	printf("camera position = (%lf, %lf, %lf)\n", minirt->cam->pos.x, minirt->cam->pos.y, minirt->cam->pos.z);
	printf("camera forward ->");
	print_vect(minirt->cam->forward);
	return (0);
}