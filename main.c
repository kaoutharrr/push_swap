/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:30:15 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/06 22:57:54 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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

void	myfree(char **arg)
{
	int	i ;

	i = 0;
	if (!arg)
		return ;
	while (arg[i])
		free(arg[i++]);
	free(arg);
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
	numbers = (int *) malloc((i) * sizeof(int));
	i = 0;
	while (splited[i])
	{
		numbers[i] = ft_atoi(splited[i]);
		i++;
	}
	already_there(numbers, i);
	is_sorted(numbers, i);
	if (i == 1)
	{
		exit(0);
	}
	push_swap(numbers, i);
	myfree(splited);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		exit(0);
	if (!*av[1])
		error("error!", 2, 1);
	while (i < ac)
	{
		if (!*av[i] || !ft_strcmp(av[i], " "))
			error("error!", 2, 1);
		i++;
	}
	if (ac >= 2)
		magic(av, ac);
}
