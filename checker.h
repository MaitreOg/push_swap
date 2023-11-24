/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:14:09 by smarty            #+#    #+#             */
/*   Updated: 2023/11/24 18:37:05 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "get_next_line/get_next_line.h"
# include <stdlib.h>

typedef struct s_list
{
	int				data;
	int				rank;
	struct s_list	*next;
}					t_list;

int		ra(t_list **lst);
int		rb(t_list **lst);
int		rra(t_list **lst);
int		rrb(t_list **lst);
int		rr(t_list **lst1, t_list **lst2);
int		rrr(t_list **lst1, t_list **lst2);
int		pb(t_list **lst1, t_list **lst2);
int		pa(t_list **lst1, t_list **lst2);
int		sa(t_list **lst);
int		sb(t_list **lst);
int		ss(t_list **lst1, t_list **lst2);
t_list	*lst_addfront(t_list *lst, int data);
t_list	*lst_addback(t_list *lst, int data);
t_list	*ft_lstlast(t_list *lst);
int		error(char **str);
int		error_double(int *tab, int len);
int	ft_strncmp(char *s1, char *s2, size_t n);
void	ft_lstclear(t_list **lst);
t_list	*lst_add(t_list *lst, int data);
t_list	*ft_lstnew(void);
void	checker(t_list **lst1, t_list **lst2);
#endif