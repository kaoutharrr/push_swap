/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:30:37 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/02 06:46:33 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
# include "libft/libft.h"
# include<unistd.h>
# include<stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}			t_list;


typedef struct s_data
{
	int		i;
	char	*s;
	char	*joined;
	char	**splited;
	
}			t_data;



void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void reverse_a(t_list **a);
void reverse_b(t_list **b);
void	swap_a(t_list **a);
void	swap_b(t_list **b);
int	ft_strlen_a(char *s);
char	*ft_strchr( char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	print_list(t_list *list);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	magic(char **av, int ac);
char	**split_join(char **av, int ac);
void	error(char *s, int fd, int ex);
void	is_sorted(int *arr, int size);
void 	already_there(int *arr, int size);
void	push_swap(int *arr, int size);
void	sort_three(t_list **a, t_list **b, int size);
void	ft_swap(t_list **stack);
void	ft_push(t_list **stack1, t_list **stack2);
void	ft_rotate(t_list **stack);
void	ft_reverse(t_list **stack);
int		max_list(t_list *stack);
int		min_list(t_list	*stack);
int get_index(t_list *stack, int start_value , int end_value );
void	sort_three(t_list **a, t_list **b, int size);
void	sort_five(t_list **a, t_list **b, int size);
void	sort_100(t_list **a, t_list **b, int size, int *arr);
void	sort_tab(int *arr, int size);
int	lstsize(t_list *lst);
int	get_index_list(int max, t_list *a);

#	endif