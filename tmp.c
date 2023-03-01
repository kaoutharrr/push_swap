int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	**splited;
	int		*numbers;

	i = 1;
	if (ac == 2)
	{
		if (!*av[1])
			error("error!", 1, 1);
	}
	while (i < ac)
	{
		if (!*av[i])
			error("error!", 1, 1);
		i++;
	}
	if (ac >= 2)
	{
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
		j = i;
		already_there(numbers, j);
		is_sorted(numbers, i);
		push_swap(numbers, i);
		
	sort_tab(numbers, i);
	j = 0 ;
	printf("\n%d\n" ,i);
	while(j <= i )
	{
		printf("<%d>", numbers[j]);
		j++;
	}
		
	}
}


int	get_index(t_list *a , int x)
{
	int i = 0;
	while (a)
	{
		if (a->content == x)
			return i;
		a = a->next;
		i++;	
	}
	return i;
}

void	sort_five(t_list **a, t_list **b, int size)
{
	 
	int	min;
	int index;

	min = min_list(*a);
	if(size <= 500)
	{
		while(size != 3)
		{
			min = min_list(*a);
			index = get_index(*a, min);
			//printf("data => %d | index : %d\n", min, index);
			if(index ==  0)
			{
				ft_push(a,b);
				write(1, "pb\n", 3);	 
				size--;
			}
			else if(index >= size / 2)
			{
				ft_reverse(a);
					write(1, "rra\n", 4);	 
			}
			else if(index < size / 2)
			{
				ft_rotate(a);
				write(1, "ra\n", 3);	 
			}
		}
		
		sort_three(a,b,3);
		
		while(*b)
		{
			ft_push(b,a);
			write(1, "pa\n", 3);
		}
		print_list(*a);
	}
}