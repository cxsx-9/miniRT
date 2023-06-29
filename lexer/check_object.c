/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 01:20:06 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/29 01:46:07 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_camera(char **data)
{
	char		**input;
	int			status;

	if (args_count(data) != 4)
	{
		ft_putstr_fd(": Wrong number of args from 'Camera'\n", 2);
		return (0);
	}
	if (!good_coordinate(ft_split(data[1], ','), 0)
		|| !good_coordinate(ft_split(data[2], ','), 1)
		|| !good_double(data[3], 1))
	{
		ft_putstr_fd(", from 'Camera'\n", 2);
		return (0);
	}
	return (1);
}

int	check_sphere(char **data)
{
	char		**input;
	int			status;

	if (args_count(data) != 4)
	{
		ft_putstr_fd(": Wrong number of args from 'Sphere'\n", 2);
		return (0);
	}
	if (!good_coordinate(ft_split(data[1], ','), 0)
		|| !good_diameter(data[2], 1)
		|| !good_color(ft_split(data[3], ',')))
	{
		ft_putstr_fd(", from 'Sphere'\n", 2);
		return (0);
	}
	return (1);
}
