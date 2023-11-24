/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:04:50 by smarty            #+#    #+#             */
/*   Updated: 2023/11/24 21:24:51 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valeur_abs(int i, int y)
{
	if (i < 0)
		i *= -1;
	if (y < 0)
		y *= -1;
	i += y;
	return (i);
}

int	tmp_cost_inf(t_list *tmp, int min)
{
	if (tmp->cost1 <= tmp->cost2 && tmp->cost1 * -1 < min)
		min = tmp->cost1 * -1;
	if (tmp->cost1 > tmp->cost2 && tmp->cost2 * -1 < min)
		min = tmp->cost2 * -1;
	return (min);
}

int	tmp_cost_sup(t_list *tmp, int min)
{
	if (tmp->cost1 >= tmp->cost2 && tmp->cost1 < min)
		min = tmp->cost1;
	if (tmp->cost1 < tmp->cost2 && tmp->cost2 < min)
		min = tmp->cost2;
	return (min);
}

int	find_min(t_list **lst)
{
	t_list	*tmp;
	int		min;
	int		min2;
	int		rank;

	tmp = *lst;
	min = INT_MAX;
	while (tmp)
	{
		min2 = min;
		if (tmp->cost1 < 0 && tmp->cost2 < 0)
			min = tmp_cost_inf(tmp, min);
		else if (tmp->cost1 >= 0 && tmp->cost2 >= 0)
			min = tmp_cost_sup(tmp, min);
		else if (valeur_abs(tmp->cost1, tmp->cost2) < min)
			min = valeur_abs(tmp->cost1, tmp->cost2);
		if (min != min2)
		{
			rank = tmp->rank;
		}
		tmp = tmp->next;
	}
	return (rank);
}
