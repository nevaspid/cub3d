/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:29:08 by gloms             #+#    #+#             */
/*   Updated: 2024/03/08 18:00:08 by gloms            ###   ########.fr       */
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

int	search_str(char *str, char *substr)
{
    int	i;
    int	j;

    i = 0;
    while (str[i])
    {
        j = 0;
        while (substr[j] == str[i + j])
        {
            if (substr[j + 1] == '\0')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
