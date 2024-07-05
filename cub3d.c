/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:41:39 by gloms             #+#    #+#             */
/*   Updated: 2024/07/05 02:05:01 by oliove           ###   ########.fr       */
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
	const char* filenames[] = {"portal/tile000.png", "portal/tile001.png", "portal/tile002.png"};
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
	display->raycast->anim->frames = malloc(3 * sizeof(mlx_image_t));
	init_text(display);
	init_text_to_img(display);
	run_raycast(display,display->raycast->ray, display->raycast->player);
	load_text_animation(display->mlx, display->raycast->anim, filenames, 3);
	image_to_window(display);
	mlx_loop_hook(display->mlx, &player_angle, display);
	// mlx_key_hook(display->mlx, &move_player, display);
	mlx_loop(display->mlx);

	free(display->raycast->anim->frames);// a deplacer plus tard
	free_and_exit(mylloc);
}




