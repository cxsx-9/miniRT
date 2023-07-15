/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:32:18 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/15 12:05:19 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"
# include "get_next_line.h"

char	**ft_split_white(char *s);
void	free_2d(char **data);
double	ft_atof(char *str);

int		good_integer(char *num, int print);
int		good_positive_int(char *num);
int		good_double(char *num, int print);
int		good_positive_double(char *num, int max);
int		good_size(char *num, char *type);
int		good_unit(char **unit_vect);
int		good_color(char **input);
int		good_coordinate(char **input, int unit_vect);

typedef struct s_obj_count
{
	int	camera;
	int	ambient;
	int	light;
	int	sphere;
	int	plane;
	int	cylinder;
}		t_obj_count;

int		check_camera(char **data, t_obj_count *counter);
int		check_ambient(char **data, t_obj_count *counter);
int		check_light(char **data, t_obj_count *counter);
int		check_sphere(char **data, t_obj_count *counter);
int		check_plane(char **data, t_obj_count *counter);
int		check_cylinder(char **data, t_obj_count *counter);

void	init_object_count(t_obj_count *counter);
t_obj	*lst_objs_last(t_obj *objs);
void	lst_objs_addback(t_obj **objs, t_obj *new_obj);
t_light	*lst_lights_last(t_light *light);
void	lst_lights_addback(t_light **lights, t_light *new_light);

int		check_line(char *line, t_obj_count *counter);
int		check_all(char *name);

int		get_coordinate(char **input, t_vect *pos);
int		get_color_input(char **input, t_vect *color);
int		get_integer(char *num, int *des);
int		get_double(char *num, double *des);

void	get_object(char **data, t_minirt *minirt);
void	get_all(char *name, t_minirt *minirt);

void	get_camera(char **data, t_minirt *minirt);
void	get_ambient(char **data, t_minirt *minirt);
void	get_light(char **data, t_minirt *minirt);

void	get_sphere(char **data, t_minirt *minirt);
void	get_plane(char **data, t_minirt *minirt);
void	get_cylinder(char **data, t_minirt *minirt);

int		error_unknow_var(char *str);
void	error_line(char *name, int line);
int		error_object_number(char *name, t_obj_count *counter);

int		error_args_count(char **data, int expect_num);

int		is_inside(char c, char *set);
int		args_count(char **str);
int		same_str(char *a, char *b);
// Debug dunction
void	show_2d(char **input);

#endif