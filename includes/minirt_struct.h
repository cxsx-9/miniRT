/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 01:04:00 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/28 15:39:57 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

# include "minirt_mlx.h"
# include "camera.h"
# include "scene.h"

typedef struct s_minirt
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_camera		*cam;
	t_scene			*scene;
	int				status;
}					t_minirt;

t_minirt	*init_minirt(void);

#endif