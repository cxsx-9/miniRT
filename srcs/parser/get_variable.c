/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 01:10:32 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/29 22:16:23 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_coordinate(char **input, t_vect *pos)
{
	pos->x = ft_atof(input[0]);
	pos->y = ft_atof(input[1]);
	pos->z = ft_atof(input[2]);
	free_2d(input);
	return (1);
}

int	get_color_input(char **input, t_color *color)
{
	color->r = ft_atoi(input[0]) / 255.0;
	color->g = ft_atoi(input[1]) / 255.0;
	color->b = ft_atoi(input[2]) / 255.0;
	free_2d(input);
	return (1);
}

int	get_integer(char *num, int *des)
{
	if (!good_integer(num, 0))
		return (0);
	*des = ft_atoi(num);
	return (1);
}

int	get_double(char *num, double *des)
{
	if (!good_double(num, 0))
		return (0);
	*des = ft_atof(num);
	return (1);
}
