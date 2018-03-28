/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_vec3_numb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:54:38 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/29 11:54:39 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uf_math.h"

inline t_vec3			mul_vec3_numb(t_vec3 v1, float numb)
{
	return (new_vec3(v1.x * numb, v1.y * numb, v1.z * numb));
}
