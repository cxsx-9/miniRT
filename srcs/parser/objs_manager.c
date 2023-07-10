/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:53:17 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/10 13:09:20 by tkraikua         ###   ########.fr       */
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
