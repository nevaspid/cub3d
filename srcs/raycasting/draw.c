/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:56:32 by oliove            #+#    #+#             */
/*   Updated: 2024/07/20 13:32:54 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_bg(t_display *display, mlx_image_t *img)
{
	int			x;
	int			y;
	uint32_t	ceiling;
	uint32_t	floor;

	ceiling = ft_pixel(ft_atoi(display->m->paths->split_c[0]),
			ft_atoi(display->m->paths->split_c[1]),
			ft_atoi(display->m->paths->split_c[2]), 255);
	floor = ft_pixel(ft_atoi(display->m->paths->split_f[0]),
			ft_atoi(display->m->paths->split_f[1]),
			ft_atoi(display->m->paths->split_f[2]), 255);
	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(img, x, y, ceiling);
			else
				mlx_put_pixel(img, x, y, floor);
			x++;
		}
		y++;
	}
}

mlx_image_t	*get_texture(t_display *s_display, t_ray *ray)
{
	mlx_image_t	*img;

	if (ray->side == 1)
	{
		if (ray->step.y > 0)
			img = s_display->raycast->text->north_img;
		else
			img = s_display->raycast->text->south_img;
	}
	else
	{
		if (ray->step.x > 0)
			img = s_display->raycast->text->west_img;
		else
			img = s_display->raycast->text->east_img;
	}
	return (img);
}

void	draw_wall_orientation(t_display *display, t_ray *ray, int x)
{
	display->current_tex = get_texture(display, ray);
	if (ray->side == 1)
	{
		if (ray->step.y > 0)
			draw_ligne_height(display, x, ray->draw_start, ray->draw_end);
		else
			draw_ligne_height(display, x, ray->draw_start, ray->draw_end);
	}
	else
	{	
		if (ray->step.x > 0)
			draw_ligne_height(display, x, ray->draw_start, ray->draw_end);
		else
			draw_ligne_height(display, x, ray->draw_start, ray->draw_end);
	}
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

void	draw_ray(t_display *display, t_ray *ray, t_player *player)
{
	int	max_ray_lenght;

	max_ray_lenght = 3;
	ray->end = (t_vec_d){ray->map.x, ray->map.y};
	if (hypot(ray->map.x - player->pos.x, ray->map.y - player->pos.y) \
		> max_ray_lenght)
	{
		ray->end.x = player->pos.x + max_ray_lenght * ray->dir.x;
		ray->end.y = player->pos.y + max_ray_lenght * ray->dir.y;
	}
	if (ray->angle >= player->angle)
		draw_line(display->raycast->ray->img, \
		(t_vec_d){player->pos.x * display->m->tile_size, player->pos.y \
		* display->m->tile_size}, (t_vec_d){ray->end.x * display->m->tile_size, \
		ray->end.y * display->m->tile_size}, MY_RED);
	else
		draw_line(display->raycast->ray->img, \
		(t_vec_d){player->pos.x * display->m->tile_size, player->pos.y \
		* display->m->tile_size}, (t_vec_d){ray->end.x \
		* display->m->tile_size, ray->end.y * display->m->tile_size}, 0x800080);
}
