/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:47:59 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/28 10:53:35 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *ptr_dst;

	ptr_dst = dst;
	while (len > 0 && *src != '\0')
	{
		*ptr_dst++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*ptr_dst++ = '\0';
		len--;
	}
	return (dst);
}
