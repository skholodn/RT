/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:58:01 by spetrenk          #+#    #+#             */
/*   Updated: 2017/07/20 19:51:08 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

t_window		*new_window(int width, int height, char *name)
{
	t_window	*window;

	if (width > 4000)
		width = 640;
	if (height > 2000)
		height = 480;
	window = (t_window *)malloc(sizeof(t_window));
	window->win = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED,
SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	window->renderer = SDL_CreateRenderer(window->win, -1,
SDL_RENDERER_ACCELERATED);
	window->texture = SDL_CreateTexture(window->renderer,
SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, width, height);
	window->data = (unsigned char *)malloc(width * height * 4);
	window->height = height;
	window->width = width;
	window->aspect = (float)width / height;
	window->inv_height = 1 / (float)height;
	window->inv_width = 1 / (float)width;
	return (window);
}
