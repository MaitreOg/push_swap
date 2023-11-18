/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:31:09 by smarty            #+#    #+#             */
/*   Updated: 2023/11/15 15:07:24 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rotate(t_list *lst)
{
	if (lst->next)
	{
		lst = lst_addback(lst, lst->data, lst->rank);
		lst = lst->next;
	}
	return (lst);
}

t_list	*rrotate(t_list *lst)
{
	t_list	*tmp;

	if(lst->next)
	{
		lst = lst_addfront(lst, ft_lstlast(lst)->data, ft_lstlast(lst)->rank);
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
	*lst2 = lst_addfront(*lst2, (*lst1)->data, (*lst1)->rank);
	*lst1 = (*lst1)->next;
	printf("pb\n");
	return;
}

void	pa(t_list **lst1, t_list **lst2)
{
	*lst1 = lst_addfront(*lst1, (*lst2)->data, (*lst2)->rank);
	*lst2 = (*lst2)->next;
	printf("pa\n");
	return;
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
/*t_list	*s(t_list *lst)
{
	t_list	*tmp;
	t_list	*node;
	t_list	*node2;

	tmp = lst;
	if (lst_len(lst) < 2)
		return (lst);
	node->data = tmp->data;
	node->rank = tmp->rank;
	//print_lst(lst);
	//printf("\n\n");
	tmp = tmp->next;
	print_lst(tmp);
	//node2->data = tmp->data;
	//node2->rank = tmp->rank;	
	node->next = tmp->next;
	tmp->next = node;
	//tmp = lst_addfront(tmp, node2->data, node2->rank);
	//print_lst(lst);
	return (lst);
}*/

void	sa(t_list **lst)
{
	*lst = s(*lst);
	printf("sa\n");
	return;
}

void	sb(t_list **lst)
{
	*lst = s(*lst);
	printf("sb\n");
	return;
}

void	ss(t_list **lst1, t_list **lst2)
{
	*lst1 = s(*lst1);
	*lst2 = s(*lst2);
	printf("ss\n");
	return;
}



