/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 19:56:55 by dpylypen          #+#    #+#             */
/*   Updated: 2017/07/20 19:57:26 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void	main_loop(t_control *control)
{
	SDL_Event	event;

	while (!control->quit)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
				control->quit = 1;
			if (event.type == SDL_KEYDOWN)
				key_press(&event.key.keysym.scancode, control);
			if (event.type == SDL_KEYUP)
				key_release(&event.key.keysym.scancode, control);
			if (event.type == SDL_MOUSEBUTTONDOWN)
				mouse_press(event.button.button, event.button.x,
event.button.x, control);
			if (event.type == SDL_MOUSEBUTTONUP)
				mouse_release(event.button.button, control);
			if (event.type == SDL_MOUSEMOTION)
				mouse_move(event.motion.x, event.motion.y, control);
			start_render(control);
		}
	}
}
