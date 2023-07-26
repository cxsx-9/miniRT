/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 01:06:41 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/26 11:45:55 by csantivi         ###   ########.fr       */
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
	t_plane		*plane;

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
	t_cylinder	*cy;

	objs = malloc(sizeof(t_obj));
	cy = malloc(sizeof(t_cylinder));
	get_coordinate(ft_split(data[1], ','), &cy->center);
	get_coordinate(ft_split(data[2], ','), &cy->dir);
	cy->dir = normalize(cy->dir);
	get_double(data[3], &cy->d);
	cy->r = cy->d / 2;
	get_double(data[4], &cy->h);
	cy->top = add_vect(cy->center, multi_vect(cy->dir, cy->h / 2));
	cy->bottom = sub_vect(cy->center, multi_vect(cy->dir, cy->h / 2));
	get_color_input(ft_split(data[5], ','), &cy->color);
	objs->id = CYLINDER;
	objs->content = (void *) cy;
	objs->next = NULL;
	lst_objs_addback(&minirt->scene->objs, objs);
}
