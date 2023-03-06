/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:36:08 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/06 12:43:10 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen_a(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*stj;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen_a(s1);
	stj = malloc((ft_strlen_a(s1) + ft_strlen_a(s2) + 1));
	if (!stj)
		return (0);
	while (s1 && s1[i])
	{
		stj[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		stj[i + j] = s2[i];
		i++;
	}
	stj[i + j] = '\0';
	return (stj);
}

void	sort_tab(int *arr, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
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

int	is_sorted_list(t_list *list)
{
	if (!list || !list->next)
		return (0);
	while (list->next)
	{
		if (list->content > list->next->content)
			return (-1);
		list = list->next;
	}
	return (1);
}
