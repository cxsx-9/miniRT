/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:27:12 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/28 17:13:15 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int get_coordinates(char **input, t_vect *pos)
{
	pos->x = ft_atof(input[0]);
	pos->y = ft_atof(input[1]);
	pos->z = ft_atof(input[2]);
	free_2d(input);
	return (1);
}

int get_color_input(char **input, t_color *color)
{
	color->r = ft_atoi(input[0]) / 255.0;
	color->g = ft_atoi(input[1]) / 255.0;
	color->b = ft_atoi(input[2]) / 255.0;
	free_2d(input);
	return (1);
}

int	get_integer(char *num, int *des)
{
	if (!good_integer(num, 0))
		return (0);
	*des = ft_atoi(num);
	return (1);
}

int	get_double(char *num, double *des)
{
	if (!good_double(num, 0))
		return (0);
	*des = ft_atof(num);
	return (1);
}

void get_camera(char **data, t_minirt *minirt)
{
	t_camera	*cam;
	char		**input;

	cam = malloc(sizeof(t_camera));
	get_coordinates(ft_split(data[1], ','), &cam->pos);
	get_coordinates(ft_split(data[2], ','), &cam->rot);
	get_double(data[3], &cam->fov);
	cam->aspect_ratio = (double) WIN_WIDTH / (double) WIN_HEIGHT;
	calculate_ray(cam);
	minirt->cam = cam;
}

void get_sphere(char **data, t_minirt *minirt)
{
	t_obj		*objs;
	t_sphere	*sphere;
	char		**input;

	objs = malloc(sizeof(t_obj));
	get_coordinates(ft_split(data[1], ','), &sphere->center);
	get_double(data[2], &sphere->d);
	get_color_input(ft_split(data[3], ','), &sphere->color);
	sphere->r = sphere->d / 2;
	objs->id = SPHERE;
	objs->content = (void*) sphere;
	objs->next = NULL;
	lst_objs_addback(&minirt->objs, objs);
}

void	get_line(char *line, t_minirt *minirt)
{
	char **data;

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
