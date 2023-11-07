/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:31:09 by smarty            #+#    #+#             */
/*   Updated: 2023/11/07 16:59:34 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *lst)
{
	t_list	*first;
	t_list	*last;

	first = *lst;
	last = ft_lstlast(lst);
	last->next = first;
	first->next = NULL;
	lst->next;
	printf("ra\n");
}

void	rb(t_list *lst)
{
	t_list	*first;
	t_list	*last;

	first = *lst;
	last = ft_lstlast(lst);
	last->next = first;
	first->next = NULL;
	lst->next;
	printf("rb\n");
}

void	rr(t_list *lst1, t_list *lst2)
{
	t_list	*first1;
	t_list	*last1;
	t_list	*first2;
	t_list	*last2;

	first1 = *lst1;
	first2 = *lst2;
	last1 = ft_lstlast(lst1);
	last2 = ft_lstlast(lst2);
	last1->next = first1;
	last2->next = first2;
	first1->next = NULL;
	first2->next = NULL;
	lst1->next;
	lst2->next;
	printf("rr\n");
}

void	pb(t_list *lst1, t_list *lst2)
{
	t_list	first1;

	first1 = *lst1;
	lst1->next;
	first1->next = lst2;
	*lst2 = first1;
}

void	pa(t_list *lst1, t_list *lst2)
{
	t_list	first2;

	first2 = *lst2;
	lst2->next;
	first2->next = lst1;
	*lst1 = first2;
}


