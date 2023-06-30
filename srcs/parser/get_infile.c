/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:27:12 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/29 22:16:14 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_object(char **data, t_minirt *minirt)
{
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
			get_object(ft_split_white(line), minirt);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
