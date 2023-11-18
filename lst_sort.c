/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:52:26 by sam               #+#    #+#             */
/*   Updated: 2023/11/18 14:37:23 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_rank(t_list *lst, int data)
{
    int rank;
    t_list *tmp;

    rank = 0;
    tmp = lst;
    while (tmp)
    {
        if (tmp->data < data)
            rank++;
        tmp = tmp->next;
    }
    return (rank);
}

void add_rank(t_list *lst)
{
    t_list *tmp;

    tmp = lst;
    while (tmp)
    {
        tmp->rank = find_rank(lst, tmp->data);
        tmp = tmp->next;
    }
}

void    sort_lst(t_list *lst1, t_list *lst2)
{
    while (lst_len(lst1) > 3)
        algo_sort1(&lst1, &lst2);
    tri_tree(&lst1);
    sort_b(&lst1, &lst2);
    //print_lst(lst1);
    //printf("\n\n");
    //print_lst(lst2);
    
   /*printf("\nressult =\n");
    printf("lst 1 =");    
    print_lst(lst1);
    printf("lst2 = ");
    print_lst(lst2);*/
    return;

}

void    sort_b(t_list **lst1, t_list **lst2)
{
    while (*lst2)
    {
       
        if ((*lst2)->rank == ((*lst1)->rank - 1))
        {   
            pa(lst1, lst2);
            if (ft_lstlast(*lst1)->rank == ((*lst1)->rank - 1))
                rra(lst1);
        }
        else if ((*lst2)->rank == ((*lst1)->rank - 2))
        {
            pa(lst1, lst2);
            ra(lst1);
        }
        else
            rb(lst2);
    }
    return;
}

void    tri_tree(t_list **lst1)
{
    t_list  *tmp;
    int rank_max;

    tmp = *lst1;
    rank_max = 0;
    while(tmp)
    {
        if (tmp->rank > rank_max)
            rank_max = tmp->rank;
        tmp = tmp->next;
    }
    if ((*lst1)->rank == rank_max)
    {
        ra(lst1);
        if ((*lst1)->rank == (rank_max - 1))
            sa(lst1);
    }
    if (ft_lstlast(*lst1)->rank == rank_max)
    {
        if ((*lst1)->rank == (rank_max - 1))
            sa(lst1);
    }
    else
    {
        if ((*lst1)->rank == (rank_max - 1))
        {
            ra(lst1);
            ra(lst1);
        }
        else
        {
            sa(lst1);
            ra(lst1);
        }
        return;
    }

}
void little_sort(t_list **lst1, t_list **lst2)
{
    t_list  *tmp;
    int rank_max;

    tmp = *lst1;
    rank_max = 0;
    while(tmp)
    {
        if (tmp->rank > rank_max)
            rank_max = tmp->rank;
        tmp = tmp->next;
    }
    //printf("rank max = %d, rank =%d", rank_max, (rank_max - 2));
    //(*lst1);
    while (lst_len(*lst1) > 3)
    {
        if ((*lst1)->rank < (rank_max - 2))
            pb(lst1, lst2);
        else
            ra(lst1);
    }
    return;
}

int rank_necessary(t_list *lst1)
{
    int inferieur;
    int len;
    int new_len;
    t_list  *tmp;
    t_list  *tmp2;

    len = lst_len(lst1);
    tmp2 = lst1;
    new_len = ((len / 3) * 2) + len % 3;
    
    while (inferieur != new_len)
    {
        tmp = lst1;
        inferieur = 0;
        while (tmp)
        {
            if (tmp->rank < tmp2->rank)
                inferieur++;
            tmp = tmp->next;
        }
       // printf("%d\n\n lst1 = ", inferieur);
        //print_lst(lst1);
        //printf("\nfin\n\n");
        if (inferieur == new_len)
            return (tmp2->rank);
        tmp2 = tmp2->next;  
    }
    return (tmp2->rank);
}

void algo_sort1(t_list **lst1, t_list **lst2)
{
    int len1;
    int new_len;
    int rank_n;
    
    rank_n = rank_necessary(*lst1);
    len1 = lst_len(*lst1);
    new_len = len1; 
    if ((len1 / 3) < 3)
    {
        little_sort(lst1, lst2);
        return;
    }
    while (new_len > (len1 / 3) && (len1 / 3) >= 3)
    {
        if ((*lst1)->rank < rank_n)
        {
            pb(lst1, lst2);
            new_len--;
        }
        else
            ra(lst1);
        //print_rank(*lst1);
        if (new_len == 3)
            return;
    }
    return;
}
