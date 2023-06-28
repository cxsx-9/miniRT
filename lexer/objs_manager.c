/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:53:17 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/29 00:54:49 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_obj	*lst_objs_last(t_obj *objs)
{
	if (!objs)
		return (NULL);
	while (objs->next)
		objs = objs->next;
	return (objs);
}

void	lst_objs_addback(t_obj **objs, t_obj *new)
{
	t_obj	*last;

	if (!objs || !new)
		return ;
	if (*objs)
	{
		last = lst_objs_last(*objs);
		last->next = new;
	}
	else
		*objs = new;
}
