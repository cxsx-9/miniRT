/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:44:11 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/15 12:01:56 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"
# include "color.h"

typedef enum e_obj_id
{
	SPHERE,
	PLANE,
	CYLINDER
}				t_obj_id;

typedef struct s_obj
{
	t_obj_id			id;
	void				*content;
	struct s_obj		*next;
}	t_obj;

typedef struct s_sphere
{
	t_vect		center;
	double		d;
	double		r;
	t_vect		color;
}	t_sphere;

typedef struct s_plane
{
	t_vect		center;
	t_vect		dir;
	t_vect		color;
}	t_plane;

typedef struct s_cylinder
{
	t_vect		center;
	t_vect		dir;
	double		d;
	double		h;
	t_vect		color;
}	t_cylinder;

#endif