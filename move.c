/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:13:38 by smarty            #+#    #+#             */
/*   Updated: 2023/11/24 21:24:23 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_pos(t_list **lst1, t_list **lst2, int cost1, int cost2)
{
	while (cost1 > 0 && cost2 > 0)
	{
		rr(lst1, lst2);
		cost1--;
		cost2--;
	}
	while (cost1 > 0)
	{
		ra(lst1);
		cost1--;
	}
	while (cost2 > 0)
	{
		rb(lst2);
		cost2--;
	}
	return ;
}

void	move_neg(t_list **lst1, t_list **lst2, int cost1, int cost2)
{
	while (cost1 <= -1 && cost2 <= -1)
	{
		rrr(lst1, lst2);
		cost1++;
		cost2++;
	}
	while (cost1 < 0)
	{
		rra(lst1);
		cost1++;
	}
	while (cost2 < 0)
	{
		rrb(lst2);
		cost2++;
	}
	return ;
}

void	move_two(t_list **lst1, t_list **lst2, int cost1, int cost2)
{
	while (cost1 > 0)
	{
		ra(lst1);
		cost1--;
	}
	while (cost1 < 0)
	{
		rra(lst1);
		cost1++;
	}
	while (cost2 > 0)
	{
		rb(lst2);
		cost2--;
	}
	while (cost2 < 0)
	{
		rrb(lst2);
		cost2++;
	}
	return ;
}

void	move_node(t_list **lst1, t_list **lst2, int rank)
{
	t_list	*tmp;
	int		cost1;
	int		cost2;

	tmp = *lst2;
	while (tmp && tmp->rank != rank)
		tmp = tmp->next;
	cost1 = tmp->cost1;
	cost2 = tmp->cost2;
	if (cost1 >= 0 && cost2 >= 0)
		move_pos(lst1, lst2, cost1, cost2);
	else if (cost1 < 0 && cost2 < 0)
		move_neg(lst1, lst2, cost1, cost2);
	else
		move_two(lst1, lst2, cost1, cost2);
	pa(lst1, lst2);
	return ;
}
