/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 06:59:07 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/05 15:48:20 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

#include "push_swap.h"
#include "get_next_line/get_next_line.h"
int   check_order(t_list **stack);
void	errors_check(char **av, int ac);
void	ft_check(t_list *a, t_list *b,int size);
void	myfree(char **arg);

#	endif
