/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:59:13 by smarty            #+#    #+#             */
/*   Updated: 2023/11/23 15:02:43 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	len_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
