/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:43:53 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/26 10:03:11 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int ch, size_t num)
{
	unsigned char	*byte_mem;
	size_t			i;

	byte_mem = (unsigned char *)memptr;
	i = -1;
	while (++i < num)
		byte_mem[i] = (char)ch;
	return (byte_mem);
}
