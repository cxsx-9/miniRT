/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:27:12 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/10 13:09:41 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_object(char **data, t_minirt *minirt)
{
	if (same_str(data[0], "C"))
		return (get_camera(data, minirt));
	else if (same_str(data[0], "A"))
		return (get_ambient(data, minirt));
	else if (same_str(data[0], "L"))
		return (get_light(data, minirt));
	else if (same_str(data[0], "sp"))
		return (get_sphere(data, minirt));
	else if (same_str(data[0], "pl"))
		return (get_plane(data, minirt));
	else if (same_str(data[0], "cy"))
		return (get_cylinder(data, minirt));
	free_2d(data);
}

void	get_all(char *name, t_minirt *minirt)
{
	char	*line;
	int		fd;
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	minirt->scene = scene;
	minirt->scene->objs = NULL;
	fd = open(name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] != 0)
			get_object(ft_split_white(line), minirt);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
