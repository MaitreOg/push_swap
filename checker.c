/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:59:59 by smarty            #+#    #+#             */
/*   Updated: 2023/11/24 21:48:31 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_lst(t_list **lst1, t_list **lst2)
{
	t_list	*tmp;

	tmp = *lst1;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
		{
			write(1, "ko\n", 3);
			return ;
		}
		tmp = tmp->next;
	}
	if (tmp->next == NULL && *lst2 == NULL)
	{
		write(1, "ok\n", 3);
		return ;
	}
	write(1, "ko\n", 3);
	return ;
}

int	move(char *str, t_list **lst1, t_list **lst2)
{
	if (ft_strncmp("sa\n", str, 3) == 0)
		return (sa(lst1));
	else if (ft_strncmp("sb\n", str, 3) == 0)
		return (sb(lst2));
	else if (ft_strncmp("ss\n", str, 3) == 0)
		return (ss(lst1, lst2));
	else if (ft_strncmp("pa\n", str, 3) == 0)
		return (pa(lst1, lst2));
	else if (ft_strncmp("pb\n", str, 3) == 0)
		return (pb(lst1, lst2));
	else if (ft_strncmp("ra\n", str, 3) == 0)
		return (ra(lst1));
	else if (ft_strncmp("rb\n", str, 3) == 0)
		return (rb(lst2));
	else if (ft_strncmp("rr\n", str, 3) == 0)
		return (rr (lst1, lst2));
	else if (ft_strncmp("rra\n", str, 4) == 0)
		return (rra(lst1));
	else if (ft_strncmp("rrb\n", str, 4) == 0)
		return (rrb(lst2));
	else if (ft_strncmp("rrr\n", str, 4) == 0)
		return (rrr(lst1, lst2));
	return (-1);
}

void	checker(t_list **lst1, t_list **lst2)
{
	char	*str;
	int		i;

	i = 0;
	str = get_next_line(0);
	while (str)
	{
		i = move(str, lst1, lst2);
		if (i == -1)
		{
			write (1, "error\n", 6);
			get_next_line(-1);
			ft_lstclear(lst1);
			ft_lstclear(lst2);
			free(str);
			return ;
		}
		free (str);
		str = get_next_line(0);
	}
	get_next_line(-1);
	check_lst(lst1, lst2);
	ft_lstclear(lst1);
	ft_lstclear(lst2);
	free(str);
}
