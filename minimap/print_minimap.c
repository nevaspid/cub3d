/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:41:09 by gloms             #+#    #+#             */
/*   Updated: 2024/02/26 21:15:19 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_minimap(t_display *mlx, t_minimap *minimap, int tile_width, int tile_height)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (minimap->minimap_array[y])
	{
		while (minimap->minimap_array[y][x])
		{
			if (minimap->minimap_array[y][x] == '1')
				wall(minimap, x * tile_width, y * tile_height, tile_width, tile_height);
			else if (minimap->minimap_array[y][x] == '0')
				floors(minimap, x * tile_width, y * tile_height, tile_width, tile_height);
			else if (is_char(minimap->minimap_array[y][x], minimap))
			{
				minimap->p_y = y;
				minimap->p_x = x;
				minimap->player = mlx_new_image(mlx->mlx, tile_width / 2, tile_height / 2);
			}
			x++;
		}
		x = 0;
		y++;
	}
	print_player(mlx, minimap, tile_width, tile_height);
}
