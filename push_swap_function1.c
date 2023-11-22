/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:31:09 by smarty            #+#    #+#             */
/*   Updated: 2023/11/22 20:38:50 by smarty           ###   ########.fr       */
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
