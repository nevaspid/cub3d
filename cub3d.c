/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:41:39 by gloms             #+#    #+#             */
/*   Updated: 2024/06/08 07:13:02 by oliove           ###   ########.fr       */
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
	init_malloc(mylloc, display);
	init_mlx(display);
	read_parse_store(av[1], mylloc, display);
	if (longest_line(display->m->minimap_array) > count_lines(display->m->minimap_array))
		tile_size = (WIDTH * SCALE) / longest_line(display->m->minimap_array);
	else
		tile_size = (HEIGHT * SCALE) / count_lines(display->m->minimap_array);
		
	print_minimap(display, display->m, tile_size);
	init_value_st(display);
	draw_compass(display, display->raycast->compass, display->raycast->player);
	init_struct_camera(display->raycast->camera);
	// init_camera(display, display->raycast->camera);
	display->m->tile_size = tile_size;
	if (flood_fill(display->m->copy, display->m->p_x, display->m->p_y) > 0)
	{
		printf("ERROR : Map is not closed\n");
		free_and_exit(mylloc);
	}
	run_raycast(display,display->raycast->ray, display->raycast->player);
	// display->img->instances->z = 1;
	// display->m->minimap->instances->z = 0;
	
	// display->raycast->ray->img->instances->z = 3;
	
	// mlx_key_hook(display->mlx, &move_player, display);
	mlx_loop_hook(display->mlx, &player_angle, display);
	mlx_loop(display->mlx);
	free_and_exit(mylloc);
}
