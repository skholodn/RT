/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:08:10 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/28 10:20:21 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t count)
{
	size_t i;

	i = 0;
	if (destination > source)
	{
		while (source - 1 != source + count - 1 - i)
		{
			*(unsigned char *)(destination + count - 1 - i) =
				*(unsigned char *)(source + count - 1 - i);
			i++;
		}
	}
	else
		ft_memcpy(destination, source, count);
	return (destination);
}
