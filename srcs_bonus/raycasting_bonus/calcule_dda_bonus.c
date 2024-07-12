/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule_dda_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:41:27 by oliove            #+#    #+#             */
/*   Updated: 2024/07/12 21:36:14 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	run_camera(t_display *d, t_camera *camera, t_player *player)
{
	camera->angle_cam = atan2(player->dir.y, player->dir.x);
	camera->angle_min = player->angle - FOV / 2;
	camera->angle_max = player->angle + FOV / 2;
	(void)d;
}

void	init_dda(t_ray *ray, t_player *player)
{
	(void)player;
	if (ray->dir.x < 0)
		ray->step.x = -1;
	else
		ray->step.x = 1;
	if (ray->dir.y < 0)
		ray->step.y = -1;
	else
		ray->step.y = 1;
	ray->side_dist.x = 0;
	ray->side_dist.y = 0;
}

void	calculate_height_line(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->side_dist.x - ray->delta_dist.x * V_MAGIE);
	else
		ray->wall_dist = (ray->side_dist.y - ray->delta_dist.y * V_MAGIE);
	ray->line_height = ((int)HEIGHT / ray->wall_dist);
	ray->line_height = ray->line_height / cos(ray->angle - player->angle);
	ray->draw_start = -ray->line_height / 2.0f + (int)HEIGHT / 2.0f;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2.0f + (int)HEIGHT / 2.0f;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos.y + ray->wall_dist * ray->dir.y;
	else
		ray->wall_x = player->pos.x + ray->wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
}

void	calculate_dda(t_display *d, t_ray *r)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (r->side_dist.x < r->side_dist.y)
		{
			r->side_dist.x += r->delta_dist.x * V_MAGIE;
			r->map.x += r->step.x * V_MAGIE;
			r->side = 0;
		}
		else
		{
			r->side_dist.y += r->delta_dist.y * V_MAGIE;
			r->map.y += r->step.y * V_MAGIE;
			r->side = 1;
		}
		if (r->map.y >= 0 || r->map.x >= 0 || r->map.y <= d->m->minimap->height
			|| r->map.x <= d->m->minimap->width)
			if (d->m->minimap_array[(int)r->map.y][(int)r->map.x] == '1')
				hit = 1;
	}
}

void	run_raycast(t_display *display, t_ray *ray, t_player *player)
{
	int			x;
	t_camera	*camera;

	x = 0;
	camera = display->raycast->camera;
	clear_image(display->raycast->ray->img, 0x000000);
	ray->angle = camera->angle_min;
	camera->camera_x = 2 * x / (double)WIDTH - 1;
	draw_bg(display->img);
	while (x < WIDTH)
	{
		update_cam(display, ray, player, x);
		init_dda(ray, player);
		calculate_dda(display, ray);
		calculate_height_line(ray, player);
		draw_ray(display, ray, player);
		draw_wall_orientation(display, ray, x);
		if (x % 2 == 0)
			ray->angle += angle_rad(FOV) / (WIDTH / 2);
		x++;
	}
}
