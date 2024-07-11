/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:41:09 by gloms             #+#    #+#             */
/*   Updated: 2024/07/11 02:14:20 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_assets(t_display *mlx, int tile_size, int x, int y)
{
	if (mlx->m->minimap_array[y][x] == '1' ||
			mlx->m->minimap_array[y][x] == 'P')
		wall(mlx->m, x * tile_size, y * tile_size, tile_size);
	else if (mlx->m->minimap_array[y][x] == '0')
		floors(mlx->m, x * tile_size, y * tile_size, tile_size);
	else if (is_char(mlx->m->minimap_array[y][x], mlx))
	{
		mlx->m->p_y = y ;
		mlx->m->p_x = x ;
		mlx->p_y = y;
		mlx->p_x = x;
		mlx->m->player = mlx_new_image(mlx->mlx, tile_size / 2, tile_size / 2);
	}
}

void	print_minimap(t_display *mlx, t_minimap *min, int tz, t_mem_alloc *my)
{
	int	x;
	int	y;
	int	print_p;

	x = 0;
	y = 0;
	print_p = 0;
	define_tile_size(mlx);
	while (min->minimap_array[y])
	{
		while (min->minimap_array[y][x])
		{
			if (is_char(mlx->m->minimap_array[y][x], mlx))
				print_p++;
			if (print_p > 1)
			{
				printf("ERROR : more than one player on map");
				free_and_exit(my);
			}
			print_assets(mlx, tz, x++, y);
		}
		x = 0;
		y++;
	}
	print_player(mlx, min, tz);
}
