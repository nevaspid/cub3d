/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:41:39 by gloms             #+#    #+#             */
/*   Updated: 2024/06/16 22:03:41 by oliove           ###   ########.fr       */
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
		
	print_minimap(display, display->m, tile_size, mylloc);
	init_value_st(display);
	draw_compass(display, display->raycast->compass, display->raycast->player);
	init_struct_camera(display->raycast->camera);
	display->m->tile_size = tile_size;
	if (flood_fill(display->m->copy, display->m->p_x, display->m->p_y) > 0)
	{
		printf("ERROR : Map is not closed\n");
		free_and_exit(mylloc);
	}
	run_raycast(display,display->raycast->ray, display->raycast->player);	
	// a mettre dans une fonction
	mlx_image_to_window(display->mlx, display->img, 0, 0);
	mlx_image_to_window(display->mlx, display->raycast->compass->img, WIDTH /2,0);
	mlx_image_to_window(display->mlx, display->m->minimap, 0, 0);
	mlx_image_to_window(display->mlx,display->m->player, display->m->p_x * tile_size, display->m->p_y * tile_size); 
	mlx_image_to_window(display->mlx, display->raycast->ray->img,0,0);
	mlx_loop_hook(display->mlx, &player_angle, display);
	
	// --mlx_texture_to_image(display->mlx, display->raycast->asset->img_wall_east);
	// load_asset(display, display->raycast->assets, "srcs/assets/portal/Space_Background/Nebula Aqua-Pink.png");
	// mlx_image_to_window(display->mlx, display->raycast->assets->ceiling, 0, 0);
	// printf("ceiling [%hhn]\n", display->raycast->assets->ceiling->pixels);
	// mlx_mouse_hook(display->mlx, &mouse_hook, display);







	////////////////////////////test///////////////////////////////
	// init_mouse(display,display->raycast->mouse);







	
	mlx_loop(display->mlx);
	// a mettre dans une fonction

    // mlx_delete_texture(display->raycast->asset->img_wall_east);  
	// mlx_delete_texture(display->raycast->asset->wall_east);
	// mlx_delete_texture(display->raycast->asset->wall_north);
	// mlx_delete_texture(display->raycast->asset->wall_south);
	// mlx_delete_texture(display->raycast->asset->wall_west);
	
	
	// mlx_delete_texture(display->raycast->assets->img);
	free_and_exit(mylloc);
}
