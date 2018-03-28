/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:20:08 by spetrenk          #+#    #+#             */
/*   Updated: 2017/07/20 17:20:19 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

inline static void	set_true(char *status)
{
	while (*status)
	{
		*status = 2;
		status++;
	}
}

inline static char	is_complete(char *status)
{
	while (*status)
	{
		if (*status == 2)
			return (0);
		status++;
	}
	return (1);
}

void				start_render(t_control *control)
{
	if (control->redraw)
	{
		set_true(control->threads_status);
		while (!is_complete(control->threads_status))
		{
		}
		window_update(control->scene->window);
		control->redraw = 0;
	}
}
