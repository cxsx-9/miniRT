/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:07:28 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/23 18:50:48 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vect
{
	double	x;
	double	y;
	double	z;
}	t_vect;

t_vect	vect(double x, double y, double z);
t_vect	*new_vect(double x, double y, double z);

t_vect	add_vect(t_vect v, t_vect u);
t_vect	sub_vect(t_vect v, t_vect u);
t_vect	multi_vect(t_vect v, double c);
t_vect	divide_vect(t_vect v, double c);
double	dot_product(t_vect v, t_vect u);
t_vect	cross_product(t_vect v, t_vect u);

double	dist_vect(t_vect v);

t_vect	normalize(t_vect v);

void	print_vect(t_vect v);

#endif