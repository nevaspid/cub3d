/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:41:39 by gloms             #+#    #+#             */
/*   Updated: 2024/04/25 16:38:55 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_display	*display;
	t_mem_alloc	*mylloc;
	int			tile_size;

	(void)ac;

	mylloc = malloc(sizeof(t_mem_alloc));
	display = mem_alloc(mylloc, sizeof(t_display));
	display->m = mem_alloc(mylloc, sizeof(t_minimap));
	display->m->paths = mem_alloc(mylloc, sizeof(t_paths));
	display->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	display->m->minimap = mlx_new_image(display->mlx, WIDTH * 0.2, HEIGHT * 0.2);
	read_parse_store(av[1], mylloc, display); //! parsing part minimap n'est pas encore stored et checked pour l'instant
	if (longest_line(display->m->minimap_array) > count_lines(display->m->minimap_array))
		tile_size = (WIDTH * 0.2) / longest_line(display->m->minimap_array);
	else
		tile_size = (HEIGHT * 0.2) / count_lines(display->m->minimap_array);
	print_minimap(display, display->m, tile_size, tile_size);
	mlx_image_to_window(display->mlx, display->m->minimap, 0, 0);
	display->m->minimap->instances[0].z = 0;
	mlx_loop_hook(display->mlx, move_player, display);
	mlx_loop_hook(display->mlx, player_angle, display);
	mlx_loop(display->mlx);
}
