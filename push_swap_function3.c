/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:48:10 by smarty            #+#    #+#             */
/*   Updated: 2023/11/23 14:55:50 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rrotate(t_list *lst)
{
	t_list	*tmp;

	if (lst->next)
	{
		lst = lst_addfront(lst, ft_lstlast(lst)->data, ft_lstlast(lst)->rank);
		tmp = lst;
		while (tmp->next->next)
			tmp = tmp->next;
		free (tmp->next);
		tmp->next = NULL;
	}
	return (lst);
}

void	rra(t_list **lst)
{
	*lst = rrotate(*lst);
	printf("rra\n");
	return ;
}

void	rrb(t_list **lst)
{
	*lst = rrotate(*lst);
	printf("rrb\n");
	return ;
}

void	rrr(t_list **lst1, t_list **lst2)
{
	*lst1 = rrotate(*lst1);
	*lst2 = rrotate(*lst2);
	printf("rrr\n");
	return ;
}

void	pb(t_list **lst1, t_list **lst2)
{
	t_list	*tmp;

	*lst2 = lst_addfront(*lst2, (*lst1)->data, (*lst1)->rank);
	tmp = (*lst1)->next;
	free(*lst1);
	*lst1 = tmp;
	printf("pb\n");
	return ;
}
