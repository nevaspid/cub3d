/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:41:09 by gloms             #+#    #+#             */
/*   Updated: 2024/05/21 14:45:51 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_assets(t_display *mlx, int tile_size, int x, int y)
{
	if (mlx->m->minimap_array[y][x] == '1')
		wall(mlx->m, x * tile_size, y * tile_size, tile_size);
	else if (mlx->m->minimap_array[y][x] == '0')
		floors(mlx->m, x * tile_size, y * tile_size, tile_size);
	else if (is_char(mlx->m->minimap_array[y][x], mlx->m))
	{
		mlx->m->p_y = y;
		mlx->m->p_x = x;
		mlx->m->player = mlx_new_image(mlx->mlx, tile_size / 2, tile_size / 2);
	}
}

void	print_minimap(t_display *mlx, t_minimap *minimap, int tile_size)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (minimap->minimap_array[y])
	{
		while (minimap->minimap_array[y][x])
		{
			print_assets(mlx, tile_size, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	print_player(mlx, minimap, tile_size);
}
