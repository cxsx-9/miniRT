/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:44:29 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/29 22:02:16 by csantivi         ###   ########.fr       */
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

int	check_input(char *name, int fd)
{
	char	*line;
	int		i;
	int		error_status;
	int		cam;

	i = 0;
	error_status = 1;
	line = get_next_line(fd);
	cam = 0;
	while (line != NULL && error_status && i++ != -1)
	{
		if (line[0] != 0)
			error_status = check_line(line, &cam);
		free(line);
		line = get_next_line(fd);
	}
	if (error_status == 0)
		error_line(name, i);
	if (cam == 0)
		error_status = error_camera(name);
	free(line);
	close(fd);
	return (error_status);
}

int	check_all(char *name)
{
	int	fd;

	if (!check_file_name(name) || !check_access(name))
		return (0);
	fd = open(name, O_RDONLY);
	if (!check_input(name, fd))
		return (0);
	return (1);
}
