/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stored_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:49:34 by gloms             #+#    #+#             */
/*   Updated: 2024/07/20 13:41:18 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_tab(t_display *d, t_mem_alloc *malloc)
{
	store_paths(d->m->file, d->m->paths, malloc);
	store_minimap(d->m->file, d->m, malloc);
	d->m->copy = copy_tab(d->m->minimap_array, malloc);
	d->m->paths->split_c = ft_split(d->m->paths->c, ',', malloc);
	if (count_lines(d->m->paths->split_c) != 3)
	{
		printf("Error\nInvalid color\n");
		free_and_exit(malloc, NULL);
	}
	d->m->paths->split_f = ft_split(d->m->paths->f, ',', malloc);
	if (count_lines(d->m->paths->split_f) != 3)
	{
		printf("Error\nInvalid color\n");
		free_and_exit(malloc, NULL);
	}
	return (1);
}

void	store_paths(char **file, t_paths *p, t_mem_alloc *m)
{
	p->no = return_paths("NO ", file, m);
	p->so = return_paths("SO ", file, m);
	p->se = return_paths("WE ", file, m);
	p->ea = return_paths("EA ", file, m);
	p->f = return_rgb("F ", file, m);
	p->c = return_rgb("C ", file, m);
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
		free_and_exit(malloc, NULL);
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
		|| c == 'x' || c == ' ' || c == 'P')
		return (1);
	return (0);
}
