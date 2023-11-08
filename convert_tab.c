/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:26:28 by sam               #+#    #+#             */
/*   Updated: 2023/11/08 15:43:05 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *create_lst1(int *tab, int ac)
{
    int     i;
    t_list  *lst1;
    printf("list 1 cree\n");
    lst1 = ft_lstnew(lst1);
  
    i = 0;
    while (i < (ac -1))
    {
        lst1 = lst_addback(lst1, tab[i]);
        i++;
    }
    return (lst1);
}

int main(int ac, char **av)
{
    int     *tab;
    int     i;
    t_list  *lst1;
    t_list  *lst2;

    i = 0;
    if (ac < 2)
        return(printf("error/n"));
    tab = (int *)malloc(sizeof(int) * (ac - 1));
    while (i < ac - 1)
    {
        tab[i] = atoi(av[i + 1]);
        i++;
    }
    lst1 = create_lst1(tab, ac);
    print_lst(lst1);
    lst2 = ft_lstnew(lst2);
    if (lst2 == NULL)
        printf("pile b vide\n");
    lst2 = pb(lst1, lst2);
    lst1 = lst1->next;
    print_lst(lst1);
    printf("pile b :\n");
    print_lst(lst2);
    lst1 = rra(lst1);
    print_lst(lst1);
    //tri_lst(lst1, lst2);
    return (0);
}