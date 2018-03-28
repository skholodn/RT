/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 13:13:16 by spetrenk          #+#    #+#             */
/*   Updated: 2017/07/21 11:54:08 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_H
# define CONTROL_H

# include "scene.h"
# include <SDL.h>
# include "pthread.h"
# include "uf_math.h"

typedef struct	s_thread
{
	t_scene		*scene;
	pthread_t	thread;
	int			y;
	int			fin_y;
	char		*run;
	char		*calculate;
}				t_thread;

t_thread		*get_threads(int count, t_scene *scene,
				char **thread_status, char *run_status);

typedef struct	s_control
{
	t_scene		*scene;
	size_t		cur_obj;
	t_vec3		*pos_cur_obj;
	char		is_camera;
	char		is_look_point_move;
	char		quit;
	char		run;
	char		*threads_status;
	char		redraw;
	t_thread	*threads;
}				t_control;

void			main_loop(t_control *control);
void			new_control(t_scene *scene, size_t threads_count);
void			next_obj(t_control *control);
void			start_render(t_control *control);
char			move(t_control *control, SDL_Scancode *key);
int				key_press(SDL_Scancode *key, t_control *control);
int				key_release(SDL_Scancode *key, t_control *control);
int				mouse_press(Uint8 key, float x, float y, t_control *control);
int				mouse_release(Uint8 key, t_control *control);
int				mouse_move(int x, int y, t_control *control);

#endif
