/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:34:02 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/29 15:52:12 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	good_unit(char *num)
{
	double	n;

	n = ft_atof(num);
	if (n > 1.0 || n < -1.0)
	{
		ft_putstr_fd(": Bad unit vector variable ", 2);
		return (0);
	}
	return (1);
}

int	good_diameter(char *num, int print)
{
	int	neg;

	neg = is_inside('-', num);
	if (!good_double(num, print) || neg)
	{
		if (neg)
			ft_putstr_fd(": Diameter should be positive ", 2);
		return (0);
	}
	return (1);
}

int	good_coordinate(char **input, int unit_vect)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (!good_double(input[i], 1)
			|| (unit_vect && !good_unit(input[i])))
			return (0);
	}
	if (i != 3)
	{
		free_2d(input);
		ft_putstr_fd(": Not enough coordinate ", 2);
		return (0);
	}
	return (1);
}

int	good_color(char **input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (!good_integer(input[i], 1))
			return (0);
		if (is_inside('-', input[i]))
		{
			ft_putstr_fd(": color should be positive ", 2);
			return (0);
		}
	}
	if (i != 3)
	{
		free_2d(input);
		ft_putstr_fd(": Not enough color ", 2);
		return (0);
	}
	return (1);
}
