/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 01:10:32 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/05 22:32:20 by csantivi         ###   ########.fr       */
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

int	get_color_input(char **input, t_vect *color)
{
	color->x = ft_atoi(input[0]) / 255.0;
	color->y = ft_atoi(input[1]) / 255.0;
	color->z = ft_atoi(input[2]) / 255.0;
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
