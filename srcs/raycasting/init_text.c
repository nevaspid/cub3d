/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:55:15 by oliove            #+#    #+#             */
/*   Updated: 2024/07/08 20:04:22 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_display *display)
{
	display->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	display->m->minimap = mlx_new_image(display->mlx, WIDTH * SCALE,
			HEIGHT * SCALE);
	display->raycast->compass->img = mlx_new_image(display->mlx, WIDTH * SCALE,
			HEIGHT * SCALE);
	display->raycast->ray->img = mlx_new_image(display->mlx, WIDTH * SCALE,
			HEIGHT * SCALE);
	display->img = mlx_new_image(display->mlx, WIDTH, HEIGHT);
}

void	init_compass(t_compass *cmp)
{
	cmp->radius = 100;
	cmp->center_x = (WIDTH - cmp->radius) - 1;
	cmp->center_y = cmp->radius;
	cmp->needle_length = cmp->radius * 0.8;
}

void	init_text_to_img(t_display *display)
{	
	load_asset(display, display->raycast->text->west,
		&display->raycast->text->west_img, "SAMPLE/DOOR_1A.PNG");
	if (display->raycast->text->west_img == NULL)
		printf("TEXTURE _WEST NULL\n");
	load_asset(display, display->raycast->text->north,
		&display->raycast->text->north_img, "SAMPLE/BRICK_6D.PNG");
	if (display->raycast->text->north_img == NULL)
		printf("TEXTURE NORTH NULL\n");
	load_asset(display, display->raycast->text->east,
		&display->raycast->text->east_img, "SAMPLE/CONCRETE_4A.PNG");
	if (display->raycast->text->east_img == NULL)
		printf("TEXTURE EAST NULL\n");
	load_asset(display, display->raycast->text->south,
		&display->raycast->text->south_img, "SAMPLE/PAPER_1F.PNG");
	if (display->raycast->text->south_img == NULL)
		printf("TEXTURENULL SOUTH\n");
}

void	init_text(t_display *display)
{
	display->raycast->text->pos = 0;
	display->raycast->text->x = 0;
	display->raycast->text->y = 0;
	display->raycast->text->step = 0;
	display->raycast->text->size = 0;
}
