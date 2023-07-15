/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:05:50 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/15 12:18:38 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "vector.h"

t_vect	color(int r, int g, int b);
int		get_color(t_vect color);
t_vect	mix_color(t_vect color1, t_vect color2, double ratio, double mode);

#endif