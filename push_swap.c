/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:13:25 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/01 00:34:21 by kkouaz           ###   ########.fr       */
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
	while(i < size)
	{
		ft_lstadd_back(&a, ft_lstnew(arr[i]));
		i++;
	}
	
	// if (size == 4)
	// 	sort_three(&a, &b, size);
	// if (size <= 5)
	// 	sort_five(&a, &b, size);
	if (size <= 500)
		sort_100(&a, &b, size, arr);
}

void	sort_three(t_list **a, t_list **b, int size)
{
	t_list	*stack;
	t_list	*last;
	last = ft_lstlast(*a);
	
	 b = NULL;
	stack = *a;
	
	if (size <= 3)
	{
		if(stack->content <stack->next->content && stack->next->content <last->content)
			return;
		if(stack->content < stack->next->content)
		{
			if(stack->content < last->content )
			{
				reverse_a(a);
				swap_a(a);
			}
			else
				reverse_a(a);
		}
		else if (stack->content > stack->next->content )
		{
			if (stack->content < last->content)
				swap_a(a);
			else if (stack->next->content < last->content)
				rotate_a(a);
			else if (stack->content > stack->next->content)
			{
				rotate_a(a);
				swap_a(a);
			}
		}
	}
	
}
int	max_list(t_list *stack)
{
	int	max;

	max = stack->content;
	while(stack)
	{
		if(stack->content > max)
		{
			max = stack->content;
		}
		else
		stack = stack->next;
	}
	return(max);
}

int	min_list(t_list	*stack)
{
	int	min;
	
	min = stack->content;
	 while (stack)
	 {
		if(stack->content < min)
			min = stack->content;
		stack = stack->next;
	 }
	 return(min);
}

int get_index(t_list *stack, int start_value , int end_value )
{
	int i;

	i = 0;
	while(stack)
	{
		if((stack)->content >= start_value && (stack)->content <= end_value)
			return(i);
		i++;
		stack = (stack)->next;
	}
	return (-1);
}

// void    sort_five(t_list **a, t_list **b, int size)
// {
// 	int min;
// 	int index;
	
// 	min = min_list(*a);
// 	if(size <=500)
// 	{
// 		while (size != 3)
// 		{
// 			min = min_list(*a);
// 			index = get_index(*a, min);
// 			if(index == 0)
// 			{
// 				push_b(a , b);
// 				size--;
// 			}
// 			else if (index >= size/2)
// 				reverse_a(a);
// 			else if (index < size/2)
// 				rotate_a(a);
// 		}
// 		sort_three(a, b, 3);
// 		while (*b)
// 			push_a(a, b);
// 		//print_list(*a);
// 	}
// }

void	sort_tab(int *arr, int size)
{
	int	i;
	int	tmp;

	i = 0;

	while(i < size - 1)
	{
		if(arr[i] > arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
		
	}
}