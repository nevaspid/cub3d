/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stored_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:49:34 by gloms             #+#    #+#             */
/*   Updated: 2024/05/15 16:51:37 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//-  cas à gérer :
//- si une ligne random est ajoutée dans le fichier ça fait planter la recuperation de la map

int	check_tab(t_display *d, t_mem_alloc *malloc)
{
	store_paths(d->m->file, d->m->paths, malloc);
	store_minimap(d->m->file, d->m, malloc);
	d->m->copy = copy_tab(d->m->minimap_array, malloc);
	return (1);
}

void	store_paths(char **file, t_paths *p, t_mem_alloc *m)
{
	p->NO = return_paths("NO ", file, m);
	p->SO = return_paths("SO ", file, m);
	p->WE = return_paths("WE ", file, m);
	p->EA = return_paths("EA ", file, m);
	p->F = return_rgb("F ", file, m);
	p->C = return_rgb("C ", file, m);
}

void	store_minimap(char **file, t_minimap *m, t_mem_alloc *malloc)
{
	int	i;
	int	j;
	int	map_height;

	i = 6;
	j = 0;
	map_height = go_to_endof_file(file) - 5;
	m->minimap_array = mem_alloc(malloc, sizeof(char *) * (map_height + 1));
	m->minimap_array[map_height] = NULL;
	while (file[i])
	{
		m->minimap_array[j] = ft_strdup(file[i], malloc);
		i++;
		j++;
	}
	if (check_map(m->minimap_array) == -1)
	{
		printf("Error\nInvalid map\n");
		exit(0); //! a free & exit
	}
}

int	check_map(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (!is_valid_char(map[j][i]))
				return (-1);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == 'x' || c == ' ')
		return (1);
	return (0);
}

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
