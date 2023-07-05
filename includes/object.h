/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:44:11 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/02 00:53:23 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"
# include "color.h"

typedef enum	e_obj_id
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
	double		d;		// the sphere diameter
	double		r;		// the sphere radius
	t_vect 		color;
}	t_sphere;

typedef struct s_plane
{
	t_vect		center;
	t_vect		dir;	// 3d normalized normal vector. In range [-1,1] for each x,y,z axis
	t_vect		color;
}	t_plane;

typedef struct s_cylinder
{
	t_vect		center;
	t_vect		dir;	// 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis
	double		d;		// the cylinder diameter
	double		h;		// the cylinder height
	t_vect		color;
}	t_cylinder;

#endif