/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:29:08 by gloms             #+#    #+#             */
/*   Updated: 2024/07/12 23:33:38 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	longest_line(char **array)
{
	int	i;
	int	length;
	int	max_length;

	i = 0;
	max_length = 0;
	if (!array)
		return (0);
	while (array && array[i])
	{
		length = ft_strlen(array[i]);
		if (length > max_length)
			max_length = length;
		i++;
	}
	return (max_length);
}

int	count_lines(char **array)
{
	int	count;

	count = 0;
	while (array[count] != NULL)
		count++;
	return (count);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strdup(char *s1, t_mem_alloc *lst)
{
	char	*str;
	int		i;

	i = 0;
	str = mem_alloc(lst, sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
