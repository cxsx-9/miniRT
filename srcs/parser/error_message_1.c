/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:03:35 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/11 00:53:49 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	ft_putstr_fd(":", 2);
	ft_putnbr_fd(line, 2);
	ft_putstr_fd("]\n", 2);
}

int	error_camera_number(t_obj_count *counter)
{
	if (counter->camera == 0)
		ft_putstr_fd(": No Cameara ", 2);
	else if (counter->camera > 1)
		ft_putstr_fd(": Too much Cameara ", 2);
	if (counter->camera != 1)
		return (0);
	return (1);
}

int	error_ambient_number(t_obj_count *counter)
{
	if (counter->ambient > 1)
	{
		ft_putstr_fd(": Too much Ambient Light ", 2);
		return (0);
	}
	return (1);
}

int	error_object_number(char *name, t_obj_count *counter)
{
	if (!error_camera_number(counter) || !error_ambient_number(counter))
	{
		ft_putstr_fd("at [", 2);
		write(2, name, ft_strlen(name));
		ft_putstr_fd("]\n", 2);
		return (0);
	}
	return (1);
}
