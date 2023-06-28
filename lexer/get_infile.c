/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:27:12 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/29 01:11:53 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	get_line(char *line, t_minirt *minirt)
{
	char	**data;

	data = ft_split_white(line);
	if (same_str(data[0], "C"))
		get_camera(data, minirt);
	else if (same_str(data[0], "sp"))
		get_sphere(data, minirt);
	free_2d(data);
}

void	get_all(char *name, t_minirt *minirt)
{
	char	*line;
	int		fd;

	fd = open(name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] != 0)
			get_line(line, minirt);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
