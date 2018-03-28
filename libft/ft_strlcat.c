/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:48:53 by spetrenk          #+#    #+#             */
/*   Updated: 2016/12/01 09:03:14 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_dst;
	size_t len_src;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (!size || len_dst >= size - 1)
		return (size + len_src);
	dst += len_dst;
	ft_strncat(dst, src, size - len_dst - 1);
	return (len_dst + len_src);
}
