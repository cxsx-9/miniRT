/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_until.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 00:57:51 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/29 16:37:04 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	args_count(char **str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

int	is_inside(char c, char *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

int	same_str(char *a, char *b)
{
	if (a == 0 || b == 0)
		return (0);
	if (!ft_strncmp(a, b, ft_strlen(a))
		&& ft_strlen(a) == ft_strlen(b))
		return (1);
	return (0);
}

void	show_2d(char **input)
{
	int	i;

	if (!input || !*input)
		return ;
	i = 0;
	while (input[i])
		dprintf(2, "%s,", input[i++]);
	dprintf(2, "\n");
}
