/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 01:20:06 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/28 17:19:32 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_ambient(char **data, t_obj_count *counter)
{
	int		status;

	counter->ambient += 1;
	status = 1;
	if (!error_args_count(data, 3))
		status = 0;
	else if (!good_size(data[1], "Ratio")
		|| !good_color(ft_split(data[2], ',')))
		status = 0;
	if (!status)
		ft_putstr_fd(", from 'Ambient Light'\n", 2);
	return (status);
}

int	check_camera(char **data, t_obj_count *counter)
{
	int		status;

	counter->camera += 1;
	status = 1;
	if (!error_args_count(data, 4))
		status = 0;
	else if (!good_coordinate(ft_split(data[1], ','), 0)
		|| !good_coordinate(ft_split(data[2], ','), 1)
		|| !good_size(data[3], "FOV"))
		status = 0;
	if (!status)
		ft_putstr_fd(", from 'Camera'\n", 2);
	return (status);
}

int	check_light(char **data, t_obj_count *counter)
{
	int		status;

	counter->light += 1;
	status = 1;
	if (!error_args_count(data, 4))
		status = 0;
	else if (!good_coordinate(ft_split(data[1], ','), 0)
		|| !good_size(data[2], "Ratio")
		|| !good_color(ft_split(data[3], ',')))
		status = 0;
	if (!status)
		ft_putstr_fd(", from 'Light'\n", 2);
	return (status);
}

int	check_sphere(char **data, t_obj_count *counter)
{
	int		status;

	counter->sphere += 1;
	status = 1;
	if (!error_args_count(data, 4))
		status = 0;
	else if (!good_coordinate(ft_split(data[1], ','), 0)
		|| !good_size(data[2], "Diameter")
		|| !good_color(ft_split(data[3], ',')))
		status = 0;
	if (!status)
		ft_putstr_fd(", from 'Sphere'\n", 2);
	return (status);
}

int	check_plane(char **data, t_obj_count *counter)
{
	int		status;

	counter->plane += 1;
	status = 1;
	if (!error_args_count(data, 4))
		status = 0;
	else if (!good_coordinate(ft_split(data[1], ','), 0)
		|| !good_coordinate(ft_split(data[2], ','), 1)
		|| !good_color(ft_split(data[3], ',')))
		status = 0;
	if (!status)
		ft_putstr_fd(", from 'Plane'\n", 2);
	return (status);
}
