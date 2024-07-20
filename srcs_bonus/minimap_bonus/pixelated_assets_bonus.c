/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelated_assets_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:13:32 by gloms             #+#    #+#             */
/*   Updated: 2024/07/20 20:04:22 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
