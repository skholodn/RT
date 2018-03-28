/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pporechn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:43:17 by pporechn          #+#    #+#             */
/*   Updated: 2017/07/10 11:37:24 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*add_file(t_list **list, const int fd)
{
	(*list) = (t_list *)malloc(sizeof(t_list));
	(*list)->content = ft_strnew(BUFF_SIZE + 1);
	(*list)->content_size = (size_t)fd;
	(*list)->next = 0;
	return ((*list)->content);
}

static char	*get_file_buff(const int fd)
{
	static t_list	*files = 0;
	t_list			*start;

	if (!files)
		return (add_file(&files, fd));
	start = files;
	while (1)
	{
		if (start->content_size == (size_t)fd)
			return (start->content);
		if (!start->next)
			break ;
		start = start->next;
	}
	return (add_file(&(start->next), fd));
}

static void	move_str(char *start, char *end)
{
	while (*end)
	{
		*start = *end;
		start++;
		end++;
	}
	*start = 0;
}

static char	add_from_content(char *content, char **line)
{
	char	*end_str;
	char	*start;

	if (*content)
	{
		start = *line;
		end_str = ft_strchr(content, '\n');
		if (end_str)
		{
			*end_str = 0;
			*line = ft_strjoin(*line, content);
			*end_str = '\n';
			move_str(content, end_str + 1);
			free(start);
			return (1);
		}
		else
		{
			*line = ft_strjoin(*line, content);
			content[0] = 0;
		}
		free(start);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char	*content;
	ssize_t	count;

	content = get_file_buff(fd);
	if (read(fd, content, 0) == -1 || !line)
		return (-1);
	*line = ft_strnew(0);
	while (!add_from_content(content, line))
	{
		if (!content[0])
		{
			if ((count = read(fd, content, BUFF_SIZE)) == 0)
			{
				if (**line)
					break ;
				else
					return (0);
			}
			content[count] = 0;
		}
	}
	return (1);
}
