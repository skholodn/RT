/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:28:34 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/28 09:36:18 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t len;

	if (!*little)
		return (char*)(big);
	len = ft_strlen(little);
	while (*big)
	{
		if (ft_strncmp(big++, little, len) == 0)
			return (char *)big - 1;
	}
	return (0);
}
