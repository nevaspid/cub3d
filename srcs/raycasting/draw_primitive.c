/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_primitive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 06:10:51 by oliove            #+#    #+#             */
/*   Updated: 2024/07/11 22:52:30 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_line(t_line *l, t_vec_d start, t_vec_d end)
{
	l->x1 = start.x;
	l->y1 = start.y;
	l->x2 = end.x;
	l->y2 = end.y;
	l->dx = abs(l->x2 - l->x1);
	l->dy = abs(l->y2 - l->y1);
	if (l->x1 < l->x2)
		l->sx = 1;
	else
		l->sx = -1;
	if (l->y1 < l->y2)
		l->sy = 1;
	else
		l->sy = -1;
	l->err = l->dx - l->dy;
	if (l->x1 < 0 || l->x1 >= WIDTH || l->x2 < 0 || l->x2 >= WIDTH || l->y1 < 0
		|| l->y1 >= HEIGHT || l->y2 < 0 || l->y2 >= HEIGHT)
		return ;
}

void	draw_line(mlx_image_t *img, t_vec_d start, t_vec_d end, int color)
{
	t_line	l;

	set_line(&l, start, end);
	while (1)
	{
		mlx_put_pixel(img, l.x1, l.y1, color);
		if (l.x1 == l.x2 && l.y1 == l.y2)
			break ;
		l.err2 = 2 * l.err;
		if (l.err2 > -l.dy)
		{
			l.err -= l.dy;
			l.x1 += l.sx;
		}
		if (l.err2 < l.dx)
		{
			l.err += l.dx;
			l.y1 += l.sy;
		}
	}
}

void	draw_fill_circle(mlx_image_t *img, t_vec *x, int y, int color)
{
	int	x1;
	int	x2;

	x1 = x->x;
	x2 = x->y;
	while (x1 <= x2)
	{
		mlx_put_pixel(img, x1, y, color);
		mlx_put_pixel(img, x2, y, color);
		x1++;
		x2--;
	}
}

void	fill_circle(t_compass *compass, int x, int y, int color)
{
	draw_fill_circle(compass->img, &(t_vec){compass->center_x - x,
		compass->center_x + x}, compass->center_y + y, color);
	draw_fill_circle(compass->img, &(t_vec){compass->center_x - x,
		compass->center_x + x}, compass->center_y - y, color);
	draw_fill_circle(compass->img, &(t_vec){compass->center_x - y,
		compass->center_x + y}, compass->center_y + x, color);
	draw_fill_circle(compass->img, &(t_vec){compass->center_x - y,
		compass->center_x + y}, compass->center_y - x, color);
}

void	print_circle(t_compass *compass, int x, int y, int color)
{
	mlx_put_pixel(compass->img, compass->center_x + x, compass->center_y + y,
		color);
	mlx_put_pixel(compass->img, compass->center_x + x, compass->center_y + y,
		color);
	mlx_put_pixel(compass->img, compass->center_x - x, compass->center_y + y,
		color);
	mlx_put_pixel(compass->img, compass->center_x + x, compass->center_y - y,
		color);
	mlx_put_pixel(compass->img, compass->center_x - x, compass->center_y - y,
		color);
	mlx_put_pixel(compass->img, compass->center_x + y, compass->center_y + x,
		color);
	mlx_put_pixel(compass->img, compass->center_x - y, compass->center_y + x,
		color);
	mlx_put_pixel(compass->img, compass->center_x + y, compass->center_y - x,
		color);
	mlx_put_pixel(compass->img, compass->center_x - y, compass->center_y - x,
		color);
}
