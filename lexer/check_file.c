/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:44:29 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/28 00:42:19 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	lastword(char *name)
{
	int	i;

	i = 0;
	if (ft_strchr(name, '/'))
	{
		i = ft_strlen(name);
		while (i && name[i] != '/')
			i--;
		i++;
	}
	return (i);
}

int	check_file_name(char *name)
{
	int		e;
	int		s;
	int		i;
	char	*type;

	type = ".rt";
	e = ft_strlen(name);
	s = lastword(name);
	i = 2;
	while (--e != s && i >= 0)
		if (name[e] != type[i--])
			break ;
	if (i == -1 && e != s)
		return (1);
	ft_putstr_fd(": Invalid name of file\n", 2);
	return (0);
}

int	check_access(char *name)
{
	if (access(name, F_OK | R_OK))
	{
		if (access(name, F_OK))
			ft_putstr_fd(": No such file or directory\n", 2);
		else if (access(name, R_OK))
			ft_putstr_fd(": Permission denied\n", 2);
		return (0);
	}
	return (1);
}


int check_input(char *name, t_minirt *minirt)
{
	char *line;
	int fd;
	int error_status;

	fd = open(name, O_RDONLY);
	error_status = 1;
	line = get_next_line(fd);
	while (line != NULL && error_status)
	{
		if (line[0] != 0)
			error_status = check_line(line, minirt);
		free(line);
		line = get_next_line(fd);
	}
	if (error_status == 0)
		ft_putstr_fd(": Bad input\n", 2);
	free(line);
	close(fd);
	return (error_status);
}

int	check_all(char *name, t_minirt *minirt)
{
	int fd;

	if (!check_file_name(name) || !check_access(name))
		return (0);
	if (!check_input(name, minirt))
		return (0);
	return (1);
}
