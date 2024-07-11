/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:56:32 by oliove            #+#    #+#             */
/*   Updated: 2024/07/11 23:57:24 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_bg(mlx_image_t *img)
{
	int	x;
	int	y;

	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(img, x, y, MY_BLACK);
			else
				mlx_put_pixel(img, x, y, MY_RED);
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
		{
			draw_ligne_height(display, x, ray->draw_start, ray->draw_end);
		}
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
