/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:31:09 by smarty            #+#    #+#             */
/*   Updated: 2023/11/04 14:54:32 by smarty           ###   ########.fr       */
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