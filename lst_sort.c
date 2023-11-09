/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:52:26 by sam               #+#    #+#             */
/*   Updated: 2023/11/08 16:40:25 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int mediane(t_list *lst, int data)
{
    int superieur;
    int inferieur;
    int true;
    t_list  *tmp;

    superieur = 0;
    inferieur = 0;
    true = 0;
    tmp = lst;
    while (tmp)
    {
        if (tmp->data > data)
            superieur++;
        if (tmp->data < data)
            inferieur++;
        if (tmp->next == NULL && inferieur == superieur)
            true = 1;
        tmp = tmp->next;
    }
    printf("data = %d\n", data);
    printf("superieur = %d\n", superieur);
    printf("inferieur = %d\n", inferieur);
    printf("true = %d\n", true);
    printf("\n\n");
    return (true);
}