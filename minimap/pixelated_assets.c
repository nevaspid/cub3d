/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelated_assets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:13:32 by gloms             #+#    #+#             */
/*   Updated: 2024/05/30 00:26:35 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	wall(t_minimap *minimap, int x, int y, int tile_size)
{
	int	i;
	int	j;
	int	first_x;

	i = 0;
	j = 0;
	first_x = x;
	while (j < tile_size)
	{
		while (i < tile_size)
		{
			mlx_put_pixel(minimap->minimap, (uint32_t)x, (uint32_t)y, 255);
			i++;
			x++;
		}
		i = 0;
		x = first_x;
		j++;
		y++;
	}
}

void	floors(t_minimap *minimap, int x, int y, int tile_size)
{
	int	i;
	int	j;
	int	first_x;

	i = 0;
	j = 0;
	first_x = x;
	while (j < tile_size)
	{
		while (i < tile_size)
		{
			mlx_put_pixel(minimap->minimap, (uint32_t)x, (uint32_t)y,
				0xAAA000FF);
			i++;
			x++;
		}
		i = 0;
		x = first_x;
		j++;
		y++;
	}
}

void	draw_player(t_display *minimap, int tile_size)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < tile_size / 2)
	{
		while (x < tile_size / 2)
		{
			mlx_put_pixel(minimap->raycast->ray->img, (uint32_t)x, (uint32_t)y,
				0x8B0000FF);
			x++;
		}
		x -= tile_size / 2;
		y++;
	}
}

void	print_player(t_display *mlx, t_minimap *m, int tile_size)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_image_to_window(mlx->mlx, m->minimap, 0, 0);
	floors(m, m->p_x * tile_size, m->p_y * tile_size, tile_size);
	while (m->minimap_array[y])
	{
		while (m->minimap_array[y][x])
		{
			if (m->minimap_array[y][x] == 'N' || m->minimap_array[y][x] == 'S'
				|| m->minimap_array[y][x] == 'W'
				|| m->minimap_array[y][x] == 'E')
				mlx_image_to_window(mlx->mlx, mlx->raycast->ray->img, (x * tile_size)
					+ tile_size / 4, (y * tile_size) + tile_size / 4);
			x++;
		}
		x = 0;
		y++;
	}
	draw_player(mlx, tile_size);
}
