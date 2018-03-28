/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_vec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:51:59 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/29 11:52:02 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uf_math.h"

inline float	lenght_vec3(t_vec3 *start, t_vec3 *dest)
{
	t_vec3 vsub;

	vsub.x = start->x - dest->x;
	vsub.y = start->y - dest->y;
	vsub.z = start->z - dest->z;
	return (sqrtf(vsub.x * vsub.x + vsub.y * vsub.y + vsub.z * vsub.z));
}
