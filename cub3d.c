/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:41:39 by gloms             #+#    #+#             */
/*   Updated: 2024/05/30 19:35:54 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_display	*display;
	t_mem_alloc	*mylloc;
	int			tile_size;

	if (ac != 2)
	{
		printf("ERROR : Wrong number of arguments\n");
		exit(0);
	}
	mylloc = malloc(sizeof(t_mem_alloc));
	mylloc->next = NULL;
	mylloc->content = NULL;
	display = mem_alloc(mylloc, sizeof(t_display));
	display->m = mem_alloc(mylloc, sizeof(t_minimap));
	display->m->paths = mem_alloc(mylloc, sizeof(t_paths));
	display->raycast = mem_alloc(mylloc, sizeof(t_raycast));
	display->raycast->compass = mem_alloc(mylloc, sizeof(t_compass));
	display->raycast->player = mem_alloc(mylloc,sizeof(t_player));
	display->raycast->ray = mem_alloc(mylloc,sizeof(t_ray));
	display->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	display->m->minimap = mlx_new_image(display->mlx, WIDTH * SCALE, HEIGHT * SCALE);
	display->raycast->compass->img = mlx_new_image(display->mlx, WIDTH * SCALE, HEIGHT * SCALE);
	display->raycast->ray->img = mlx_new_image(display->mlx, WIDTH * SCALE, HEIGHT * SCALE);
	// display->m->player = mlx_new_image(display->mlx, SCALE, SCALE);
	read_parse_store(av[1], mylloc, display);
	if (longest_line(display->m->minimap_array) > count_lines(display->m->minimap_array))
		tile_size = (WIDTH * SCALE) / longest_line(display->m->minimap_array);
	else
		tile_size = (HEIGHT * SCALE) / count_lines(display->m->minimap_array);
	print_minimap(display, display->m, tile_size);
	draw_compass(display, display->raycast->compass, display->raycast->player);
	display->m->tile_size = tile_size;
	if (flood_fill(display->m->copy, display->m->p_x, display->m->p_y) > 0)
	{
		printf("ERROR : Map is not closed\n");
		free_and_exit(mylloc);
	}
	run_raycast(display,display->raycast->ray, display->raycast->player);
	mlx_loop_hook(display->mlx, move_player, display);
	mlx_loop_hook(display->mlx, player_angle, display);
	mlx_loop(display->mlx);
	free_and_exit(mylloc);
}
