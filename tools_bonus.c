/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:09:59 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/06 00:53:39 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include "push_swap.h"

void	swap_both(t_list **a, t_list **b)
{
	ft_swap(a);
	ft_swap(b);
}

void	rotate_both(t_list **a, t_list **b)
{
	ft_rotate(a);
	ft_rotate(b);
}

void	reverse_both(t_list **a, t_list **b)
{
	ft_reverse(a);
	ft_reverse(b);
}
