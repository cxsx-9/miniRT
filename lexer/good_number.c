/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:49:56 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/29 15:50:28 by csantivi         ###   ########.fr       */
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
