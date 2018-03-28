/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:30:16 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/24 13:38:32 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*mem;

	mem = (char *)malloc(size);
	if (mem)
	{
		i = 0;
		while (i < size)
			mem[i++] = 0;
	}
	return (mem);
}
