/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:17:35 by smarty            #+#    #+#             */
/*   Updated: 2023/11/24 18:18:25 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	error_letter(char **str)
{
	int	i;
	int	y;

	i = 0;
	while (str[i])
	{
		y = 0;
		while (str[i][y])
		{
			if (str[i][y] < '0' || str[i][y] > '9')
				return (1);
			y++;
		}
		i++;
	}
	return (0);
}

int	error_overflow(char **str)
{
	int			i;
	int			y;
	long long	result;

	i = 0;
	while (str[i])
	{
		y = 0;
		result = 0;
		while (str[i][y])
		{
			if (str[i][y] >= '0' && str[i][y] <= '9')
				result = result * 10 + (str[i][y] - '0');
			y++;
		}
		if (result > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

int	error_double(int *tab, int len)
{
	int	i;
	int	y;

	i = 0;
	while (i < len)
	{
		y = i + 1;
		while (y < len)
		{
			if (tab[i] == tab[y])
			{
				write (1, "error\n", 6);
				return (1);
			}
			y++;
		}
		i++;
	}
	return (0);
}

int	error(char **str)
{
	if (error_overflow(str) == 1)
	{
		write (1, "error\n", 6);
		return (1);
	}
	if (error_letter(str) == 1)
	{
		write (1, "error\n", 6);
		return (1);
	}
	return (0);
}