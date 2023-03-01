/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:30:15 by kkouaz            #+#    #+#             */
/*   Updated: 2023/02/28 18:51:27 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	magic(char **av, int ac)
{
	int			i;
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

int main(int ac, char **av)
{
	int	i;

	i = 1;
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