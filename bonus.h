/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 06:59:07 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/06 21:32:28 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "push_swap.h"
# include "get_next_line/get_next_line.h"

typedef struct t_norm
{
	int		i;
	int		j;
	int		*numbers;
	char	**splited;
	t_list	*a;
	t_list	*b;

}t_norm;

int		check_order(t_list *stack);
void	checker(char **av, int ac);
void	ft_check(t_list **a, t_list **b, int size);
void	myfree(char **arg);
void	swap_both(t_list **a, t_list **b);
void	rotate_both(t_list **a, t_list **b);
void	reverse_both(t_list **a, t_list **b);
void	actions(t_list **a, t_list **b, char *line);
void	free_all(int *arr, char **s1, t_list **a, t_list **b);

#	endif
