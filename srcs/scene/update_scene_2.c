/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_scene_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 20:22:02 by dpylypen          #+#    #+#             */
/*   Updated: 2017/07/21 11:22:38 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static t_vec3	get_cam_dir(t_scene *scene, t_update *up, float xy)
{
	t_vec3	ret;
	float	x;
	float	y;

	x = (float)up->x;
	y = (float)xy;
	x = (2 * ((x + up->col / scene->alising) *
		scene->window->inv_width) - 1) * scene->camera->angle
	* scene->window->aspect;
	y = (1 - 2 * ((y + up->row / scene->alising) *
	scene->window->inv_height)) * scene->camera->angle;
	ret = add_vec3(scene->camera->forward,
		add_vec3(mul_vec3_numb(scene->camera->side, x),
			mul_vec3_numb(scene->camera->up, y)));
	normalize_vec3(&ret);
	return (ret);
}

t_vec3			get_mid(t_vec3 *colors, int aliasing)
{
	t_vec3	mid_col;
	int		i;

	i = 0;
	mid_col = new_vec3(0, 0, 0);
	while (i < (aliasing * aliasing))
	{
		mid_col.x += colors[i].x;
		mid_col.y += colors[i].y;
		mid_col.z += colors[i].z;
		i++;
	}
	mid_col.x /= aliasing * aliasing;
	mid_col.y /= aliasing * aliasing;
	mid_col.z /= aliasing * aliasing;
	return (mid_col);
}

void			update_scene(t_scene *scene, int y, int finline)
{
	t_update	up;
	t_vec3		color[scene->alising * scene->alising];

	up.ray.origin = scene->camera->pos;
	while (++y < finline)
	{
		up.x = -1;
		while (++up.x < scene->window->width)
		{
			up.row = -1;
			up.i = 0;
			while (++up.row < scene->alising)
			{
				up.col = -1;
				while (++up.col < scene->alising)
				{
					up.ray.t = RAY_LEN;
					up.ray.dir = get_cam_dir(scene, &up, y);
					up.ray.power = 0.9;
					color[up.i++] = get_color(&up.ray, scene);
				}
			}
			set_pixel(scene->window, up.x, y, get_mid(color, scene->alising));
		}
	}
}
