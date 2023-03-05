/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:15:36 by kkouaz            #+#    #+#             */
/*   Updated: 2023/01/24 02:46:47 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr( char *s, int c)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen_gnl(s);
	if (!s)
		return (NULL);
	while (i < size)
	{
		if (s[i] == c)
			return ((s + i));
		else
			i++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*stj;
	int		i;
	int		j;

i = 0;
	j = ft_strlen_gnl(s1);
	stj = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
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
	free(s1);
	return (stj);
}
