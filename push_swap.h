/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:31:22 by smarty            #+#    #+#             */
/*   Updated: 2023/11/24 21:29:31 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				rank;
	int				cost1;
	int				cost2;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void);
void	ft_lstclear(t_list **lst);
t_list	*lst_addback(t_list *lst, int data, int rank);
t_list	*lst_add(t_list *lst, int data);
t_list	*lst_addfront(t_list *lst, int data, int rank);
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
void	sa(t_list **lst);
void	sb(t_list **lst);
void	ss(t_list **lst1, t_list **lst2);
int		lst_len(t_list *lst);
int		find_rank(t_list *lst, int data);
void	add_rank(t_list *lst);
void	sort_lst(t_list **lst1, t_list **lst2);
int		find_min(t_list **lst);
void	move_node(t_list **lst1, t_list **lst2, int rank);
void	aff_cost_a(t_list **lst1, t_list **lst2);
void	add_cost_b(t_list **lst);
int		pos_max(t_list **lst);
void	algo_sort1(t_list **lst1, t_list **lst2);
void	little_sort(t_list **lst1, t_list **lst2);
void	tri_tree(t_list **lst1);
void	sort_b(t_list **lst1, t_list **lst2);
int		error(char **str);
int		error_double(int *tab, int len);
char	**split(char *str);
void	free_split(char **str);
int		len_tab(char **str);
int		rank_max(t_list **lst);
#endif /*push_swap*/
