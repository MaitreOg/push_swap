/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:52:26 by sam               #+#    #+#             */
/*   Updated: 2023/11/09 11:28:05 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int mediane_impaire(t_list *lst, int data)
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


int mediane_paire(t_list *lst, int data)
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
        if (tmp->next == NULL && (inferieur + 1) == superieur)
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


void    algo_sort(t_list *lst1, t_list *lst2)
{
    int len1;
    int mediane;

    len1 = lst_len(lst1);
    if (len1 % 2 == 0)
        mediane = mediane_paire;
    else
        meidane = mediane_impaire;    
    while (len1 > 3)
    {
        if (lst1->data < mediane)
        {
            lst2 = pb(lst1, lst2);
            lst1 = lst1->next;
        }
        else
            lst1 = ra(lst1);
        len1 = lst_len(lst1);
    }
}


