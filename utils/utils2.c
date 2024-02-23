/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:29:08 by gloms             #+#    #+#             */
/*   Updated: 2024/02/23 16:37:20 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
