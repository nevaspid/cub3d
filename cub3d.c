/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:41:39 by gloms             #+#    #+#             */
/*   Updated: 2024/06/25 14:11:50 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void define_tile_size(t_display *display)
{
	if (longest_line(display->m->minimap_array) > count_lines(display->m->minimap_array))
		display->m->tile_size = (WIDTH * SCALE) / longest_line(display->m->minimap_array);
	else
		display->m->tile_size = (HEIGHT * SCALE) / count_lines(display->m->minimap_array);
}

int	main(int ac, char **av)
{
	t_display	*display;
	t_mem_alloc	*mylloc;
	// int			tile_size;

	if (ac != 2)
	{
		printf("ERROR : Wrong number of arguments\n");
		exit(0);
	}
	mylloc = malloc(sizeof(t_mem_alloc));
	mylloc->next = NULL;
	mylloc->content = NULL;
	display = mem_alloc(mylloc, sizeof(t_display));
	init_game(display, mylloc);
	read_parse_store(av[1], mylloc, display);
	define_tile_size(display);
	print_minimap(display, display->m, display->m->tile_size, mylloc);
	if (flood_fill(display->m->copy, display->m->p_x, display->m->p_y) > 0)
	{
		printf("ERROR : Map is not closed\n");
		free_and_exit(mylloc);
	}

	run_raycast(display,display->raycast->ray, display->raycast->player);
	image_to_window(display);
	mlx_loop_hook(display->mlx, &player_angle, display);
	mlx_loop(display->mlx);
	free_and_exit(mylloc);
}

