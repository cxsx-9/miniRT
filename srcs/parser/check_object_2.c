/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 23:36:45 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/01 20:38:03 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_cylinder(char **data, t_obj_count *counter)
{
	char	**input;
	int		status;

	counter->cylinder += 1;
	status = 1;
	if (!error_args_count(data, 6))
		status = 0;
	else if (!good_coordinate(ft_split(data[1], ','), 0)
		|| !good_coordinate(ft_split(data[2], ','), 1)
		|| !good_size(data[3], "Diameter")
		|| !good_size(data[4], "Height")
		|| !good_color(ft_split(data[5], ',')))
		status = 0;
	if (!status)
		ft_putstr_fd(", from 'Cylinder'\n", 2);
	return (status);
}
