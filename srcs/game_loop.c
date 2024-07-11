/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:44:31 by oliove            #+#    #+#             */
/*   Updated: 2024/07/11 01:57:20 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_to_window(t_display *display)
{
	mlx_image_to_window(display->mlx, display->img, 0, 0);
	mlx_image_to_window(display->mlx, display->raycast->compass->img, WIDTH / 2,
		0);
}

void	init_game(t_display *display, t_mem_alloc *mylloc)
{
	init_malloc(mylloc, display);
	init_mlx(display);
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
