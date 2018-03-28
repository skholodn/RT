/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:34:49 by spetrenk          #+#    #+#             */
/*   Updated: 2017/07/21 12:15:22 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <stdlib.h>
# include <SDL.h>
# include <math.h>
# include "uf_math.h"

typedef struct		s_window
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	unsigned char	*data;
	int				height;
	int				width;
	float			aspect;
	float			inv_height;
	float			inv_width;

}					t_window;

t_window			*new_window(int width, int height, char *name);
void				set_pixel(t_window *window, int x, int y, t_vec3 color);
void				window_update(t_window *window);

#endif
