/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prim_draw_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 01:40:53 by oliove            #+#    #+#             */
/*   Updated: 2024/07/11 23:57:37 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_circle(t_compass *compass, int radius, int color, int fill)
{
	int	x;
	int	y;
	int	d;

	y = radius;
	x = 0;
	d = 3 - 2 * radius;
	while (x <= y)
	{
		if (fill == 1)
			fill_circle(compass, x, y, MY_BLACK);
		print_circle(compass, x, y, color);
		if (d < 0)
			d = d + 4 * x + 6;
		else
		{
			d = d + 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
}

// static void	set_line(t_line *l, t_vec_d start, t_vec_d end)
// {
// 	l->x1 = start.x;
// 	l->y1 = start.y;
// 	l->x2 = end.x;
// 	l->y2 = end.y;
// 	l->dx = abs(l->x2 - l->x1);
// 	l->dy = abs(l->y2 - l->y1);
// 	if (l->x1 < l->x2)
// 		l->sx = 1;
// 	else
// 		l->sx = -1;
// 	if (l->y1 < l->y2)
// 		l->sy = 1;
// 	else
// 		l->sy = -1;
// 	l->err = l->dx - l->dy;
// 	if (l->x1 < 0 || l->x1 >= WIDTH || l->x2 < 0 || l->x2 >= WIDTH || l->y1 < 0
// 		|| l->y1 >= HEIGHT || l->y2 < 0 || l->y2 >= HEIGHT)
// 		return ;
// }
