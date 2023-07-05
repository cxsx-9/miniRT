/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:44:29 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/02 01:24:11 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "get_next_line.h"

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
	char		*line;
	int			i;
	int			status;
	t_obj_count	counter;

	i = 0;
	status = 1;
	init_object_count(&counter);
	line = get_next_line(fd);
	while (line != NULL && status && i++ != -1)
	{
		if (line[0] != 0)
			status = check_line(line, &counter);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (status == 0)
		error_line(name, i);
	else
		status = error_object_number(name, &counter);
	return (status);
}

int	check_all(char *name)
{
	int	fd;
	int	status;

	status = 1;
	if (!check_file_name(name) || !check_access(name))
		return (0);
	fd = open(name, O_RDONLY);
	if (!check_input(name, fd))
		status = 0;
	close(fd);
	return (status);
}
