/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 00:56:24 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/28 17:37:39 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>
#include "vector.h"

double	to_radian(double degree)
{
	return (degree * M_PI / 180);
}

void	print_vect(t_vect v)
{
	printf("(%lf, %lf, %lf)\n", v.x, v.y, v.z);
}

void	free_cam(t_camera *camera)
{
	if (camera != NULL)
	{
		if (camera->ray != NULL)
			free(camera->ray);
		free(camera);
	}
}

void	free_scene(t_scene *scene)
{
	t_obj	*tmp_obj;
	t_light	*tmp_light;

	if (scene != NULL)
	{
		if (scene->ambient_light != NULL)
			free(scene->ambient_light);
		while (scene->lights != NULL)
		{
			tmp_light = scene->lights->next;
			free(scene->lights);
			scene->lights = tmp_light;
		}
		while (scene->objs != NULL)
		{
			free(scene->objs->content);
			tmp_obj = scene->objs->next;
			free(scene->objs);
			scene->objs = tmp_obj;
		}
		free(scene);
	}
}
