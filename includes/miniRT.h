/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:49:05 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/12 20:49:05 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <math.h>

# include "minirt_define.h"

# include "libft.h"
# include "mlx.h"

# include "minirt_mlx.h"

# include "control.h"

# include "camera.h"
# include "vector.h"
# include "object.h"
# include "ray.h"
# include "get_next_line.h"

typedef struct		s_minirt
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_camera		*cam;
	t_obj			*objs;
}					t_minirt;

t_minirt	*init_minirt();
# include "lexer.h"

#endif