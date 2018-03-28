/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:19:12 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/29 11:23:04 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light_model.h"

inline t_vec3	phong_light(t_vec3 *ray_dir, t_vec3 *to_light_dir,
							t_vec3 *nphit, t_vec3 *light_intensity)
{
	t_vec3	ref;
	float	cos;
	float	phong;

	ref = reflect_vec3(to_light_dir, nphit);
	cos = -dot_vec3(ref, *ray_dir);
	if (cos > 0)
	{
		phong = powf(cos, PHONG_COEF);
		return (new_vec3(light_intensity->x * phong, light_intensity->y * phong,
						light_intensity->z * phong));
	}
	return (new_vec3(0, 0, 0));
}
