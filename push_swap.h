/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:31:22 by smarty            #+#    #+#             */
/*   Updated: 2023/11/04 15:09:12 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstlast(t_list *lst);
void	ra(t_list *lst);
void	rb(t_list *lst);
void	rr(t_list *lst1, t_list *lst2);

#endif /*push_swap*/
