/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 03:37:46 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/06 21:32:42 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include "push_swap.h"

int	check_order(t_list *stack)
{
	if (!stack)
		return (1);
	while ((stack)->next)
	{
		if ((stack)->content > (stack)->next->content)
			return (0);
		stack = (stack)->next;
	}
	return (1);
}

void	ft_check(t_list **a, t_list **b, int size)
{
	char	*line;

	line = "";
	while (line)
	{
		line = get_next_line(0);
		if (!line)
		{
			free(line);
			break ;
		}
		else
		{
			actions(a, b, line);
		}
		free(line);
	}
	free(line);
	if (check_order(*a) == 1 && lstsize(*a) == size)
		write(1, "OK\n", 3);
	else
	{
		write(1, "KO\n", 3);
	}
}

void	checker(char **av, int ac)
{	
	t_norm	norm;

	norm.b = NULL;
	norm.a = NULL;
	norm.i = 0;
	norm.j = 0;
	norm.splited = split_join(av, ac);
	while (norm.splited[norm.i] != NULL )
		norm.i++;
	norm.numbers = (int *) malloc(norm.i * sizeof(int));
	norm.i = 0;
	while (norm.splited[norm.i])
	{
		norm.numbers[norm.i] = ft_atoi(norm.splited[norm.i]);
		norm.i++;
	}
	already_there(norm.numbers, norm.i);
	while (norm.j < norm.i)
	{
		ft_lstadd_back(&norm.a, ft_lstnew(norm.numbers[norm.j]));
		norm.j++;
	}
	ft_check(&norm.a, &norm.b, norm.j);
	free_all(norm.numbers, norm.splited, &norm.a, &norm.b);
}

void	actions(t_list **a, t_list **b, char *line)
{
	if (ft_strcmp(line, "ra\n") == 0)
		ft_rotate(a);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_reverse(a);
	else if (ft_strcmp(line, "sa\n") == 0)
		ft_swap(a);
	else if (ft_strcmp(line, "pa\n") == 0)
		ft_push(b, a);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rotate(b);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_reverse(b);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_swap(b);
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_push(a, b);
	else if (ft_strcmp(line, "ss\n") == 0)
		swap_both(a, b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rotate_both(a, b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		reverse_both(a, b);
	else
		error("error!", 2, 1);
}
