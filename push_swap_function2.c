/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:46:06 by smarty            #+#    #+#             */
/*   Updated: 2023/11/23 14:55:38 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*s(t_list *lst)
{
	int	swap_data;
	int	swap_rank;

	swap_data = lst->data;
	swap_rank = lst->rank;
	lst->data = lst->next->data;
	lst->rank = lst->next->rank;
	lst->next->data = swap_data;
	lst->next->rank = swap_rank;
	return (lst);
}

void	sa(t_list **lst)
{
	*lst = s(*lst);
	printf("sa\n");
	return ;
}

void	sb(t_list **lst)
{
	*lst = s(*lst);
	printf("sb\n");
	return ;
}

void	ss(t_list **lst1, t_list **lst2)
{
	*lst1 = s(*lst1);
	*lst2 = s(*lst2);
	printf("ss\n");
	return ;
}

void	pa(t_list **lst1, t_list **lst2)
{
	t_list	*tmp;

	*lst1 = lst_addfront(*lst1, (*lst2)->data, (*lst2)->rank);
	tmp = (*lst2)->next;
	free(*lst2);
	*lst2 = tmp;
	printf("pa\n");
	return ;
}
