/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:26:28 by sam               #+#    #+#             */
/*   Updated: 2023/11/23 15:42:49 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_lst1(int *tab, int ac)
{
	int		i;
	t_list	*lst1;

	lst1 = ft_lstnew();
	i = 0;
	while (i < (ac))
	{
		lst1 = lst_add(lst1, tab[i]);
		i++;
	}
	return (lst1);
}

char	**create_tab_str(int ac, char **av)
{
	char	**str;

	if (ac == 2)
		str = split(av[1]);
	else
		str = &av[1];
	return (str);
}

int	*create_tab(char **str)
{
	int		*tab;
	int		i;

	i = 0;
	tab = (int *)malloc(sizeof(int) * (len_tab(str)));
	while (i < len_tab(str))
	{
		tab[i] = atoi(str[i]);
		i++;
	}
	return (tab);
}

int	main(int ac, char **av)
{
	int		*tab;
	char	**str;
	t_list	*lst1;
	t_list	*lst2;

	if (ac < 2)
		return (printf("error/n"));
	str = create_tab_str(ac, av);
	if (error(str) == 1)
		return (0);
	tab = create_tab(str);
	if (error_double(tab, len_tab(str)) == 1)
		return (0);
	lst1 = create_lst1(tab, len_tab(str));
	lst2 = ft_lstnew();
	if (ac == 2)
		free_split(str);
	free(tab);
	add_rank(lst1);
	sort_lst(&lst1, &lst2);
	ft_lstclear(&lst1);
	ft_lstclear(&lst2);
	return (0);
}
