/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:11:16 by gloms             #+#    #+#             */
/*   Updated: 2024/07/20 13:04:17 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(char *a, char *to_cmp)
{
	int	j;

	j = 0;
	while (*a)
	{
		if (*a == to_cmp[j])
		{
			while (*a == to_cmp[j])
			{
				a++;
				j++;
				if (to_cmp[j] == '\0')
					return (1);
			}
		}
		j = 0;
		a++;
	}
	return (0);
}

int	find_path_in_line(char *tab_line)
{
	int	path_start;

	path_start = 0;
	while (tab_line[path_start] != '.')
		path_start++;
	if (path_start == ft_strlen(tab_line))
		printf("ERROR : path is not referenced as following : ./PATH");
	return (path_start);
}

int	find_rgb_in_line(char *tab_line)
{
	int	path_start;

	path_start = 0;
	while (!is_digit(tab_line[path_start]))
		path_start++;
	if (path_start == ft_strlen(tab_line))
		printf("ERROR : RGB code is not referenced as following : R,G,B");
	return (path_start);
}

int	search_flag_in_tab(char *to_find, char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (ft_strcmp(tab[i], to_find) == 1)
			return (i);
	}
	return (-1);
}
