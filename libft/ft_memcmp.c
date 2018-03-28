/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:55:29 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/28 17:32:33 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cptr_s1;
	unsigned char	*cptr_s2;

	i = -1;
	cptr_s1 = (unsigned char *)s1;
	cptr_s2 = (unsigned char *)s2;
	while (++i < n)
	{
		if (cptr_s1[i] != cptr_s2[i])
			return (cptr_s1[i] - cptr_s2[i]);
	}
	return (0);
}
