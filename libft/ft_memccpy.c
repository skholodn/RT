/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:09:33 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/25 17:10:45 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int ch, size_t count)
{
	size_t i;

	i = 0;
	while (i < count)
	{
		((char *)dest)[i] = ((char*)source)[i];
		if (((char *)(dest))[i] == (char)ch)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
