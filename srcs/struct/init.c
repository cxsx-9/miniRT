/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:55:02 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/05 22:19:59 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_minirt	*init_minirt()
{
	t_minirt	*minirt;

	minirt = malloc(sizeof(t_minirt));
	minirt->mlx = mlx_init();
	minirt->win = mlx_new_window(minirt->mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
	minirt->img.img = mlx_new_image(minirt->mlx, WIN_WIDTH, WIN_HEIGHT);
	minirt->img.addr = mlx_get_data_addr(
			minirt->img.img, &minirt->img.bpp,
			&minirt->img.line_len, &minirt->img.endian);
	minirt->cam = NULL;
	minirt->scene = NULL;
	return (minirt);
}