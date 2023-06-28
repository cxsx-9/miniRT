/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:17:52 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/18 15:26:09 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_H
# define CONTROL_H

# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126
# define KEY_ESC 53
# define KEY_Z 6
# define KEY_X 7

# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define WHEEL_UP 4
# define WHEEL_DOWN 5

int close_event( void );
int mouse_event(int button, int x, int y, void *param);
int	key_event(int keycode, void *param);

#endif