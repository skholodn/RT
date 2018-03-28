/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:11:38 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/27 13:11:41 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "uf_math.h"

typedef struct	s_camera
{
	t_vec3		pos;
	t_vec3		forward;
	t_vec3		look_point;
	t_vec3		look_up;
	t_vec3		side;
	t_vec3		up;
	float		angle;
}				t_camera;

t_camera		*new_camera(t_vec3 pos, t_vec3 forward, t_vec3 up, float fov);
void			camera_update(t_camera *camera);
void			calculate_cam(t_camera *c, t_vec3 *forward, t_vec3 *up);

#endif
