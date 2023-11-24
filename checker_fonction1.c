/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_fonction1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:00:38 by smarty            #+#    #+#             */
/*   Updated: 2023/11/24 21:33:59 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*rotate(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (lst);
	if (lst->next)
	{
		lst = lst_addback(lst, lst->data);
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (lst);
}

int	ra(t_list **lst)
{
	if (!(*lst))
		return (-1);
	*lst = rotate(*lst);
	printf("ra\n");
	return (0);
}

int	rb(t_list **lst)
{
	if (!(*lst))
		return (-1);
	*lst = rotate(*lst);
	printf("rb\n");
	return (0);
}

int	rr(t_list **lst1, t_list **lst2)
{
	if (!(*lst1) || !(*lst2))
		return (-1);
	*lst1 = rotate(*lst1);
	*lst2 = rotate(*lst2);
	printf("rr\n");
	return (0);
}
