/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:37:21 by smarty            #+#    #+#             */
/*   Updated: 2023/11/22 20:28:12 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free (*lst);
		*lst = temp;
	}
	*lst = NULL;
}
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_atoi(char *nptr)
{
	int	i;
	int	result;
	int	signe;

	signe = 1;
	i = 0;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * signe);
}

t_list	*ft_lstnew()
{
	return (NULL);
}

t_list	*lst_addback(t_list *lst, int data, int rank)
{
	t_list	*node;
	t_list	*tmp;
	
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->rank = rank;
	node->data = data;
	node->next = NULL;
	if (!lst)
		return (node);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (lst);
}

t_list	*lst_add(t_list *lst, int data)
{
	t_list	*node;
	t_list	*tmp;
	
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	if (!lst)
		return (node);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (lst);
}

t_list	*lst_addfront(t_list *lst, int data, int rank)
{
	t_list	*node;
	
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->rank = rank;
	node->data = data;
	node->next = lst;
	return (node);
}
void	print_lst(t_list **lst1, t_list **lst2)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *lst1;
	tmp2 = *lst2;
	while (tmp1 || tmp2)
	{
		if (tmp1)
		{
			printf("%d (%d)(%d)", tmp1->data, tmp1->cost1, tmp1->cost2);
			tmp1 = tmp1->next;
		}
		else 
			printf("\t");
		printf("\t");
		if (tmp2)
		{
			printf("%d (%d)(%d)", tmp2->data, tmp2->cost1, tmp2->cost2);
			tmp2 = tmp2->next;
		}
		printf("\n\n");
	}
}
void	print_rank(t_list *lst)
{
	t_list	*print;

	print = lst;
	if (lst == NULL)
	{
		printf("chaine vide\n");
		return;
	}
	while (print)
	{
		printf("%d\n", print->rank);
		print = print->next;
	}
}


int lst_len(t_list *lst)
{
	int	i;

	i = 0;
	while(lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}