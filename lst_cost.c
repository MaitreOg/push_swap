/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:19:00 by smarty            #+#    #+#             */
/*   Updated: 2023/11/24 21:24:36 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_rank(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		tmp->rank = find_rank(lst, tmp->data);
		tmp = tmp->next;
	}
}

void	add_cost_b(t_list **lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *lst;
	while (i <= (lst_len(*lst) / 2) + lst_len(*lst) % 2 - 1)
	{
		tmp->cost2 = i;
		i++;
		tmp = tmp->next;
	}
	if (lst_len(*lst) % 2 == 0)
		i++;
	while (tmp)
	{
		tmp->cost2 = -i + 1;
		i--;
		tmp = tmp->next;
	}
	return ;
}

int	pos_max(t_list **lst)
{
	int		i;
	int		rank;
	t_list	*tmp;

	i = 0;
	rank = rank_max(lst);
	tmp = *lst;
	while (tmp->rank != rank)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < lst_len(*lst) / 2)
		return (i);
	return (-(lst_len(*lst) - i));
}

int	add_cost_a(int rank, t_list **lst1)
{
	int		i;
	int		pos;
	long	target;
	t_list	*tmp;

	target = LONG_MAX;
	tmp = *lst1;
	i = 0;
	while (tmp)
	{
		if (tmp->rank > rank && tmp->rank < target)
		{
			target = tmp->rank;
			pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	if (target != LONG_MAX && pos < lst_len(*lst1) / 2)
		return (pos);
	else
		return (- (lst_len(*lst1) - pos));
	return (pos_max(lst1));
}

void	aff_cost_a(t_list **lst1, t_list **lst2)
{
	t_list	*tmp2;

	tmp2 = *lst2;
	while (tmp2)
	{
		tmp2->cost1 = add_cost_a(tmp2->rank, lst1);
		tmp2 = tmp2->next;
	}
}
