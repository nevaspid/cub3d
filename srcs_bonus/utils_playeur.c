/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_playeur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:37:46 by oliove            #+#    #+#             */
/*   Updated: 2024/07/12 00:48:48 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ray(t_display *display, t_ray *ray, t_player *player)
{
	int	max_ray_lenght;

	max_ray_lenght = 3;
	ray->end = (t_vec_d){ray->map.x, ray->map.y};
	if (hypot(ray->map.x - player->pos.x, ray->map.y
			- player->pos.y) > max_ray_lenght)
	{
		ray->end.x = player->pos.x + max_ray_lenght * ray->dir.x;
		ray->end.y = player->pos.y + max_ray_lenght * ray->dir.y;
	}
	if (ray->angle >= player->angle)
		draw_line(display->raycast->ray->img, (t_vec_d){player->pos.x
			* display->m->tile_size, player->pos.y * display->m->tile_size},
			(t_vec_d){ray->end.x * display->m->tile_size, ray->end.y
			* display->m->tile_size}, MY_RED);
	else
		draw_line(display->raycast->ray->img, (t_vec_d){player->pos.x
			* display->m->tile_size, player->pos.y * display->m->tile_size},
			(t_vec_d){ray->end.x * display->m->tile_size, ray->end.y
			* display->m->tile_size}, 0x800080);
}

void	clear_image(mlx_image_t *img, uint32_t a)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, a);
			x++;
		}
		y++;
	}
}

void	draw_ligne_height(t_display *display, int x, int star, int end)
{
	t_ray	*ray;
	double	ty;
	int		px;
	int		y;

	if (display == NULL || display->current_tex == NULL)
		return ;
	ray = display->raycast->ray;
	px = (int)(display->current_tex->width * (ray->map.x + ray->map.y))
		% display->current_tex->width;
	y = star;
	while (y < end)
	{
		ty = inverse_lerp(star, end, y);
		mlx_put_pixel(display->img, x, y, get_color((int)(px), (int)(ty
					* (display->current_tex->height - 1)),
				display->current_tex));
		y++;
	}
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
