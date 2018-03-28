/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:05:44 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/29 16:25:21 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memclr(void *memptr, size_t memlen)
{
	size_t i;

	if (memptr)
	{
		i = -1;
		while (++i < memlen)
			((char *)memptr)[i] = 0;
	}
	free(memptr);
}
