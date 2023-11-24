/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:52:26 by sam               #+#    #+#             */
/*   Updated: 2023/11/24 21:22:17 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rank_max(t_list **lst)
{
	t_list	*tmp;
	int		rank_max;

	tmp = *lst;
	rank_max = 0;
	while (tmp)
	{
		if (tmp->rank > rank_max)
			rank_max = tmp->rank;
		tmp = tmp->next;
	}
	return (rank_max);
}

void	sort_lst(t_list **lst1, t_list **lst2)
{
	while (lst_len(*lst1) > 3)
		algo_sort1(lst1, lst2);
	tri_tree(lst1);
	sort_b(lst1, lst2);
	return ;
}

int	test_count(t_list **lst)
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
		return (1);
	return (0);
}

void	replace_lst(t_list **lst1)
{
	t_list	*tmp;
	int		i;

	i = test_count(lst1);
	tmp = *lst1;
	if (i == 0)
	{
		while (ft_lstlast(tmp)->rank != rank_max(lst1))
			rra(lst1);
	}
	else
	{
		while (ft_lstlast(tmp)->rank != rank_max(lst1))
			ra(lst1);
	}
	return ;
}

void	sort_b(t_list **lst1, t_list **lst2)
{
	int	rank;

	while (*lst2)
	{
		add_cost_b(lst2);
		aff_cost_a(lst1, lst2);
		rank = find_min(lst2);
		move_node(lst1, lst2, rank);
	}
	replace_lst(lst1);
	return ;
}
