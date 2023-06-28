/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:34:02 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/29 01:06:19 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	good_integer(char *num, int print)
{
	int	i;

	i = 0;
	if (num[i] == '+' || num[i] == '-')
		i++;
	while (num[i])
	{
		if (num[i] >= '0' && num[i] <= '9')
			i++;
		else
		{
			if (print)
				ft_putstr_fd(": Bad integer variable ", 2);
			return (0);
		}
	}
	return (1);
}

int	good_double(char *num, int print)
{
	int	dot;
	int	i;

	dot = 1;
	i = 0;
	if (num[i] == '+' || num[i] == '-')
		i++;
	while (num[i] && dot >= 0)
	{
		if (i != 0 && num[i] == '.' )
		{
			dot--;
			i++;
		}
		if (num[i] >= '0' && num[i] <= '9')
			i++;
		else
		{
			if (print)
				ft_putstr_fd(": Bad double variable ", 2);
			return (0);
		}
	}
	return (1);
}

int	good_unit(char *num)
{
	if (!same_str(num, "-1") && !same_str(num, "1"))
	{
		ft_putstr_fd(": Bad unit vector variable ", 2);
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
