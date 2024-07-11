/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prim_draw_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 01:40:53 by oliove            #+#    #+#             */
/*   Updated: 2024/07/11 01:45:30 by oliove           ###   ########.fr       */
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
