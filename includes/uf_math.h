/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uf_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:30:12 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/27 13:30:22 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UF_MATH_H
# define UF_MATH_H
# define MIN(a,b) (((a) < (b)) ? (a) : (b))
# define ABS(a) (((a) < (0)) ? (-a) : (a))
# define ACCURACY 0.099999f

# include <math.h>
# include "stdlib.h"

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

t_vec3			new_vec3(float x, float y, float z);
t_vec3			mul_vec3_numb(t_vec3 v1, float numb);
t_vec3			mul_vec3(t_vec3 v1, t_vec3 v2);
t_vec3			reflect_vec3(t_vec3 *dir, t_vec3 *normal);
t_vec3			refract_vec3(t_vec3 dir, t_vec3 normal, float refract_coef);
t_vec3			add_vec3(t_vec3 v1, t_vec3 v2);
t_vec3			sub_vec3(t_vec3 v1, t_vec3 v2);
t_vec3			get_direction(t_vec3 start, t_vec3 dest);
void			normalize_vec3(t_vec3 *v);
float			dot_vec3(t_vec3 v1, t_vec3 v2);
void			mul_in_vec(t_vec3 *v1, t_vec3 *v2);
void			add_in_vec(t_vec3 *v1, t_vec3 v2);
float			lenght_vec3(t_vec3 *start, t_vec3 *dest);
int				top_round(float i);

#endif
