/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:41:39 by gloms             #+#    #+#             */
/*   Updated: 2024/07/20 19:30:31 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	define_tile_size(t_display *display)
{
	if (longest_line(display->m->minimap_array) > \
		count_lines(display->m->minimap_array))
		display->m->tile_size = (WIDTH * 0.2)
			/ longest_line(display->m->minimap_array);
	else
		display->m->tile_size = (HEIGHT * 0.2)
			/ count_lines(display->m->minimap_array);
}

void	remove_player(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'S' || map[i][j] == 'N' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				map[i][j] = '0';
			j++;
		}
		i++;
	}
}

bool	map_filled(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

t_vec	get_first_0_pos(char **map)
{
	t_vec	pos;

	pos.x = 0;
	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == '0')
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	return (pos);
}

int	main(int ac, char **av)
{
	t_display	*display;
	t_mem_alloc	*mylloc;
	char		**ffmap;

	if (ac != 2)
		free_and_exit(NULL, "ERROR : Wrong number of arguments");
	mylloc = malloc(sizeof(t_mem_alloc));
	mylloc->next = NULL;
	mylloc->content = NULL;
	display = mem_alloc(mylloc, sizeof(t_display));
	init_game(display, mylloc);
	read_parse_store(av[1], mylloc, display);
	define_tile_size(display);
	print_minimap(display, display->m, display->m->tile_size, mylloc);
	ffmap = copy_tab(display->m->minimap_array, mylloc);
	remove_player(ffmap);
	new_flood_fill(ffmap, display->m->p_x, display->m->p_y, mylloc);
	init_text(display);
	init_text_to_img(display);
	run_raycast(display, display->raycast->ray, display->raycast->player);
	image_to_window(display);
	mlx_loop_hook(display->mlx, &player_angle, display);
	mlx_loop(display->mlx);
	free_and_exit(mylloc, NULL);
}
