/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:58:10 by spetrenk          #+#    #+#             */
/*   Updated: 2017/07/20 19:54:18 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	set_pixel(t_window *window, int x, int y, t_vec3 color)
{
	unsigned char	*data;
	int				pos;

	data = window->data;
	pos = y * window->width + x;
	data[pos * 4] = (unsigned char)MIN(color.x * 255.f, 255.f);
	data[pos * 4 + 1] = (unsigned char)MIN(color.y * 255.f, 255.f);
	data[pos * 4 + 2] = (unsigned char)MIN(color.z * 255.f, 255.f);
}
