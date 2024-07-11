/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:25:21 by oliove            #+#    #+#             */
/*   Updated: 2024/07/12 00:27:51 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_to_window(t_display *display)
{
	int	tile_size;

	tile_size = display->m->tile_size;
	mlx_image_to_window(display->mlx, display->img, 0, 0);
	mlx_image_to_window(display->mlx, display->raycast->compass->img, WIDTH / 2 \
	, 0);
	mlx_image_to_window(display->mlx, display->m->minimap, 0, 0);
	mlx_image_to_window(display->mlx, display->m->player, display->m->p_x
		* tile_size, display->m->p_y * tile_size);
	mlx_image_to_window(display->mlx, display->raycast->ray->img, 0, 0);
}

void	arry_nb(t_display *display)
{
	if (longest_line(display->m->minimap_array) \
		> count_lines(display->m->minimap_array))
		display->m->tile_size = (WIDTH * SCALE)
			/ longest_line(display->m->minimap_array);
	else
		display->m->tile_size = (HEIGHT * SCALE)
			/ count_lines(display->m->minimap_array);
}

void	init_game(t_display *display, t_mem_alloc *mylloc)
{
	init_malloc(mylloc, display);
	init_mlx(display);
	init_value_st(display);
}

void	update_cam(t_display *display, t_ray *ray, t_player *player, int x)
{
	t_camera	*camera;

	(void)x;
	camera = display->raycast->camera;
	ray->dir.x = cos(ray->angle) + player->plane.x * camera->camera_x;
	ray->dir.y = sin(ray->angle) + player->plane.y * camera->camera_x;
	ray->map.x = player->pos.x;
	ray->map.y = player->pos.y;
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
}
