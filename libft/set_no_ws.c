/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_no_ws.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:57:27 by spetrenk          #+#    #+#             */
/*   Updated: 2017/07/20 17:57:29 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_no_ws(char **str)
{
	char *p_str;
	char *mover;
	char *tmp;

	p_str = ft_strtrim(*str);
	free(*str);
	*str = p_str;
	while (*p_str)
	{
		if (ft_isspace(*p_str++))
		{
			tmp = p_str;
			*(tmp - 1) = ' ';
			mover = p_str;
			while (*mover && ft_isspace(*mover))
				mover++;
			while (*mover)
			{
				*tmp = *mover++;
				tmp++;
			}
			*tmp = 0;
		}
	}
}
