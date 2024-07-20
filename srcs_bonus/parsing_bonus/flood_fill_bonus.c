/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:41:49 by gloms             #+#    #+#             */
/*   Updated: 2024/07/20 17:36:28 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_around(char **map, int x, int y)
{
	if (y > 0 && x <= ft_strlen(map[y - 1]) && !is_valid_char(map[y - 1][x]))
		return (0);
	else if (y < count_lines(map) && x <= ft_strlen(map[y + 1])
		&& !is_valid_char(map[y + 1][x]))
		return (0);
	else if (x > 0 && !is_valid_char(map[y][x - 1]))
		return (0);
	else if (!is_valid_char(map[y][x + 1]))
		return (0);
	else if (map[y][x] == '0' && y > 0 && x > ft_strlen(map[y - 1]))
		return (0);
	else if (map[y][x] == '0' && y < count_lines(map) && x > ft_strlen(map[y
			+ 1]))
		return (0);
	else if (map[y][x] == '0' && x == 0)
		return (0);
	else if (map[y][x] == '0' && y == 0)
		return (0);
	else
		return (1);
}

int	flood_fill(char **map, int x, int y)
{
	int	i;

	i = 0;
	if (!check_around(map, x, y))
		i += 1;
	if (is_valid_char(map[y][x]))
		map[y][x] = 'x';
	if (y > 0 && x <= ft_strlen(map[y - 1]) && map[y - 1][x] == '0')
		i += flood_fill(map, x, y - 1);
	if (y < count_lines(map) && x <= ft_strlen(map[y + 1]) && map[y
			+ 1][x] == '0')
		i += flood_fill(map, x, y + 1);
	if (x > 0 && map[y][x - 1] == '0')
		i += flood_fill(map, x - 1, y);
	if (map[y][x + 1] == '0')
		i += flood_fill(map, x + 1, y);
	return (i);
}
