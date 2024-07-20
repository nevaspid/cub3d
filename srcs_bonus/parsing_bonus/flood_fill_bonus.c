/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:41:49 by gloms             #+#    #+#             */
/*   Updated: 2024/07/20 19:29:46 by oliove           ###   ########.fr       */
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

bool	flood_fill(char **map, int x, int y, t_mem_alloc *myalloc)
{
	if (y < 0 || y > count_lines(map) || x < 0 || x >= ft_strlen(map[y]))
		free_and_exit(myalloc, "ERROR : map is not closed");
	if (map[y][x] == ' ' || map[y][x] == '0')
		map[y][x] = 'f';
	else if (map[y][x] == '1' || map[y][x] == 'f')
		return (false);
	return (flood_fill(map, x, y - 1, myalloc) || flood_fill(map, x, y + 1,
			myalloc) || flood_fill(map, x - 1, y, myalloc) || flood_fill(map, x
			+ 1, y, myalloc));
}

int	flood_fill_2(char **map, int x, int y)
{
	int	i;

	i = 0;
	if (!check_around(map, x, y))
		i += 1;
	if (is_valid_char(map[y][x]))
		map[y][x] = 'x';
	if (y > 0 && x <= ft_strlen(map[y - 1]) && map[y - 1][x] == '0')
		i += flood_fill_2(map, x, y - 1);
	if (y < count_lines(map) && x <= ft_strlen(map[y + 1]) && \
		map[y + 1][x] == '0')
		i += flood_fill_2(map, x, y + 1);
	if (x > 0 && map[y][x - 1] == '0')
		i += flood_fill_2(map, x - 1, y);
	if (map[y][x + 1] == '0')
		i += flood_fill_2(map, x + 1, y);
	return (i);
}

void	new_flood_fill(char **map, int x, int y, t_mem_alloc *myalloc)
{
	t_vec	newpos;

	newpos = (t_vec){x, y};
	while (1)
	{
		flood_fill(map, newpos.x, newpos.y, myalloc);
		if (map_filled(map))
			break ;
		newpos = get_first_0_pos(map);
	}
}
