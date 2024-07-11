/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:55:15 by oliove            #+#    #+#             */
/*   Updated: 2024/07/11 01:45:47 by oliove           ###   ########.fr       */
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

void	draw_compass(t_display *display, t_compass *compass, t_player *player)
{
	init_value_st(display);
	draw_circle(compass, compass->radius, MY_WHITE, 1);
	draw_circle(compass, compass->radius - 2, MY_BLACK, 0);
	draw_circle(compass, compass->radius - 1, MY_WHITE, 0);
	compass->needle_length = compass->radius * 0.8;
	compass->needle_end_x = compass->center_x + compass->needle_length
		* cos(player->angle);
	compass->needle_end_y = compass->center_y + compass->needle_length
		* sin(player->angle);
	draw_line(compass->img, (t_vec_d){compass->center_x, compass->center_y},
		(t_vec_d){compass->needle_end_x, compass->needle_end_y}, MY_RED);
	mlx_put_pixel(compass->img, compass->center_x, compass->center_y, MY_WHITE);
}
