/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:22:10 by oliove            #+#    #+#             */
/*   Updated: 2024/07/12 00:19:53 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	angle_rad(double angle)
{
	return (angle * M_PI / 180);
}

double	distance(t_vec_d a, t_vec_d b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}

void	load_asset(t_display *display, mlx_texture_t *text, mlx_image_t **asset,
		char *path)
{
	text = mlx_load_png(path);
	if (!text)
	{
		printf("ERROR : Asset not found\n");
		exit(0);
	}
	*asset = mlx_texture_to_image(display->mlx, text);
	mlx_delete_texture(text);
}

u_int32_t	get_rgba_tex(u_int32_t color)
{
	u_int8_t	r;
	u_int8_t	g;
	u_int8_t	b;
	u_int8_t	a;

	a = color >> 24;
	r = color >> 16;
	g = color >> 8;
	b = color;
	return (r << 8 | g << 16 | b << 24 | a << 0);
}

u_int32_t	get_color(int x, int y, mlx_image_t *img)
{
	uint32_t	*pixel;
	u_int32_t	color;

	(void)x;
	color = 0;
	pixel = NULL;
	pixel = (uint32_t *)(img->pixels + (x + y * (img->width))
			* sizeof(uint32_t));
	color = *pixel;
	return (get_rgba_tex(color));
}
