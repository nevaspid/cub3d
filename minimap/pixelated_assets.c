/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelated_assets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:13:32 by gloms             #+#    #+#             */
/*   Updated: 2024/02/02 01:30:30 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	wall(t_minimap *minimap, int x, int y, int tile_width, int tile_height)
{
	int		i;
	int		j;
	int		first_x;

	i = 0;
	j = 0;
	first_x = x;
	while (j < tile_height)
	{
		while (i < tile_width)
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

void	floors(t_minimap *minimap, int x, int y, int tile_width, int tile_height)
{
	int		i;
	int		j;
	int		first_x;

	i = 0;
	j = 0;
	first_x = x;
	while (j < tile_height)
	{
		while (i < tile_width)
		{
			mlx_put_pixel(minimap->minimap, (uint32_t)x, (uint32_t)y, 0xAAA000FF);
			i++;
			x++;
		}
		i = 0;
		x = first_x;
		j++;
		y++;
	}
}
