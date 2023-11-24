/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_fonction2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:01:40 by smarty            #+#    #+#             */
/*   Updated: 2023/11/24 19:21:33 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*s(t_list *lst)
{
	int	swap_data;

	swap_data = lst->data;
	lst->data = lst->next->data;
	lst->next->data = swap_data;
	return (lst);
}

int	sa(t_list **lst)
{
	if (!(*lst) || !(*lst)->next)
		return (-1);
	*lst = s(*lst);
	printf("sa\n");
	return (0);
}

int	sb(t_list **lst)
{
	if (!(*lst) || !(*lst)->next)
		return (-1);
	*lst = s(*lst);
	printf("sb\n");
	return (0);
}

int	ss(t_list **lst1, t_list **lst2)
{
	if (!(*lst1) || !(*lst1)->next || !(*lst2) || !(*lst2)->next)
		return (-1);
	*lst1 = s(*lst1);
	*lst2 = s(*lst2);
	printf("ss\n");
	return (0);
}

int	pa(t_list **lst1, t_list **lst2)
{
	t_list	*tmp;

	if (!(*lst2))
		return (-1);
	*lst1 = lst_addfront(*lst1, (*lst2)->data);
	tmp = (*lst2)->next;
	free(*lst2);
	*lst2 = tmp;
	printf("pa\n");
	return (0);
}