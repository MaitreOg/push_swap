/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:31:22 by smarty            #+#    #+#             */
/*   Updated: 2023/11/10 01:42:49 by sam              ###   ########.fr       */
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
t_list	*ft_lstnew(t_list *new);
t_list	*lst_addback(t_list *lst, int data);
t_list	*lst_addfront(t_list *lst, int data);
t_list	*rotate(t_list *lst);
t_list	*rrotate(t_list *lst);
void	ra(t_list **lst);
void	rb(t_list **lst);
void	rra(t_list **lst);
void	rrb(t_list **lst);
void	rr(t_list **lst1, t_list **lst2);
void	rrr(t_list **lst1, t_list **lst2);
void	pb(t_list **lst1, t_list **lst2);
void	pa(t_list **lst1, t_list **lst2);
int 	mediane(t_list *lst, int data);
int		lst_len(t_list *lst);
void	print_lst(t_list *lst);

#endif /*push_swap*/
