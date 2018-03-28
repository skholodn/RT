/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:13:58 by spetrenk          #+#    #+#             */
/*   Updated: 2017/05/29 11:14:01 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

int			mouse_release(Uint8 key, t_control *control)
{
	if (key == SDL_BUTTON_LEFT)
	{
		control->is_look_point_move = 0;
		control->pos_cur_obj = &control->scene->camera->pos;
	}
	return (0);
}
