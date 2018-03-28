/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:09:45 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/29 11:09:51 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

int			key_press(SDL_Scancode *key, t_control *control)
{
	if (*key == SDL_SCANCODE_ESCAPE)
		control->quit = 1;
	if (*key == SDL_SCANCODE_C)
	{
		control->is_camera = 1;
		if (control->is_look_point_move)
			return (0);
		control->pos_cur_obj = &control->scene->camera->pos;
	}
	if (move(control, key))
	{
		if (control->is_camera == 1)
			camera_update(control->scene->camera);
		control->redraw = 1;
	}
	return (0);
}
