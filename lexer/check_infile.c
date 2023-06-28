/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:00:45 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/29 00:59:57 by csantivi         ###   ########.fr       */
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
		ft_putstr_fd("from 'Camera'\n", 2);
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
		|| !good_double(data[2], 1)
		|| is_inside('-', data[2])
		|| !good_color(ft_split(data[3], ',')))
	{
		ft_putstr_fd("from 'Sphere'\n", 2);
		return (0);
	}
	return (1);
}

char	*ignore_comment(char *line)
{
	int		i;
	char	*new;

	i = 0;
	while (line[i] && line[i] != '#')
		i++;
	new = ft_substr(line, 0, i);
	return (new);
}

int	check_line(char *line)
{
	char	**data;
	int		error_status;

	if (is_inside('#', line))
		line = ignore_comment(line);
	data = ft_split_white(line);
	if (data && data[0])
	{
		if (same_str(data[0], "C"))
			error_status = check_camera(data);
		else if (same_str(data[0], "sp"))
			error_status = check_sphere(data);
		else
		{
			write(2, data[0], ft_strlen(data[0]));
			ft_putstr_fd(" : Unknow variable\n", 2);
			error_status = 0;
		}
	}
	free_2d(data);
	return (error_status);
}
