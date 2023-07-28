/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:42:53 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/28 17:51:06 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_camera(t_camera *cam)
{
	cam->forward = normalize(cam->forward);
	if (cam->forward.x == 0 && cam->forward.y == 1 && cam->forward.z == 0)
	{
		cam->right = vect(1, 0, 0);
		cam->up = vect(0, 0, 1);
	}
	else if (cam->forward.x == 0 && cam->forward.y == -1 && cam->forward.z == 0)
	{
		cam->right = vect(1, 0, 0);
		cam->up = vect(0, 0, -1);
	}
	else
	{
		cam->right = cross_product(cam->forward, vect(0, 1, 0));
		cam->up = cross_product(cam->right, cam->forward);
	}
}

int	main(int ac, char **av)
{
	t_minirt	*minirt;

	if (ac != 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	minirt = init_minirt();
	if (!check_all(av[1]))
	{
		ft_putstr_fd("Error\n", 2);
		minirt->status = 1;
		close_event(minirt);
	}
	get_all(av[1], minirt);
	printf("Running Program\n");
	set_camera(minirt->cam);
	mlx_loop_hook(minirt->mlx, &loop_event, minirt);
	mlx_hook(minirt->win, 02, 1L << 0, &handle_keypress, minirt);
	mlx_hook(minirt->win, 03, 1L << 1, &handle_keyrelease, minirt);
	mlx_hook(minirt->win, 17, 0L, &close_event, minirt);
	mlx_loop(minirt->mlx);
}
