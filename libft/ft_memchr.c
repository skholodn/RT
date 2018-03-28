/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:37:34 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/25 17:11:32 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memptr, int val, size_t num)
{
	size_t	i;

	i = -1;
	while (++i < num)
		if (((unsigned char*)memptr)[i] == (unsigned char)val)
			return (void *)((size_t)(memptr + i));
	return (0);
}
