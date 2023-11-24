/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_fonction3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:02:37 by smarty            #+#    #+#             */
/*   Updated: 2023/11/24 19:21:44 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*rrotate(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (lst);
	if (lst->next)
	{
		lst = lst_addfront(lst, ft_lstlast(lst)->data);
		tmp = lst;
		while (tmp->next->next)
			tmp = tmp->next;
		free (tmp->next);
		tmp->next = NULL;
	}
	return (lst);
}

int	rra(t_list **lst)
{
	if (!(*lst))
		return (-1);
	*lst = rrotate(*lst);
	printf("rra\n");
	return (0);
}

int	rrb(t_list **lst)
{
	if (!(*lst))
		return (-1);
	*lst = rrotate(*lst);
	printf("rrb\n");
	return (0);
}

int	rrr(t_list **lst1, t_list **lst2)
{
	if (!(*lst1) || !(*lst2))
		return (-1);
	*lst1 = rrotate(*lst1);
	*lst2 = rrotate(*lst2);
	printf("rrr\n");
	return (0);
}

int	pb(t_list **lst1, t_list **lst2)
{
	t_list	*tmp;

	if (!(*lst1))
		return (-1);
	*lst2 = lst_addfront(*lst2, (*lst1)->data);
	tmp = (*lst1)->next;
	free(*lst1);
	*lst1 = tmp;
	printf("pb\n");
	return (0);
}