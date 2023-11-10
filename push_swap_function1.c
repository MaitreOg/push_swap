/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:31:09 by smarty            #+#    #+#             */
/*   Updated: 2023/11/10 01:54:39 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rotate(t_list *lst)
{
	if (lst->next)
	{
		lst = lst_addback(lst, lst->data);
		lst = lst->next;
	}
	return (lst);
}

t_list	*rrotate(t_list *lst)
{
	t_list	*tmp;

	if(lst->next)
	{
		lst = lst_addfront(lst,ft_lstlast(lst)->data);
		tmp = lst;
		while(tmp->next->next)
			tmp = tmp->next;
		tmp->next = NULL;
	}
	return(lst);
}

void	ra(t_list **lst)
{
	*lst = rotate(*lst);
	printf("ra\n");
	return;
}

void	rb(t_list **lst)
{
	*lst = rotate(*lst);
	printf("rb\n");
	return;
}

void	rr(t_list **lst1, t_list **lst2)
{
	*lst1 = rotate(*lst1);
	*lst2 = rotate(*lst2);
	printf("rr\n");
	return;
}

void	rra(t_list **lst)
{
	*lst = rrotate(*lst);
	printf("rra\n");
	return;
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
	return;
}

void	pb(t_list **lst1, t_list **lst2)
{
	*lst2 = lst_addfront(*lst2, (*lst1)->data);
	*lst1 = (*lst1)->next;
	printf("pb\n");
	return;
}

void	pa(t_list **lst1, t_list **lst2)
{
	*lst1 = lst_addfront(*lst1, (*lst2)->data);
	printf("pa\n");
	return;
}

