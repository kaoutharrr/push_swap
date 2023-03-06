/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:13:25 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/06 11:52:51 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *arr, int size)
{
	t_list	*a;
	t_list	*b;
	int		i;

	i = 0;
	b = NULL;
	a = NULL;
	while (i < size)
	{
		ft_lstadd_back(&a, ft_lstnew(arr[i]));
		i++;
	}
	sort_tab(arr, i);
	if (size == 2)
		sort_two(&a);
	else if (size <= 3)
		sort_three(&a);
	else if (size <= 50)
		sort_five(&a, &b, size);
	else if (size <= 100)
		sort_100(&a, &b, size, arr);
	else if (size <= 500)
		sort_500(&a, &b, size, arr);
	free(arr);
	free_list(a);
}

void	sort_two(t_list **a)
{
	if ((*a)->content > (*a)->next->content)
		swap_a(a);
	else
		return ;
}

void	sort_three(t_list **a)
{
	if ((*a)->content < (*a)->next->content
		&& (*a)->next->content < ft_lstlast(*a)->content)
		return ;
	if ((*a)->content < (*a)->next->content)
	{
		if ((*a)->content < ft_lstlast(*a)->content)
		{
			reverse_a(a);
			swap_a(a);
		}
		else
			reverse_a(a);
	}
	else if ((*a)->content > (*a)->next->content)
	{
		if ((*a)->content < ft_lstlast(*a)->content)
			swap_a(a);
		else if ((*a)->next->content < ft_lstlast(*a)->content)
			rotate_a(a);
		else if ((*a)->content > (*a)->next->content)
		{
			rotate_a(a);
			swap_a(a);
		}
	}
}

int	get_index(t_list *stack, int start_value, int end_value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if ((stack)->content >= start_value && (stack)->content <= end_value)
			return (i);
		stack = (stack)->next;
		i++;
	}
	return (-1);
}

void	sort_five(t_list **a, t_list **b, int size)
{
	int	min;
	int	index;

	min = min_list(*a);
	if (size <= 500)
	{
		while (size != 3)
		{
			min = min_list(*a);
			index = get_index_list(min, *a);
			if (index == 0)
			{
				push_b(a, b);
				size--;
			}
			else if (index >= size / 2)
				reverse_a(a);
			else if (index < size / 2)
				rotate_a(a);
		}
		sort_three(a);
		while (*b)
			push_a(a, b);
	}
}
