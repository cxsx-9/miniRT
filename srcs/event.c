/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:24:09 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/18 15:26:22 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int close_event( void )
{
	exit(0);
}

int mouse_event(int button, int x, int y, void *param)
{
	button = (int) button;
	x = (int) x;
	y = (int) y;
	param = (void *) param;
    printf("%d\n", button);
	return (0);
}

int	key_event(int keycode, void *param)
{
	keycode = (int) keycode;
	param = (void *) param;
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}