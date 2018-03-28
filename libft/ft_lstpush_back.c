/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:44:36 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/30 16:18:09 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_back(t_list **start, t_list *new_node)
{
	t_list *node_start;

	if (start)
	{
		if (*start)
		{
			node_start = *start;
			while (node_start->next)
				node_start = node_start->next;
			node_start->next = new_node;
		}
		else
			*start = new_node;
	}
}
