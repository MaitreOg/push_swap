/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:58:57 by sam               #+#    #+#             */
/*   Updated: 2023/11/07 17:34:55 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra(t_list *lst1)
{
    t_list  *lst1temp;
    t_list  *temp;
    
    temp = ft_lstlast(lst1);
    while (lst1temp->next->next)
        lst1temp->next;
    lst1temp->next = NULL;
    temp->next = *lst1;
}