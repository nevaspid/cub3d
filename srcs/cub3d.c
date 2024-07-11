/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:41:39 by gloms             #+#    #+#             */
/*   Updated: 2024/07/12 00:52:55 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	define_tile_size(t_display *display)
{
	if (longest_line(display->m->minimap_array) \
		> count_lines(display->m->minimap_array))
		display->m->tile_size = (WIDTH * SCALE)
			/ longest_line(display->m->minimap_array);
	else
		display->m->tile_size = (HEIGHT * SCALE)
			/ count_lines(display->m->minimap_array);
}

static void	prepa_text(t_display *display)
{
	init_text(display);
	init_text_to_img(display);
}

static void	other_norm(char **av, t_mem_alloc *mylloc, t_display *display)
{
	read_parse_store(av[1], mylloc, display);
	print_minimap(display, display->m, display->m->tile_size, mylloc);
	if (flood_fill(display->m->copy, display->m->p_x, display->m->p_y) > 0)
		free_and_exit(mylloc, "ERROR : Map is not closed\n");
	prepa_text(display);
	run_raycast(display, display->raycast->ray, display->raycast->player);
	image_to_window(display);
	mlx_loop_hook(display->mlx, &player_angle, display);
	mlx_loop(display->mlx);
	free_and_exit(mylloc, NULL);
}

int	main(int ac, char **av)
{
	t_display	*display;
	t_mem_alloc	*mylloc;

	if (ac != 2)
		free_and_exit(NULL, "ERROR : Wrong number of arguments\n");
	mylloc = malloc(sizeof(t_mem_alloc));
	mylloc->next = NULL;
	mylloc->content = NULL;
	display = mem_alloc(mylloc, sizeof(t_display));
	init_game(display, mylloc);
	other_norm(av, mylloc, display);
	free_and_exit(mylloc, NULL);
}
