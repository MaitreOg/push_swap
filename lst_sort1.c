/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:25:24 by smarty            #+#    #+#             */
/*   Updated: 2023/11/24 21:24:33 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_tree_2(t_list **lst1, int rank_m)
{
	if ((*lst1)->rank == (rank_m - 1))
	{
		ra(lst1);
		ra(lst1);
	}
	else
	{
		sa(lst1);
		ra(lst1);
	}
	return ;
}

void	tri_tree(t_list **lst1)
{
	t_list	*tmp;
	int		rank_m;

	tmp = *lst1;
	rank_m = rank_max(lst1);
	if ((*lst1)->rank == rank_m)
	{
		ra(lst1);
		if ((*lst1)->rank == (rank_m - 1))
			sa(lst1);
	}
	if (ft_lstlast(*lst1)->rank == rank_m)
	{
		if ((*lst1)->rank == (rank_m - 1))
			sa(lst1);
	}
	else
		tri_tree_2(lst1, rank_m);
	return ;
}

void	little_sort(t_list **lst1, t_list **lst2)
{
	t_list	*tmp;
	int		rank_max;

	tmp = *lst1;
	rank_max = 0;
	while (tmp)
	{
		if (tmp->rank > rank_max)
			rank_max = tmp->rank;
		tmp = tmp->next;
	}
	while (lst_len(*lst1) > 3)
	{
		if ((*lst1)->rank < (rank_max - 2))
			pb(lst1, lst2);
		else
			ra(lst1);
	}
	return ;
}

int	rank_necessary(t_list *lst1)
{
	int		inferieur;
	int		len;
	int		new_len;
	t_list	*tmp;
	t_list	*tmp2;

	inferieur = 0;
	len = lst_len(lst1);
	tmp2 = lst1;
	new_len = ((len / 2)) + len % 2;
	while (inferieur != new_len)
	{
		tmp = lst1;
		inferieur = 0;
		while (tmp)
		{
			if (tmp->rank < tmp2->rank)
				inferieur++;
			tmp = tmp->next;
		}
		if (inferieur == new_len)
			return (tmp2->rank);
		tmp2 = tmp2->next;
	}
	return (tmp2->rank);
}

void	algo_sort1(t_list **lst1, t_list **lst2)
{
	int	len1;
	int	new_len;
	int	rank_n;

	rank_n = rank_necessary(*lst1);
	len1 = lst_len(*lst1);
	new_len = len1;
	while (new_len > (len1 / 2) * 1 && (len1 / 2) * 1 >= 3)
	{
		if ((*lst1)->rank < rank_n)
		{
			pb(lst1, lst2);
			if ((*lst2)->rank < rank_n - (len1 / 4))
				rb(lst2);
			new_len--;
		}
		else
			ra(lst1);
		if (new_len == 3)
			return ;
	}
	if ((len1 / 2) < 3)
		little_sort(lst1, lst2);
	return ;
}
