/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 19:55:54 by dpylypen          #+#    #+#             */
/*   Updated: 2017/07/20 19:56:12 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "control.h"
#include "parse_yml.h"

int		main(int ac, char **av)
{
	char	*file;
	int		fd;
	size_t	count;

	if (ac != 2)
		print_error("Usage: ./RT <file_path.yml>");
	fd = open(av[1], O_RDONLY);
	if (fd == -1 || fd == 0)
		print_error("Reading error: no such yml file");
	count = count_words(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	file = (char *)ft_memalloc(count + 1);
	read(fd, file, count);
	close(fd);
	parse_yml(file, count);
	return (0);
}
