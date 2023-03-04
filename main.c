/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:30:15 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/04 04:47:30 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_list(t_list *stack)
{
	int	max;

	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
		}
		else
		stack = stack->next;
	}
	return (max);
}

int	min_list(t_list	*stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

void	magic(char **av, int ac)
{
	int		i;
	int		*numbers;
	char	**splited;

	i = 0;
	splited = split_join(av, ac);
	while (splited[i])
		i++;
	numbers = malloc(i * sizeof(int));
	i = 0;
	while (splited[i])
	{
		numbers[i] = ft_atoi(splited[i]);
		i++;
	}
	already_there(numbers, i);
	is_sorted(numbers, i);
	push_swap(numbers, i);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		exit(1);
	if (!*av[1])
		error("error!", 1, 1);
	while (i < ac)
	{
		if (!*av[i])
			error("error!", 1, 1);
		i++;
	}
	if (ac >= 2)
		magic(av, ac);
}
