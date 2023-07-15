/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:48:34 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/15 18:07:51 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "minirt.h"

typedef struct s_payload
{
	t_obj	*obj;
	double	hit_distance;
	t_vect	world_pos;
	t_vect	world_norm;
}	t_payload;

typedef struct s_pixel
{
	t_vect	c;
	int		i;
	double	multiplier;
}	t_pixel;

void		draw(t_minirt *minirt);

t_payload	miss(t_ray ray);
t_payload	get_closest_hit(t_ray ray, double hit_d, t_obj *obj);
void		closest_hit_pl(t_ray ray, double hit_d, t_plane *p, t_payload *l);
void		closest_hit_sp(t_ray ray, double hit_d, t_sphere *s, t_payload *l);

double		get_closestt(t_obj *obj, t_ray ray, double *closestT);
int			hit_sphere(t_sphere *sphere, t_ray ray, double *closestT);
int			hit_plane(t_plane *p, t_ray ray, double *closestT);

t_vect		reflect(t_vect incident, t_vect norm);
t_vect		new_ray_origin(t_payload *load);

t_vect		sky_color(t_vect c, t_scene *scene);
t_vect		ambient_light(t_pixel *p, t_scene *s, t_payload *load);
t_vect		point_light(t_pixel *p, t_scene *s, t_payload *load, t_ray *ray);

t_vect		get_object_color(t_obj *obj);
int			obj_block(t_ray ray, t_scene *scene, t_light *light);

#endif