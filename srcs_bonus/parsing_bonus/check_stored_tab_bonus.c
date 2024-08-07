/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stored_tab_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:49:34 by gloms             #+#    #+#             */
/*   Updated: 2024/07/20 17:05:48 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_tab(t_display *d, t_mem_alloc *malloc)
{
	store_paths(d->m->file, d->m->paths, malloc);
	store_minimap(d->m->file, d->m, malloc);
	store_tab(d->m->file, d->m, malloc);
	search_player(d->m->copy, &d->m->ff_px, &d->m->ff_py);
	printf("Player position : %d %d\n", d->m->ff_px, d->m->ff_py);
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

void    store_minimap(char **file, t_minimap *m, t_mem_alloc *malloc)
{
    int    i;
    int    j;
    int    map_height;

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
        free_and_exit(malloc, "Error\nInvalid map\n");
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
