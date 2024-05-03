/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stored_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:49:34 by gloms             #+#    #+#             */
/*   Updated: 2024/05/03 17:07:52 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_tab(t_display *d, t_mem_alloc *malloc)
{
	store_paths(d->m->file, d->m->paths, malloc);
	store_minimap(d->m->file, d->m, malloc);
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

#include <string.h>
void	store_minimap(char **file, t_minimap *m, t_mem_alloc *malloc)
{
	int i;
	int	j;
	int	map_height;

	map_height = 0;
	j = 0;
	i = go_to_endof_file(file);
	while (is_empty_line(file[i]))
		i--;
	while (i >= 0 && !is_empty_line(file[i]))
	{
		map_height++;
		i--;
	}
	if (i < 0)
		i = 0;
	m->minimap_array = mem_alloc(malloc, sizeof(char *) * (map_height + 1));
	m->minimap_array[map_height] = NULL;
	while (file[i] && !is_empty_line(file[i]))
	{
		m->minimap_array[j] = ft_substr(file[i], 0, ft_strlen(file[i]), malloc);
		i++;
		j++;
	}
}
