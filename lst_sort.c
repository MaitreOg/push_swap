/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:52:26 by sam               #+#    #+#             */
/*   Updated: 2023/11/20 17:34:43 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int rank_max(t_list **lst)
{
    t_list  *tmp;
    int rank_max;

    tmp = *lst;
    rank_max = 0;
    while(tmp)
    {
        if (tmp->rank > rank_max)
            rank_max = tmp->rank;
        tmp = tmp->next;
    }
    return (rank_max);
}
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
    
    //printf("\n\n");
    //print_lst(lst2);
    
   /*printf("\nressult =\n");
    printf("lst 1 =");    
    print_lst(lst1);
    printf("lst2 = ");
    print_lst(lst2);*/
    return;

}
int valeur_abs(int i, int y)
{
    if (i < 0)
        i *= -1;
    if (y < 0)
        y *= -1;
    i += y;
    return (i);
}
int find_min(t_list **lst)
{
    t_list  *tmp;
    int     min;
    int     min2;
    int     rank;

    tmp = *lst;
    min = INT_MAX;
    while (tmp)
    {
        min2 = min;
        if (tmp->cost1 < 0 && tmp->cost2 < 0)
        {
            if (tmp->cost1 <= tmp->cost2 && tmp->cost1 * -1 < min)
                min = tmp->cost1 * -1;
            if (tmp->cost1 > tmp->cost2 && tmp->cost2 * -1 < min)
                min = tmp->cost2 * -1;
        }
        else if (tmp->cost1 >= 0 && tmp->cost2 >= 0)
        {
            if (tmp->cost1 >= tmp->cost2 && tmp->cost1 < min)
                min = tmp->cost1;
            if (tmp->cost1 < tmp->cost2 && tmp->cost2  < min)
                min = tmp->cost2;
        }
        else if (valeur_abs(tmp->cost1, tmp->cost2) < min)
            min = valeur_abs(tmp->cost1, tmp->cost2);
        if (min != min2)
        {    
            rank = tmp->rank;
            //printf("la data= %d\n", tmp->data);
        }
        tmp = tmp->next;
    }
    //printf("le rank = %d\n", rank);
    return (rank);
}
void    add_cost_b(t_list **lst)
{
    int i;
    int rank;
    t_list  *tmp;

    i = 0;
    tmp = *lst;
    while (i <= (lst_len(*lst) / 2) + lst_len(*lst) % 2 - 1)
    {
        tmp->cost2 = i;
        i++;
        tmp = tmp->next;
    }
    if (lst_len(*lst) % 2 == 0)
            i++;
    while (tmp)
    {
        tmp->cost2 = -i + 1;
        i--;
        tmp = tmp->next;
    }
    return;
}
int    pos_max(t_list **lst)
{
    int i;
    int rank;
    t_list  *tmp;

    i = 0;
    rank = rank_max(lst);
    tmp = *lst;
    while (tmp->rank != rank)
    {
        i++;
        tmp = tmp->next;
    }
    if (i < lst_len(*lst) / 2)
        return (i);
    return (-(lst_len(*lst) - i));
}
int add_cost_a(int rank, t_list **lst1)
{
    int i;
    int pos;
    long target;
    t_list  *tmp;

    target = LONG_MAX;
    tmp = *lst1;
    i = 0;
    while (tmp)
    {
        if (tmp->rank > rank && tmp->rank < target)
        {
            target = tmp->rank;
            pos = i;
        }
        i++;
        tmp = tmp->next;
    
    }
    if (target != LONG_MAX && pos < lst_len(*lst1) / 2)
        return (pos);
    else
        return (- (lst_len(*lst1) - pos));
    return (pos_max(lst1));
}
void    aff_cost_a(t_list **lst1, t_list **lst2)
{
    t_list  *tmp2;

    tmp2 = *lst2;
    while (tmp2)
    {
        tmp2->cost1 = add_cost_a(tmp2->rank, lst1);
        tmp2 = tmp2->next;
    }
}

void move_node(t_list **lst1, t_list **lst2, int rank)
{
    t_list *tmp;
    int    cost1;
    int    cost2;

    tmp = *lst2;
    
    while (tmp && tmp->rank != rank )
        tmp = tmp->next;
    //printf("value = %d\n\n", tmp->data);
    cost1 = tmp->cost1;
    cost2 = tmp->cost2;
    //printf("cost 1 = %d\n\n", cost1);
    //printf("cost 2 = %d\n\n", cost2);
    if (cost1 >= 0 && cost2 >= 0)
    {
        while (cost1 > 0 && cost2 > 0)
        {
            rr(lst1, lst2);
            cost1--;
            cost2--;
        }
        while (cost1 > 0)
        {
            ra(lst1);
            cost1--;
        }
        while (cost2 > 0)
        {
            rb(lst2);
            cost2--;
        }
    }
    else if (cost1 < 0 && cost2 < 0)
    {
        while (cost1 <= -1 && cost2 <= -1)
        {
            rrr(lst1, lst2);
            cost1++;
            cost2++;
        }
        while (cost1 < 0)
        {
            rra(lst1);
            cost1++;
        }
        while (cost2 < 0)
        {
            rrb(lst2);
            cost2++;
        }
    }
    else
    {
        while (cost1 > 0)
        {
            ra(lst1);
            cost1--;
        }
        while (cost1 < 0)
        {
            rra(lst1);
            cost1++;
        }
        while (cost2 > 0)
        {
            rb(lst2);
            cost2--;
        }
        while (cost2 < 0)
        {
            rrb(lst2);
            cost2++;
        }
    }
    pa(lst1, lst2);
    return;   
}

void    replace_lst(t_list **lst1)
{
    t_list  *tmp;

    tmp = *lst1;
    while (ft_lstlast(*lst1)->rank != rank_max(lst1))
    {
        rra(lst1);
        tmp = tmp->next;
    }
    return;
}
void    sort_b(t_list **lst1, t_list **lst2)
{
    int rank;
    
    while (*lst2)
    {  
        add_cost_b(lst2);
        aff_cost_a(lst1, lst2);
        rank = find_min(lst2);
        //print_lst(lst1, lst2);
        move_node(lst1, lst2, rank);
        
    }
    replace_lst(lst1);
    //print_lst(lst1, lst2);
    return;
}
/*int    test_count(t_list **lst)
{
    int i;
    int rank;
    t_list  *tmp;

    i = 0;
    rank = rank_max(lst);
    tmp = *lst;
    while (tmp->rank != rank)
    {
        i++;
        tmp = tmp->next;
    }
    if (i < lst_len(*lst) / 2)
        return (1);
    return (0);
}
void    sort_b(t_list **lst1, t_list **lst2)
{
    int test;

    while (*lst2)
    {
        test = test_count(lst2);

        if (test == 0)
        {   
            while ((*lst2)->rank != rank_max(lst2))
                rrb(lst2);
            pa(lst1, lst2);
        }
        else 
        {
            while ((*lst2)->rank != rank_max(lst2))
                rb(lst2);
            pa(lst1, lst2);
        }
    }
    return;
}*/



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
    new_len = ((len / 6)) + len % 6;
    
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
    if ((len1 / 6) < 3)
    {
        little_sort(lst1, lst2);
        return;
    }
    while (new_len > (len1 / 6) * 5 && (len1 / 6) * 5 >= 3)
    {
        if ((*lst1)->rank < rank_n)
        {
            pb(lst1, lst2);
            if ((*lst2)->rank < rank_n - (len1 / 12))
                rb(lst2);
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
