/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:34:02 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/10 22:55:25 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

const int	get_max(char *type)
{
	if (same_str(type, "FOV"))
		return (180);
	else if (same_str(type, "Ratio"))
		return (1);
	else if (same_str(type, "Color"))
		return (255);
	else
		return (INT32_MAX);
}

int	good_size(char *num, char *type)
{
	int	max;

	if (!good_double(num, 1))
		return (0);
	max = get_max(type);
	if (!good_positive_double(num, max))
	{
		ft_putstr_fd(": ", 2);
		write(2, type, ft_strlen(type));
		if (max == 1 || max == 180 || max == 255)
		{
			ft_putstr_fd(" should be in the range [0,", 2);
			ft_putnbr_fd(max, 2);
			ft_putstr_fd("]", 2);
		}
		else
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
		if (!good_integer(input[i], 1) || !good_size(input[i], "Color"))
			status = 0;
	if (status && i != 3)
	{
		ft_putstr_fd(": Not enough color", 2);
		status = 0;
	}
	free_2d(input);
	return (status);
}
