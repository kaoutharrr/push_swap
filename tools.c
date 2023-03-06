/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:37:25 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/06 12:13:36 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
{
	int	swap;

	if (lstsize(*stack) < 2)
		return ;
	swap = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = swap;
}

void	ft_push(t_list **stack1, t_list **stack2)
{
	t_list	*tmp;

	if (*stack1 == NULL )
		return ;
	tmp = (*stack1)->next;
	if (*stack2 == NULL)
	{
		(*stack1)->next = *stack2;
		(*stack2) = *stack1;
		*stack1 = tmp;
		(*stack2)->next = NULL;
	}
	else
		ft_lstadd_front(stack2, *stack1);
	*stack1 = tmp;
}

void	ft_rotate(t_list **stack)
{
	t_list	*tmp;

	if (lstsize(*stack) < 2)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = NULL;
	ft_lstadd_back(&tmp, *stack);
	*stack = tmp;
}

void	ft_reverse(t_list **stack)
{
	t_list	*last;
	t_list	*tmp;

	if (lstsize(*stack) < 2)
		return ;
	tmp = *stack;
	last = ft_lstlast(*stack);
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *stack;
	*stack = last;
}
