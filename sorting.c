/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 02:30:11 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/04 04:46:43 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_100(t_list **a, t_list **b, int size, int *arr)
{
	t_ok	data;

	data.bottom = 0;
	data.size = size;
	data.mid = ((data.size - 1) / 2);
	data.offset = data.size / 8;
	data.start = data.mid - data.offset;
	data.end = data.mid + data.offset;
	data.lsize = lstsize(*a);
	while (*a)
	{
		push_to_b(a, b, arr, &data);
	}
	data.end = size - 1;
	while (*b)
	{
		data.max = arr[data.end];
		data.index = get_index_list(data.max, *b);
		push_back_to_a(a, b, &data);
	}
	while (data.bottom)
	{
		reverse_a(a);
		data.bottom--;
	}
}

int	get_index_list(int max, t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->content == max)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

void	sort_500(t_list **a, t_list **b, int size, int *arr)
{
	t_ok	data;

	data.bottom = 0;
	data.size = size;
	data.mid = ((data.size - 1) / 2);
	data.offset = data.size / 18;
	data.start = data.mid - data.offset;
	data.end = data.mid + data.offset;
	data.lsize = lstsize(*a);
	while (*a)
	{
		push_to_b(a, b, arr, &data);
	}
	data.end = size - 1;
	while (*b)
	{
			data.max = arr[data.end];
			data.index = get_index_list(data.max, *b);
		push_back_to_a(a, b, &data);
	}
	while (data.bottom)
	{
		reverse_a(a);
		data.bottom--;
	}
}

void	push_to_b(t_list **a, t_list **b, int *arr, t_ok *data)
{
	data->index = get_index(*a, arr[data->start], arr[data->end]);
	if (data->index == -1)
	{
		data->start -= data->offset;
		data->end += data->offset;
		if (data->start < 0)
			data->start = 0;
		if (data->end >= data->size)
			data->end = data->size - 1;
	}
	else
	{
		data->lsize = lstsize(*a);
		data->i = 0;
		if (data->index <= data->lsize / 2)
			while (data->i++ < data->index)
				rotate_a(a);
		else if (data->index > data->lsize / 2)
			while (data->i++ < data->lsize - data->index)
				reverse_a(a);
		push_b(a, b);
		if ((*b)->content < data->mid)
			rotate_b(b);
	}
}

void	push_back_to_a(t_list **a, t_list **b, t_ok *data)
{
	data->size = lstsize(*b);
	if ((*b)->content == data->max)
	{
		push_a(a, b);
		data->end--;
	}
	else if (data->index == -1)
	{
		reverse_a(a);
		data->end--;
		data->bottom--;
	}
	else if (!data->bottom || (*b)->content > ft_lstlast(*a)->content)
	{
		push_a(a, b);
		rotate_a(a);
		data->bottom++;
	}
	else
	{
		if (data->index <= data->size / 2)
			rotate_b(b);
		else
			reverse_b(b);
	}
}
