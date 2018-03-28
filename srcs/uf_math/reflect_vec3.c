/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect_vec3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:55:20 by spetrenk          #+#    #+#             */
/*   Updated: 2017/07/20 19:46:53 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uf_math.h"

inline t_vec3	reflect_vec3(t_vec3 *dir, t_vec3 *normal)
{
	float dir_norm;

	dir_norm = dot_vec3(*dir, *normal);
	return (add_vec3(*dir, mul_vec3_numb(*normal, -2 * dir_norm)));
}
