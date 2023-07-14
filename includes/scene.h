/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:39:32 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/14 23:16:05 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "../libft/libft.h"
# include "object.h"

typedef struct s_al
{
	double	r;			// ambient lighting ratio in range [0.0,1.0]
	t_vect	color;
}	t_al;

typedef struct s_light
{
	t_vect			center;
	double			b;		// the light brightness ratio in range [0.0,1.0]
	t_vect			color;
	t_vect			light_dir;
	struct s_light	*next;
}	t_light;

typedef	struct s_scene
{
	t_al	*ambient_light;
	t_light	*lights;
	t_obj	*objs;
}	t_scene;


#endif