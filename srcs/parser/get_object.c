/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 01:06:41 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/05 22:51:17 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_sphere(char **data, t_minirt *minirt)
{
	t_obj		*objs;
	t_sphere	*sphere;

	objs = malloc(sizeof(t_obj));
	sphere = malloc(sizeof(t_sphere));
	get_coordinate(ft_split(data[1], ','), &sphere->center);
	get_double(data[2], &sphere->d);
	get_color_input(ft_split(data[3], ','), &sphere->color);
	sphere->r = sphere->d / 2;
	objs->id = SPHERE;
	objs->content = (void *) sphere;
	objs->next = NULL;
	lst_objs_addback(&minirt->scene->objs, objs);
}

void	get_plane(char **data, t_minirt *minirt)
{
	t_obj		*objs;
	t_plane	*plane;

	objs = malloc(sizeof(t_obj));
	plane = malloc(sizeof(t_plane));
	get_coordinate(ft_split(data[1], ','), &plane->center);
	get_coordinate(ft_split(data[2], ','), &plane->dir);
	get_color_input(ft_split(data[3], ','), &plane->color);
	objs->id = PLANE;
	objs->content = (void *) plane;
	objs->next = NULL;
	lst_objs_addback(&minirt->scene->objs, objs);
}

void	get_cylinder(char **data, t_minirt *minirt)
{
	t_obj		*objs;
	t_cylinder	*cylinder;

	objs = malloc(sizeof(t_obj));
	cylinder = malloc(sizeof(t_cylinder));
	get_coordinate(ft_split(data[1], ','), &cylinder->center);
	get_coordinate(ft_split(data[2], ','), &cylinder->dir);
	get_double(data[3], &cylinder->d);
	get_double(data[4], &cylinder->h);
	get_color_input(ft_split(data[5], ','), &cylinder->color);
	objs->id = CYLINDER;
	objs->content = (void *) cylinder;
	objs->next = NULL;
	lst_objs_addback(&minirt->scene->objs, objs);
}
