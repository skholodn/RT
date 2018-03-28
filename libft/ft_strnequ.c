/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 09:52:26 by spetrenk          #+#    #+#             */
/*   Updated: 2016/12/01 09:28:11 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 1;
	if (s1 && s2)
	{
		if (!*s2)
			return (1);
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
			if (i == n)
				return (1);
			i++;
		}
		if (*s1 - *s2 == 0)
			return (1);
	}
	return (0);
}
