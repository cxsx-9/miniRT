/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:34:02 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/01 00:07:37 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	good_ratio(char *num)
{
	double	ratio;

	if (!good_double(num, 1))
		return (0);
	ratio = ft_atof(num);
	if (ratio > 1 || ratio < 0)
	{
		ft_putstr_fd(": The ratio should be in the range [0,1]", 2);
		return (0);
	}
	return (1);
}

int	good_unit(char **unit_vect)
{
	double	n;
	int		i;
	int		zero;

	i = -1;
	zero = 0;
	while (unit_vect[++i])
	{
		n = ft_atof(unit_vect[i]);
		if (n > 1.0 || n < -1.0)
			break ;
		if (n == 0)
			zero++;
	}
	if (i != 3 || zero == 3)
	{
		ft_putstr_fd(": Bad unit vector variable", 2);
		return (0);
	}
	return (1);
}

int	good_size(char *num, char *type, int print)
{
	if (!good_double(num, print))
		return (0);
	if (!good_positive_double(num))
	{
		ft_putstr_fd(": ", 2);
		write(2, type, ft_strlen(type));
		ft_putstr_fd(" should be positive", 2);
		return (0);
	}
	return (1);
}

int	good_coordinate(char **input, int unit_vect)
{
	int	i;
	int	status;

	i = -1;
	status = 1;
	while (input[++i])
		if (!good_double(input[i], 1))
			status = 0;
	if (status && unit_vect && !good_unit(input))
		status = 0;
	if (status && i != 3)
	{
		ft_putstr_fd(": Not enough coordinate", 2);
		status = 0;
	}
	free_2d(input);
	return (status);
}

int	good_color(char **input)
{
	int	i;
	int	status;

	i = -1;
	status = 1;
	while (status && input[++i])
	{
		if (!good_integer(input[i], 1))
			status = 0;
		if (status && !good_positive_int(input[i]))
		{
			ft_putstr_fd(": color should be positive", 2);
			status = 0;
		}
	}
	if (status && i != 3)
	{
		ft_putstr_fd(": Not enough color", 2);
		status = 0;
	}
	free_2d(input);
	return (status);
}
