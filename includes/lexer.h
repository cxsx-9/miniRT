/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:32:18 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/29 01:16:30 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "miniRT.h"

char	**ft_split_white(char *s);
void	free_2d(char **data);
double	ft_atof(char *str);

t_obj	*lst_objs_last(t_obj *objs);
void	lst_objs_addback(t_obj **objs, t_obj *new);

int		good_coordinate(char **input, int unit_vect);
int		good_integer(char *num, int print);
int		good_double(char *num, int print);
int     good_color(char **input);

int		check_line(char *line);
int		check_all(char *name);

int     get_coordinate(char **input, t_vect *pos);
int 	get_color_input(char **input, t_color *color);
int 	get_integer(char *num, int *des);
int     get_double(char *num, double *des);

void	get_all(char *name, t_minirt *minirt);
void	get_line(char *line, t_minirt *minirt);

void	get_camera(char **data, t_minirt *minirt);
void	get_sphere(char **data, t_minirt *minirt);

int	    is_inside(char c, char *set);
int	    args_count(char **str);
int		same_str(char *a, char *b);

#endif