/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:13:45 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/06 12:28:08 by kkouaz           ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	size_t				i;
	unsigned const char	*a1;
	unsigned const char	*a2;

	if (!s1)
		return (-1);
	a1 = (unsigned const char *)s1;
	a2 = (unsigned const char *)s2;
	i = 0;
	while ((a1[i] != '\0' || a2[i] != '\0'))
	{
		if (a1[i] != a2[i])
			return (1);
		i++;
	}
	return (0);
}

void	free_list(t_list *stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	while (stack->next != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	free(stack);
}
