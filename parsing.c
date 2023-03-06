/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:42:21 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/06 23:01:04 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "string.h"

char	**split_join(char **av, int ac)
{
	t_data	data;
	char	*leak_save1;

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
	check_errors(data.joined);
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
	if (size == 1 || size == 0)
		return ;
	while (i < size - 1)
	{
		i++;
		if (arr[i - 1] > arr[i])
			return ;
	}
	exit(0);
}

void	already_there(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				error("error!", 2, 1);
			j++;
		}
		i++;
	}
}

void	check_errors(char *joined)
{
	int	i;

	i = 0;
	while (joined[i])
	{
		while (joined[i] == ' '
			|| (joined[i] >= 9 && joined[i] <= 13))
					i++;
		if ((joined[i + 1] == '+' || joined[i + 1] == '-')
			&& (ft_isdigit(joined[i])))
			error("error!", 2, 1);
		if (joined[i] == '+' || joined[i] == '-')
			i++;
		if (!ft_isdigit(joined[i]) && joined[i] != ' ' && joined[i] != 0)
			error("error!", 2, 1);
		i++;
	}
}
