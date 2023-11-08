/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:31:09 by smarty            #+#    #+#             */
/*   Updated: 2023/11/08 15:41:52 by sam              ###   ########.fr       */
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

t_list	*ra(t_list *lst)
{
	lst = rotate(lst);
	printf("ra\n");
	return (lst);
}

t_list	*rb(t_list *lst)
{
	lst = rotate(lst);
	printf("rb\n");
	return (lst);
}

void	rr(t_list *lst1, t_list *lst2)
{
	lst1 = rotate(lst1);
	lst2 = rotate(lst2);
	printf("rr\n");

}

t_list	*rra(t_list *lst)
{
	lst = rrotate(lst);
	printf("rra\n");
	return (lst);
}

t_list	*rrb(t_list *lst)
{
	lst = rrotate(lst);
	printf("rrb\n");
	return (lst);
}

void	rrr(t_list *lst1, t_list *lst2)
{
	lst1 = rrotate(lst1);
	lst2 = rrotate(lst2);
	printf("rrr\n");
}

t_list	*pb(t_list *lst1, t_list *lst2)
{
	lst2 = lst_addfront(lst2, lst1->data);
	printf("pb\n");
	return (lst2);
}


/*void	pb(t_list *lst1, t_list *lst2)
{
	t_list	*first1;

	first1 = lst1;
	lst1 = lst1->next;
	first1->next = lst2;
	*lst2 = first1;
}

void	pa(t_list *lst1, t_list *lst2)
{
	t_list	*first2;

	first2 = lst2;
	lst2 = lst2->next;
	first2->next = lst1;
	*lst1 = first2;
}
*/

