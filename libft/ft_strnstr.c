/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 09:42:46 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/29 13:09:43 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char *ret_big;

	ret_big = ft_strstr(big, little);
	if ((ret_big - big) + ft_strlen(little) > len)
		return (0);
	return (ret_big);
}
