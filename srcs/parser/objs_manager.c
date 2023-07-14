/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:53:17 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/15 00:27:40 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_object_count(t_obj_count *counter)
{
	counter->camera = 0;
	counter->ambient = 0;
	counter->light = 0;
	counter->sphere = 0;
	counter->plane = 0;
	counter->cylinder = 0;
}

t_obj	*lst_objs_last(t_obj *objs)
{
	if (!objs)
		return (NULL);
	while (objs->next)
		objs = objs->next;
	return (objs);
}

t_light	*lst_lights_last(t_light *light)
{
	if (!light)
		return (NULL);
	while (light->next)
		light = light->next;
	return (light);
}

void	lst_objs_addback(t_obj **objs, t_obj *new_obj)
{
	t_obj	*last;

	if (!objs || !new_obj)
		return ;
	if (*objs)
	{
		last = lst_objs_last(*objs);
		last->next = new_obj;
	}
	else
		*objs = new_obj;
}

void	lst_lights_addback(t_light **lights, t_light *new_light)
{
	t_light	*last;

	if (!lights || !new_light)
		return ;
	if (*lights)
	{
		last = lst_lights_last(*lights);
		last->next = new_light;
	}
	else
		*lights = new_light;
}
