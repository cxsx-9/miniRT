/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 00:57:26 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/28 15:44:15 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H
# include <math.h>

double	to_radian(double degree);
void	print_vect(t_vect v);
void	free_cam(t_camera *camera);
void	free_scene(t_scene *scene);

#endif