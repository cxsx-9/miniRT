/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:42:53 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/29 00:15:01 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#define DBL_MAX 1.7976931348623158e+308

int	per_pixel(t_minirt *minirt, double x, double y)
{
	t_ray		ray;
	t_obj		*objs = minirt->objs;
	t_camera	*camera = minirt->cam;

	x = x * 2 - 1;
	y = y * 2 - 1;

	// setting primary ray
	ray.orig = vect(x, y, camera->pos.z);
	ray.dir = vect(x, y, 1);

	// check hit sphere
	t_sphere *sphere = (t_sphere*) objs->content;
	// (bx^2 + by^2)t^2 + (2(axbx + ayby))t + (ax^2 + ay^2 -r^2) = 0
	// this formula use with sphere center is (0, 0, 0)
	// a -> ray origin
	// b -> ray direction
	// r -> radius
	// t -> hit distance

	// quadratic formula form (ax^2 + bx + c = 0) 
	double a = dot_product(ray.dir, ray.dir);
	double b = 2 * dot_product(ray.orig, ray.dir);
	double c = dot_product(ray.orig, ray.orig) - sphere->r * sphere->r;

	// check discriminant
	double discriminant = b * b - 4.0 * a * c;

	if (discriminant < 0)
		return (get_color(color(0, 0, 0)));
	return (get_color(sphere->color));
}

// int	ray_trace(t_minirt *minirt, t_ray ray)
// {
// 	// t_sphere *sphere = (t_sphere*) minirt->objs->content;

// 	t_sphere *sphere1 = malloc(sizeof(t_sphere));
// 	sphere1->center = vect(-10, 0, 20);
// 	sphere1->d = 5;
// 	sphere1->r = sphere1->d / 2;
// 	sphere1->color = color(136, 8, 8);
	
// 	t_sphere *sphere2 = malloc(sizeof(t_sphere));
// 	sphere2->center = vect(-5, 0, 10);
// 	sphere2->d = 5;
// 	sphere2->r = sphere2->d / 2;
// 	sphere2->color = color(20, 8, 138);

// 	t_sphere* spheres[2];
// 	spheres[0] = sphere1;
// 	spheres[1] = sphere2;

// 	for (int i = 0; i < 2; i++)
// 	{
// 		t_sphere* sphere = spheres[i];
// 		// ray.orig = sub_vect(ray.orig, sphere->center);
// 		t_vect origin = sub_vect(ray.orig, sphere->center);

// 		double a = dot_product(ray.dir, ray.dir);
// 		double b = 2 * dot_product(origin, ray.dir);
// 		double c = dot_product(origin, origin) - sphere->r * sphere->r;

// 		// check discriminant
// 		double discriminant = b * b - 4.0 * a * c;
// 		if (discriminant < 0)
// 			continue;

// 		// (-b +- sqrt(discriminant)) / (2.0 * a)
// 		double t0 = (-b + sqrt(discriminant)) / (2.0 * a);
// 		double closestT = (-b - sqrt(discriminant)) / (2.0 * a);

// 		t_vect hit_point = add_vect(origin, multi_vect(ray.dir, closestT));

// 		t_vect normal = normalize(hit_point);

// 		t_vect light_dir = normalize(vect(1, 1, 1));

// 		double d = MAX(dot_product(normal, multi_vect(light_dir, -1)), 0.0); // = cos(angle)
// 		t_color color;
// 		color.r = sphere->color.r * d;
// 		color.g = sphere->color.g * d;
// 		color.b = sphere->color.b * d;
// 		return (get_color(color));
// 	}
// 	return (get_color(color(135, 206, 235)));
// }

// void    set_object(t_minirt *minirt)
// {
//     t_obj        *objs;
//     t_obj        *tmp_obj;
//     t_sphere    *sphere;

//     objs = malloc(sizeof(t_obj));

//     // first sphere
//     sphere = malloc(sizeof(t_sphere));
//     sphere->center = vect(-2, 0, 10);
//     sphere->d = 5;
//     sphere->r = sphere->d / 2;
//     sphere->color = color(136, 8, 8);
    
//     objs->id = SPHERE;
//     objs->content = (void*) sphere;
//     objs->next = NULL;

//     tmp_obj = malloc(sizeof(t_obj));

//     // second sphere
//     sphere = malloc(sizeof(t_sphere));
//     sphere->center = vect(10, 0, 30);
//     sphere->d = 5;
//     sphere->r = sphere->d / 2;
//     sphere->color = color(20, 8, 138);

//     tmp_obj->id = SPHERE;
//     tmp_obj->content = (void*) sphere;
//     tmp_obj->next = NULL;

//     objs->next = tmp_obj;
    
//     minirt->objs = objs;
// }


int    ray_trace(t_minirt *minirt, t_ray ray)
{
    t_obj *objs = minirt->objs;
    t_sphere *closest_sphere = NULL;
    double hit_distance = DBL_MAX;

    while (objs != NULL)
    {
        t_sphere* sphere = (t_sphere*) objs->content;
        t_vect origin = sub_vect(ray.orig, sphere->center);

        double a = dot_product(ray.dir, ray.dir);
        double b = 2 * dot_product(origin, ray.dir);
        double c = dot_product(origin, origin) - sphere->r * sphere->r;

        double discriminant = b * b - 4.0 * a * c;
        if (discriminant < 0){
            objs = objs->next;
            continue;
        }
        double t0 = (-b + sqrt(discriminant)) / (2.0 * a);
        double closestT = (-b - sqrt(discriminant)) / (2.0 * a);
        if (closestT < hit_distance)
        {
            hit_distance = closestT;
            closest_sphere = sphere;
            objs = objs->next;
            continue;
        }
        objs = objs->next;
    }

    if (closest_sphere == NULL)
        return (get_color(color(135, 206, 235)));
    
    t_vect origin = sub_vect(ray.orig, closest_sphere->center);
    t_vect hit_point = add_vect(origin, multi_vect(ray.dir, hit_distance));
    t_vect normal = normalize(hit_point);
    t_vect light_dir = normalize(vect(1, 1, 1));

    double d = MAX(dot_product(normal, multi_vect(light_dir, -1)), 0.0); // = cos(angle)
    t_color color;
    color.r = closest_sphere->color.r * d;
    color.g = closest_sphere->color.g * d;
    color.b = closest_sphere->color.b * d;
    return (get_color(color));
}

void draw(t_minirt *minirt)
{
	int			x;
	int			y;
	t_ray		ray;

	t_sphere *sphere = (t_sphere*)minirt->objs->content;
	x = -1;
	while (x++ < WIN_WIDTH - 1)
	{
		y = -1;
		while (y++ < WIN_HEIGHT - 1)
		{
			img_pix_put(&minirt->img, x, y, ray_trace(minirt, minirt->cam->ray[x + y * WIN_WIDTH]));
		}
	}
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img.img, 0, 0);
}

void	set_camera(t_minirt *minirt)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	cam->pos = vect(0, 1, 0);
	cam->rot = vect(0, 0, 0);
	cam->fov = 70;
	cam->aspect_ratio = (double) WIN_WIDTH / (double) WIN_HEIGHT;
	calculate_ray(cam);
	minirt->cam = cam;
}

int main(int ac, char **av)
{
	t_minirt *minirt;
	
	if (ac != 2)
		return (0);
	minirt = init_minirt();
	if (!check_all(av[1]))
	{
		ft_putstr_fd(": Fail\n", 2);
		close_event();
	}
	printf("Running Program\n"); // dbug
	get_all(av[1], minirt);
	draw(minirt);
	mlx_mouse_hook(minirt->win, &mouse_event, NULL);
	mlx_key_hook(minirt->win, &key_event, NULL);
	mlx_hook(minirt->win, 17, 1L<<5, &close_event, NULL);
	mlx_loop(minirt->mlx);
}
