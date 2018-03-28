/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:10:44 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/29 11:10:45 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

int		key_release(SDL_Scancode *key, t_control *control)
{
	if (*key == SDL_SCANCODE_C)
	{
		control->is_camera = 0;
		control->pos_cur_obj = &control->scene->
				objects[control->cur_obj]->center;
	}
	if (*key == SDL_SCANCODE_KP_PLUS)
		next_obj(control);
	return (0);
}
