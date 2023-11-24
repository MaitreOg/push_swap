/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tab_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:10:55 by smarty            #+#    #+#             */
/*   Updated: 2023/11/23 14:12:49 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	count_word(const char *s)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (s[0] != ' ' && s[0])
		nb++;
	while (s[i])
	{
		if (s[i] == ' ' && s[i + 1] != ' ' && s[i + 1])
			nb++;
		i++;
	}
	return (nb);
}

char	**split(char *str)
{
	int		i;
	int		y;
	int		z;
	char	**split;

	i = 0;
	z = 0;
	split = (char **)malloc(sizeof(char *) * (count_word(str) + 1));
	while (str[i])
	{
		y = 0;
		while (str[i + y] != ' ' && str[i + y])
			y++;
		split[z] = malloc(y + 1);
		y = 0;
		while (str[i] != ' ' && str[i])
			split[z][y++] = str[i++];
		split[z][y] = 0;
		while (str[i] == ' ' && str[i])
			i++;
		z++;
	}
	split[z] = NULL;
	return (split);
}

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

int	len_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}

int	main(int ac, char **av)
{
	int		*tab;
	int		i;
	char	**str;
	t_list	*lst1;
	t_list	*lst2;

	i = 0;
	if (ac < 2)
		return (printf("error/n"));
	else if (ac == 2)
		str = split(av[1]);
	else
		str = &av[1];
	if (error(str) == 1)
		return (0); 
	tab = (int *)malloc(sizeof(int) * (len_tab(str)));
	while (i < len_tab(str))
	{
		tab[i] = atoi(str[i]);
		i++;
	}
	if (error_double(tab, len_tab(str)) == 1)
		return (0);
	lst1 = create_lst1(tab, len_tab(str));
	lst2 = ft_lstnew();
	if (ac == 2)
		free_split(str);
	free(tab);
	checker(&lst1, &lst2);
	ft_lstclear(&lst1);
	ft_lstclear(&lst2);
	return (0);
}
