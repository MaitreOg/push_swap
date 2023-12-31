/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:31:09 by smarty            #+#    #+#             */
/*   Updated: 2023/11/23 14:55:24 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rotate(t_list *lst)
{
	t_list	*tmp;

	if (lst->next)
	{
		lst = lst_addback(lst, lst->data, lst->rank);
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (lst);
}

void	ra(t_list **lst)
{
	*lst = rotate(*lst);
	printf("ra\n");
	return ;
}

void	rb(t_list **lst)
{
	*lst = rotate(*lst);
	printf("rb\n");
	return ;
}

void	rr(t_list **lst1, t_list **lst2)
{
	*lst1 = rotate(*lst1);
	*lst2 = rotate(*lst2);
	printf("rr\n");
	return ;
}
