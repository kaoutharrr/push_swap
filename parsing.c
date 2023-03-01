/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:42:21 by kkouaz            #+#    #+#             */
/*   Updated: 2023/02/26 01:06:39 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_join(char **av, int ac)
{
	t_data	data;
	char *leak_save1;

	data.i = 1;
	data.splited = NULL;
	data.joined = ft_strdup(av[data.i]);
	while (data.i <= ac -2)
	{
		leak_save1 = data.joined;
		data.s = ft_strjoin(data.joined, " ");
		free(leak_save1);
		leak_save1 = data.s;
		data.joined = ft_strjoin(data.s, av[data.i + 1]);
		free(leak_save1);
		
		data.i++;
	}
	data.i = 0;
	while (data.joined[data.i])
	{
		while (data.joined[data.i] == ' ' || (data.joined[data.i] >= 9 && data.joined[data.i] <= 13))
				data.i++;
		if ((data.joined[data.i] == '+' ||  data.joined[data.i] == '-') && (ft_isdigit(data.joined[data.i-1])))
			error("error!", 1, 1);
		if (data.joined[data.i] == '+' ||  data.joined[data.i] == '-')
				data.i++;
		if (!ft_isdigit(data.joined[data.i]))
				error("error!", 1, 1);
			data.i++;
	}
	data.splited = ft_split(data.joined, ' ');
	free(data.joined);
	return (data.splited);
	}

void	error(char *s, int fd, int ex)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	exit (ex);
}
void	is_sorted(int *arr, int size)
{
	int	i;
	
	i = 0;
	if(size == 1 || size == 0)
			return;
	while(i < size - 1)
	{
		
		i++;
		
			
		if ( arr[i - 1] > arr[i])
			return;
		
	}
	//error("error!", 1, 1);
}
void 	already_there(int *arr, int size)
{
	int	i;
	int	j;
	
	
	i = 0;
	j = i + 1;

    while ( i < size ) 
	{
		j = i + 1;
        while ( j <  size)
		 {
            if (arr[i] == arr[j])
                error("error!", 1, 1);
            j++;
       	 }
		i++;
    }
}