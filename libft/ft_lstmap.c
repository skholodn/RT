/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetrenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:52:22 by spetrenk          #+#    #+#             */
/*   Updated: 2016/11/29 16:59:29 by spetrenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret_lst;
	t_list *cur_el_ret_lst;

	ret_lst = 0;
	if (f && lst)
	{
		ret_lst = f(lst);
		cur_el_ret_lst = ret_lst;
		lst = lst->next;
		while (lst)
		{
			cur_el_ret_lst->next = f(lst);
			cur_el_ret_lst = cur_el_ret_lst->next;
			lst = lst->next;
		}
	}
	return (ret_lst);
}
