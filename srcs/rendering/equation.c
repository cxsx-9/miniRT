/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:26:26 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/15 14:34:40 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

t_vect	reflect(t_vect incident, t_vect norm)
{
	t_vect	multi;

	multi = multi_vect(norm, 2.0 * dot_product(incident, norm));
	return (sub_vect(incident, multi));
}

t_vect	new_ray_origin(t_payload *load)
{
	t_vect	new_norm;

	new_norm = multi_vect(load->world_norm, 0.0001);
	return (add_vect(load->world_pos, new_norm));
}
