/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 01:06:41 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/29 22:31:03 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_camera(char **data, t_minirt *minirt)
{
	t_camera	*cam;
	char		**input;

	cam = malloc(sizeof(t_camera));
	get_coordinate(ft_split(data[1], ','), &cam->pos);
	get_coordinate(ft_split(data[2], ','), &cam->rot);
	get_double(data[3], &cam->fov);
	cam->aspect_ratio = (double) WIN_WIDTH / (double) WIN_HEIGHT;
	cam->ray = malloc(sizeof(t_ray) * WIN_HEIGHT * WIN_WIDTH);
	calculate_ray(cam);
	minirt->cam = cam;
}

void	get_sphere(char **data, t_minirt *minirt)
{
	t_obj		*objs;
	t_sphere	*sphere;
	char		**input;

	objs = malloc(sizeof(t_obj));
	sphere = malloc(sizeof(t_sphere));
	get_coordinate(ft_split(data[1], ','), &sphere->center);
	get_double(data[2], &sphere->d);
	get_color_input(ft_split(data[3], ','), &sphere->color);
	sphere->r = sphere->d / 2;
	objs->id = SPHERE;
	objs->content = (void *) sphere;
	objs->next = NULL;
	lst_objs_addback(&minirt->objs, objs);
}
