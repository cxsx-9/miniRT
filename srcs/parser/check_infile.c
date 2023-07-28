/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:00:45 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/28 17:24:38 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int	check_object(char **data, t_obj_count *counter)
{
	if (same_str(data[0], "C"))
		return (check_camera(data, counter));
	else if (same_str(data[0], "A"))
		return (check_ambient(data, counter));
	else if (same_str(data[0], "L"))
		return (check_light(data, counter));
	else if (same_str(data[0], "sp"))
		return (check_sphere(data, counter));
	else if (same_str(data[0], "pl"))
		return (check_plane(data, counter));
	else if (same_str(data[0], "cy"))
		return (check_cylinder(data, counter));
	else
		return (error_unknow_var(data[0]));
}

int	check_line(char *line, t_obj_count *counter)
{
	char	*new_line;
	char	**data;
	int		error_status;

	data = NULL;
	error_status = 1;
	if (is_inside('#', line))
	{
		new_line = ignore_comment(line);
		data = ft_split_white(new_line);
		free(new_line);
	}
	else
		data = ft_split_white(line);
	if (data && data[0])
		error_status = check_object(data, counter);
	free_2d(data);
	return (error_status);
}
