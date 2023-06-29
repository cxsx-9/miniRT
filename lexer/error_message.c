/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:03:35 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/29 22:03:49 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	error_unknow_var(char *str)
{
	write(2, str, ft_strlen(str));
	ft_putstr_fd(" : Unknow variable\n", 2);
	return (0);
}

void	error_line(char *name, int line)
{
	ft_putstr_fd(": Bad input at [", 2);
	write(2, name, ft_strlen(name));
	ft_putstr_fd(" ", 2);
	ft_putnbr_fd(line, 2);
	ft_putstr_fd("]\n", 2);
}

int	error_camera(char *name)
{
	ft_putstr_fd(": No cameara at [", 2);
	write(2, name, ft_strlen(name));
	ft_putstr_fd("]\n", 2);
	return (0);
}
