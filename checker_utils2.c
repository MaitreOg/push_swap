/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:28:30 by smarty            #+#    #+#             */
/*   Updated: 2023/11/24 22:08:04 by smarty           ###   ########.fr       */
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

t_list	*ft_lstnew(void)
{
	return (NULL);
}
