/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 19:51:33 by dpylypen          #+#    #+#             */
/*   Updated: 2017/07/20 19:53:13 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

inline void	window_update(t_window *window)
{
	SDL_UpdateTexture(window->texture, NULL, &window->data[0],
window->width * 4);
	SDL_RenderCopy(window->renderer, window->texture, NULL, NULL);
	SDL_RenderPresent(window->renderer);
}
