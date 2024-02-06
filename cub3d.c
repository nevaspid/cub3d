/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:41:39 by gloms             #+#    #+#             */
/*   Updated: 2024/02/06 14:42:53 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_minimap *minimap, int tile_width, int tile_height)
{
	int		x;
	int		y;

	x = 0;
	y = 0;

	while (y < tile_height / 2)
	{
		while (x < tile_width / 2)
		{
			mlx_put_pixel(minimap->minimap, (uint32_t)minimap->p_x * tile_width + x, (uint32_t)minimap->p_y * tile_height + y, 0xFF0000FF);
			x++;
		}
		x -= tile_width / 2;
		y++;
	}
}

void	print_player(t_display *mlx, t_minimap *minimap, int tile_width, int tile_height)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (minimap->minimap_array[y])
	{
		while (minimap->minimap_array[y][x])
		{
			if (minimap->minimap_array[y][x] == 'N')
				mlx_image_to_window(mlx->mlx, minimap->player, x * tile_width, y * tile_height);
			else if (minimap->minimap_array[y][x] == 'S')
				mlx_image_to_window(mlx->mlx, minimap->player, x * tile_width, y * tile_height);
			else if (minimap->minimap_array[y][x] == 'E')
				mlx_image_to_window(mlx->mlx, minimap->player, x * tile_width, y * tile_height);
			else if (minimap->minimap_array[y][x] == 'W')
				mlx_image_to_window(mlx->mlx, minimap->player, x * tile_width, y * tile_height);
			x++;
		}
		x = 0;
		y++;
	}
	draw_player(minimap, tile_width, tile_height);
}

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
			else if (is_char(minimap->minimap_array[y][x]))
			{
				minimap->p_y = y;
				minimap->p_x = x;
				floors(minimap, x * tile_width, y * tile_height, tile_width, tile_height);
				minimap->player = mlx_new_image(mlx->mlx, tile_width / 2, tile_height / 2);
			}
			x++;
		}
		x = 0;
		y++;
	}
	print_player(mlx, minimap, tile_width, tile_height);
}

int	longest_line(char **array)
{
    int		i;
    int		length;
    int		max_length;

    i = 0;
    max_length = 0;
    while (array[i])
    {
        length = ft_strlen(array[i]);
        if (length > max_length)
            max_length = length;
        i++;
    }
    return (max_length);
}

int count_lines(char **array)
{
    int count = 0;
    while (array[count] != NULL)
        count++;
    return count;
}

void	wall2(mlx_key_data_t keydata, void *param)
{
	static int		x;
	static int		y;
	static int counter;
	t_minimap		*m;

	m = (t_minimap *)param;
	if (keydata.key == 87)
	{
		wall(m, x, y, 6, 6);
		x += 6;
		counter++;
		if (counter == 57)
		{
			y += 6;
			counter = 0;
		}
	}
}

int	main(int ac, char **av)
{
	t_display *display;
	t_minimap *minimap;
	t_mem_alloc *mylloc;

	(void)ac;
	mylloc = malloc(sizeof(t_mem_alloc));
	minimap = mem_alloc(mylloc, sizeof(t_minimap));
	display = mem_alloc(mylloc, sizeof(t_display));
	display->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	minimap->minimap = mlx_new_image(display->mlx, WIDTH * 0.2, HEIGHT * 0.2);
	minimap->minimap_array = read_and_store(av[1], mylloc);
	print_minimap(display, minimap, (WIDTH * 0.2) / longest_line(minimap->minimap_array), (HEIGHT * 0.2) / count_lines(minimap->minimap_array));
	mlx_image_to_window(display->mlx, minimap->minimap, 0, 0);
	mlx_key_hook(display->mlx, &wall2, minimap);
	mlx_loop(display->mlx);
}
