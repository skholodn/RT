/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 19:07:18 by dpylypen          #+#    #+#             */
/*   Updated: 2017/07/20 19:37:53 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

inline static char	*get_status(size_t count)
{
	char	*thread_status;

	thread_status = (char *)malloc(count + 1);
	thread_status[count] = 0;
	while (count)
	{
		thread_status[count - 1] = 1;
		count--;
	}
	return (thread_status);
}

void				*thread_worker(void *data)
{
	t_thread	*thread;

	thread = data;
	thread->y -= 1;
	while (*(thread->run))
	{
		if (*(thread->calculate) == 2)
		{
			update_scene(thread->scene, thread->y, thread->fin_y);
			*(thread->calculate) = 1;
		}
	}
	return (0);
}

void				abc(size_t *height, t_scene *scene, int *count)
{
	*height = scene->window->height;
	if (*count > scene->window->height)
		*count = scene->window->height;
}

t_thread			*get_threads(int count, t_scene *scene,
	char **thread_status, char *run_status)
{
	t_thread	*ret_threads;
	size_t		height;
	size_t		task;
	size_t		i;

	abc(&height, scene, &count);
	ret_threads = (t_thread*)malloc(sizeof(t_thread) * count);
	*thread_status = get_status(count);
	*run_status = 1;
	i = 0;
	while (height)
	{
		task = top_round((float)height / count);
		height -= task;
		ret_threads[count - 1].y = i;
		ret_threads[count - 1].fin_y = i + task;
		ret_threads[count - 1].scene = scene;
		ret_threads[count - 1].run = run_status;
		ret_threads[count - 1].calculate = &((*thread_status)[count - 1]);
		pthread_create(&ret_threads[count - 1].thread, 0,
			thread_worker, &ret_threads[count - 1]);
		count--;
		i += task;
	}
	return (ret_threads);
}
