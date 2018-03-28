/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 17:24:06 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/27 17:24:08 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void			calculate_cam(t_camera *c, t_vec3 *forward, t_vec3 *up)
{
	c->forward = new_vec3(-(c->pos.x - forward->x),
						-(c->pos.y - forward->y),
						-(c->pos.z - forward->z));
	normalize_vec3(&c->forward);
	c->side = mul_vec3(c->forward, *up);
	normalize_vec3(&c->side);
	c->up = mul_vec3(c->side, c->forward);
}

void			camera_update(t_camera *camera)
{
	calculate_cam(camera, &camera->look_point, &camera->look_up);
}

t_camera		*new_camera(t_vec3 pos, t_vec3 forward, t_vec3 up, float fov)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	camera->look_point = forward;
	camera->look_up = up;
	camera->pos = pos;
	calculate_cam(camera, &forward, &up);
	camera->angle = tanf((float)3.14f * 0.5f * fov / 180.f);
	return (camera);
}
