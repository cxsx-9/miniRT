/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 23:11:18 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/30 23:29:00 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	error_args_count(char **data, int expect_num)
{
	if (args_count(data) != expect_num)
	{
		ft_putstr_fd(": Wrong number of args, it should be ", 2);
		ft_putnbr_fd(expect_num, 2);
		return (0);
	}
	return (1);
}
