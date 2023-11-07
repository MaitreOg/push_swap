/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:26:28 by sam               #+#    #+#             */
/*   Updated: 2023/11/07 17:46:27 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    create_lst(int *tab)
{
    int     i;
    t_list  *lst1;

    i = 0;
    while (tab[i])
    {
        lst1->data = tab[i];
        printf("data = %d\n", lst1->data);
        lst1->next;
        i++;
    }
    lst1 = NULL;
}

int main(int ac, char **av)
{
    int *tab;
    int i;

    i = 0;
    if (ac < 2)
        return(printf("error/n"));
    tab = (int *)malloc(sizeof(int) * (ac - 1));
    while (i < ac - 1)
    {
        tab[i] = atoi(av[i + 1]);
        i++;
    }
    /*int y = 0;
    while (i > y)
    {
        printf("%d\n", tab[y]);
        y++;
    }*/
    create_lst(tab);
    return (0);
}