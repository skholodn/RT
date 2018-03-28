/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:48:05 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/26 13:40:01 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destination, const char *source)
{
	char *ptr_dest;

	ptr_dest = destination;
	while (*destination)
		destination++;
	while (*source)
		*(destination++) = *(source++);
	*destination = 0;
	return (ptr_dest);
}
