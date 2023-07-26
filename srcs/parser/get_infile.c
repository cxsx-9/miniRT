/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:27:12 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/26 11:43:58 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_object(char **data, t_minirt *minirt)
{
	if (same_str(data[0], "C"))
		get_camera(data, minirt);
	else if (same_str(data[0], "A"))
		get_ambient(data, minirt);
	else if (same_str(data[0], "L"))
		get_light(data, minirt);
	else if (same_str(data[0], "sp"))
		get_sphere(data, minirt);
	else if (same_str(data[0], "pl"))
		get_plane(data, minirt);
	else if (same_str(data[0], "cy"))
		get_cylinder(data, minirt);
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
	minirt->scene->lights = NULL;
	minirt->scene->ambient_light = NULL;
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
