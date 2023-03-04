/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:13:45 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/04 04:47:50 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	reverse_b(t_list **b)
{
	ft_reverse(b);
	write(1, "rrb\n", 4);
}
