/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:44:31 by oliove            #+#    #+#             */
/*   Updated: 2024/06/23 21:28:42 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void image_to_window(t_display *display, mlx_image_t *img, int x, int y)
{
	mlx_image_to_window(display->mlx, display->img, 0, 0);
	mlx_image_to_window(display->mlx, display->raycast->compass->img, WIDTH /2,0);
	mlx_image_to_window(display->mlx, display->m->minimap, 0, 0);
	mlx_image_to_window(display->mlx,display->m->player, display->m->p_x * display->m->tile_size, display->m->p_y * display->m->tile_size); 
	mlx_image_to_window(display->mlx, display->raycast->ray->img,0,0);
}

void arry_nb(t_display *display)// nom a changer mais pas d'idee
{
    if (longest_line(display->m->minimap_array) > count_lines(display->m->minimap_array))
		display->m->tile_size = (WIDTH * SCALE) / longest_line(display->m->minimap_array);
	else
		display->m->tile_size = (HEIGHT * SCALE) / count_lines(display->m->minimap_array);
}


void game_loop(t_display *display, t_mem_alloc *mylloc)
{
    init_game(display,mylloc);
    while (1)
    {
        update_game(display);
        draw_game(display);
        image_to_window(display, display->img, 0, 0);
    }
}

void init_game(t_display *display, t_mem_alloc *mylloc)
{
    
    init_malloc(mylloc, display);
    init_mlx(display);
    // arry_nb(display);
    init_value_st(display);
    
}

void update_game(t_display *display)
{
    
}

void draw_game(t_display *display)
{
    clear_image(display->raycast->ray->img, 0x000000);
    clear_image(display->img, 0x000000);
    draw_bg(display, display->img);
}