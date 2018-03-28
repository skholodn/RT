/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambert_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:19:04 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/29 11:20:24 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light_model.h"

inline t_vec3	lambert_light(t_vec3 *ray_dir, t_vec3 *nphit, t_vec3 power)
{
	float cos;

	cos = -dot_vec3(*ray_dir, *nphit);
	if (cos > 0)
		return (new_vec3(power.x * cos, power.y * cos, power.z * cos));
	return (new_vec3(0, 0, 0));
}
