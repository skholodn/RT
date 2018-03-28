/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 09:17:59 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/29 13:08:42 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned nmb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nmb = n * -1;
	}
	else
		nmb = n;
	if (nmb < 10)
		ft_putchar_fd(nmb + '0', fd);
	else
	{
		ft_putnbr_fd(nmb / 10, fd);
		ft_putnbr_fd(nmb % 10, fd);
	}
}
