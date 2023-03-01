/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:38:16 by kkouaz            #+#    #+#             */
/*   Updated: 2023/02/27 01:49:47 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **a, t_list **b)
{
	ft_push(b, a);
	write(1, "pa\n", 3);
}

void	push_b(t_list **a, t_list **b)
{
	ft_push(a, b);
	write(1, "pb\n", 3);
}

void	rotate_a(t_list **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}


void	rotate_b(t_list **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void reverse_a(t_list **a)
{
	ft_reverse(a);
	write(1, "rra\n", 4);
}
void reverse_b(t_list **b)
{
	ft_reverse(b);
	write(1, "rrb\n", 4);
}

void	swap_a(t_list **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	swap_b(t_list **b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}