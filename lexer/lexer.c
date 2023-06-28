/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:00:45 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/28 01:21:52 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	same_str(char *a, char *b)
{
	if (!ft_strncmp(a, b, ft_strlen(a))
		&& ft_strlen(a) == ft_strlen(b))
		return (1);
	return (0);
}

int	good_integer(char *num)
{
	int i;

	i = 0;
	if (num[i] == '+' || num[i] == '-')
		i++;
	while (num[i])
	{
		if (num[i] >= '0' && num[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	good_double(char *num)
{
	int dot;
	int i;

	dot = 1;
	i = 0;
	if (num[i] == '+' || num[i] == '-')
		i++;
	while (num[i] && dot >= 0)
	{
		if (num[i] == '.')
		{
			dot--;
			i++;
		}
		if (num[i] >= '0' && num[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

double	double_atoi(char *str)
{
	int		i;
	double	neg;
	double	num;
	double	dnum;

	neg = 1;
	i = 0;
	num = 0;
	dnum = 0.1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + str[i++] - '0';
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			num += (dnum * (str[i] - '0'));
			dnum /= 10;
			i++;
		}
	}
	return (neg * num);
}

int get_coordinates(char **input, t_vect *pos)
{
	t_camera	*cam;
	int			i;

	i = -1;
	while (input[++i])
	{
		if (!good_double(input[i]))
		{
			free_2d(input);
			ft_putstr_fd(": Bad Double\n", 2);
			return (0);
		}
	}
	if (i != 3)
	{
		free_2d(input);
			ft_putstr_fd(": Not enough coordinate\n", 2);
		return (0);
	}
	pos->x = double_atoi(input[0]);
	pos->y = double_atoi(input[1]);
	pos->z = double_atoi(input[2]);
	printf("%s -> %f\n%s -> %f\n",input[0] ,double_atoi(input[0]), input[1] ,double_atoi(input[1]));
	free_2d(input);
	return (1);
}

int	get_integer(char *num, int *des)
{
	if (!good_integer(num))
		return (0);
	*des = ft_atoi(num);
	return (1);
}

int	get_double(char *num, double *des)
{
	if (!good_double(num))
		return (0);
	*des = double_atoi(num);
	return (1);
}

int check_camera(char **data, t_minirt *minirt)
{
	t_camera	*cam;
	char		**input;
	int			status;

	cam = malloc(sizeof(t_camera));
	if (!get_coordinates(ft_split(data[1], ','), &cam->pos)
		|| !get_coordinates(ft_split(data[2], ','), &cam->rot)
		|| !get_double(data[3], &cam->fov))
	{
		free(cam);
		return (0);
	}
	cam->aspect_ratio = (double) WIN_WIDTH / (double) WIN_HEIGHT;
	calculate_ray(cam);
	minirt->cam = cam;
	return (1);
}

int	check_line(char *line, t_minirt *minirt)
{
	char **data;
	int	error_status;

	data = ft_split_white(line);
	if (same_str(data[0], "C"))
		error_status = check_camera(data, minirt);
	free_2d(data);
	return (error_status);
}
