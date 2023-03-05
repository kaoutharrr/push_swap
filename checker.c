/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 03:37:46 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/05 15:57:15 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include "get_next_line/get_next_line.h"
#include "push_swap.h"
#include <sys/fcntl.h>

void	print_list(t_list *list)
{
	while(list)
	{
		printf("{%d} ", list->content);
		list = list->next;
	}
	printf("\n");
}

int	check_order(t_list **stack)
{
	while((*stack)->next)
	{
		if((*stack)->content > (*stack)->next->content)
			return(0);
		*stack  = (*stack)->next;
	}
	return(1);
}


void	ft_check(t_list *a, t_list *b,int size)
{
	char	*line;

	line = "" ;
	while(line)
	{
		line = get_next_line(0);
		if( !line)
		{
			free(line);
			break;
		}
		else if(ft_strcmp(line, "ra\n")== 0)
			ft_rotate(&a);
		else if(ft_strcmp(line, "rra\n")== 0)
			ft_reverse(&a);
		else if(ft_strcmp(line, "sa\n")== 0)
			ft_swap(&a);
		else if(ft_strcmp(line, "pa\n") == 0)
			ft_push(&b, &a);
		else if(ft_strcmp(line, "rb\n")==0)
			ft_rotate(&b);
		else if(ft_strcmp(line, "rrb\n")==0)
			ft_reverse(&b);
		else if(ft_strcmp(line, "sb\n")==0)
			ft_swap(&b);
		else if(ft_strcmp(line, "pb\n")==0)
			ft_push(&a, &b);

		else  
			error("error!", 2, 1);	
		free(line);
	}
	
	if (check_order(&a) == 1 &&  lstsize(a) == size + 1)
	{
		error("OK\n", 1, 1);
	}
	else if (check_order(&a) == 0 && lstsize(a) != size  + 1)
	{
	 	error("KO\n", 1, 1);
	}
}
	
void	errors_check(char **av, int ac)
{
	int		i;
	int		j;
	int		*numbers;
	char	**splited;
	t_list	*a;
	t_list  *b;

	b = NULL;
	//b->content = 0;
	a = NULL;
	i = 0;
	j = 0;
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
	
	while (j < i)
	{
		ft_lstadd_back(&a, ft_lstnew(numbers[j]));
		j++;
	}
	ft_check(a, b, j);
}