/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 22:23:08 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/18 15:16:13 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_camera(char **data, t_minirt *minirt)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	get_coordinate(ft_split(data[1], ','), &cam->pos);
	get_coordinate(ft_split(data[2], ','), &cam->forward);
	get_double(data[3], &cam->fov);
	cam->aspect_ratio = (double) WIN_WIDTH / (double) WIN_HEIGHT;
	cam->ray = malloc(sizeof(t_ray) * WIN_HEIGHT * WIN_WIDTH);
	calculate_ray(cam);
	cam->bounces = 1;
	minirt->cam = cam;
}

void	get_ambient(char **data, t_minirt *minirt)
{
	t_al	*ambient;

	ambient = malloc(sizeof(t_al));
	get_double(data[1], &ambient->r);
	get_color_input(ft_split(data[2], ','), &ambient->color);
	minirt->scene->ambient_light = ambient;
}

void	get_light(char **data, t_minirt *minirt)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	get_coordinate(ft_split(data[1], ','), &light->center);
	get_double(data[2], &light->b);
	get_color_input(ft_split(data[3], ','), &light->color);
	light->next = NULL;
	lst_lights_addback(&minirt->scene->lights, light);
}
