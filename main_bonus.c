/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 03:23:58 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/05 11:49:37 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "bonus.h"

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
int main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		exit(1);
	if (!*av[1])
		error("error!", 2, 1);
	while (i < ac)
	{
		if (!*av[i] || !ft_strcmp(av[i], " "))
			error("error!", 2, 1);
		i++;
	}
	if (ac >= 2)
		errors_check(av, ac);
	
}
