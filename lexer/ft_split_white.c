/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_white.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:41:55 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/29 00:54:17 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	word_count(char *s)
{
	int	n;

	n = 0;
	while (*s)
	{
		while (is_white_space(*s))
			s++;
		if (!is_white_space(*s) && *s)
			n++;
		while (!is_white_space(*s) && *s)
			s++;
	}
	return (n);
}

char	*fill_str(char *s)
{
	int		i;
	char	*txt;

	i = 0;
	while (s[i] && !is_white_space(s[i]))
		i++;
	txt = (char *)malloc(sizeof(char) * (i + 1));
	if (!txt)
		return (NULL);
	ft_strlcpy(txt, s, i + 1);
	return (txt);
}

char	**ft_split_white2(char *s, int n, char **str)
{
	int	i;

	i = 0;
	while (i < n)
	{
		while (is_white_space(*s))
			s++;
		str[i] = fill_str(s);
		if (!str[i])
		{
			while (i)
				free(str[i--]);
			free(str);
			return (NULL);
		}
		s = s + ft_strlen(str[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split_white(char *s)
{
	int		n;
	char	**str;

	if (!s || !s[0])
		return (NULL);
	n = word_count(s);
	str = (char **)malloc(sizeof(char *) * (n + 1));
	if (!str)
		return (NULL);
	return (ft_split_white2(s, n, str));
}
