/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 01:21:22 by oliove            #+#    #+#             */
/*   Updated: 2024/07/20 11:31:15 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_display *display)
{
	display->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	display->m->minimap = mlx_new_image(display->mlx, WIDTH * 0.2, HEIGHT
			* 0.2);
	display->raycast->compass->img = mlx_new_image(display->mlx, WIDTH * 0.2,
			HEIGHT * 0.2);
	display->raycast->ray->img = mlx_new_image(display->mlx, WIDTH * 0.2,
			HEIGHT * 0.2);
	display->img = mlx_new_image(display->mlx, WIDTH, HEIGHT);
}

void	init_text_to_img(t_display *display)
{
	load_asset(display, display->raycast->text->west,
		&display->raycast->text->west_img, display->m->paths->se);
	if (display->raycast->text->west_img == NULL)
		printf("TEXTURE _WEST NULL\n");
	load_asset(display, display->raycast->text->north,
		&display->raycast->text->north_img, display->m->paths->no);
	if (display->raycast->text->north_img == NULL)
		printf("TEXTURE NORTH NULL\n");
	load_asset(display, display->raycast->text->east,
		&display->raycast->text->east_img, display->m->paths->ea);
	if (display->raycast->text->east_img == NULL)
		printf("TEXTURE EAST NULL\n");
	load_asset(display, display->raycast->text->south,
		&display->raycast->text->south_img, display->m->paths->so);
	if (display->raycast->text->south_img == NULL)
		printf("TEXTURENULL SOUTH\n");
}

void	init_compass(t_compass *cmp)
{
	cmp->radius = 100;
	cmp->center_x = (WIDTH - cmp->radius) - 1;
	cmp->center_y = cmp->radius;
	cmp->needle_length = cmp->radius * 0.8;
}

void	init_text(t_display *display)
{
	display->raycast->text->pos = 0;
	display->raycast->text->x = 0;
	display->raycast->text->y = 0;
	display->raycast->text->step = 0;
	display->raycast->text->size = 0;
}
