/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:29:08 by gloms             #+#    #+#             */
/*   Updated: 2024/05/03 18:52:07 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

int	longest_line(char **array)
{
    int		i;
    int		length;
    int		max_length;

    i = 0;
    max_length = 0;
	if (!array)
		return (0);
    while (array[i])
    {
        length = ft_strlen(array[i]);
        if (length > max_length)
            max_length = length;
        i++;
    }
    return (max_length);
}

int count_lines(char **array)
{
    int count = 0;
    while (array[count] != NULL)
        count++;
    return count;
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
