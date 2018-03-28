/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:28:30 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/28 11:04:06 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*skip_ws_symb(const char *str)
{
	char *new_str;

	new_str = (char *)((size_t)str);
	while (ft_isspace(*new_str))
		new_str++;
	return (new_str);
}

int			ft_atoi(const char *str)
{
	char	sign;
	int		result;
	char	*str_no_ws;

	sign = 1;
	result = 0;
	if (!*str)
		return (0);
	str_no_ws = skip_ws_symb(str);
	if (*str_no_ws == '+')
		str_no_ws++;
	else if (*str_no_ws == '-')
	{
		str_no_ws++;
		sign = -1;
	}
	while (*str_no_ws && ft_isdigit(*str_no_ws))
		result = result * 10 + (*(str_no_ws++)) - '0';
	return (sign * result);
}
