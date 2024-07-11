/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_directions_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:52:41 by gloms             #+#    #+#             */
/*   Updated: 2024/07/11 14:41:53 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* MSG for push*/
int	check_next_move(t_display *d, double x, double y, t_direction dir)
{
	t_vec	pos;

	if (dir == UP)
	{
		pos.x = x + cos(d->p_angle) * SPEED;
		pos.y = y + sin(d->p_angle) * SPEED;
	}
	if (dir == DOWN)
	{
		pos.x = x - cos(d->p_angle) * SPEED;
		pos.y = y - sin(d->p_angle) * SPEED;
	}
	if (dir == LEFT)
	{
		pos.x = x + cos(d->p_angle + M_PI / 2) * SPEED;
		pos.y = y + sin(d->p_angle + M_PI / 2) * SPEED;
	}
	if (dir == RIGHT)
	{
		pos.x = x - cos(d->p_angle + M_PI / 2) * SPEED;
		pos.y = y - sin(d->p_angle + M_PI / 2) * SPEED;
	}
	if (d->m->minimap_array[pos.y][pos.x] == '1')
		return (1);
	return (0);
}

void	move_forwards(t_display *d)
{
	if (check_next_move(d, d->p_x + cos(d->p_angle) * SPEED, d->p_y
			+ sin(d->p_angle) * SPEED, UP))
		return ;
	d->p_x += (cos(d->p_angle) * SPEED);
	d->p_y += (sin(d->p_angle) * SPEED);
	d->m->player->instances[0].x = (d->p_x * d->m->tile_size);
	d->m->player->instances[0].y = (d->p_y * d->m->tile_size);
}

void	move_backwards(t_display *d)
{
	if (check_next_move(d, d->p_x - cos(d->p_angle) * SPEED, d->p_y
			- sin(d->p_angle) * SPEED, DOWN))
		return ;
	d->p_x -= cos(d->p_angle) * SPEED;
	d->p_y -= sin(d->p_angle) * SPEED;
	d->m->player->instances[0].x = (d->p_x * d->m->tile_size);
	d->m->player->instances[0].y = (d->p_y * d->m->tile_size);
}

void	move_left(t_display *d)
{
	if (check_next_move(d, d->p_x + cos(d->p_angle + M_PI / 2) * SPEED, d->p_y
			+ sin(d->p_angle + M_PI / 2) * SPEED, LEFT))
		return ;
	d->p_x += cos(d->p_angle + M_PI / 2) * SPEED;
	d->p_y += sin(d->p_angle + M_PI / 2) * SPEED;
	d->m->player->instances[0].x = (d->p_x * d->m->tile_size);
	d->m->player->instances[0].y = (d->p_y * d->m->tile_size);
}

void	move_right(t_display *d)
{
	if (check_next_move(d, d->p_x - cos(d->p_angle + M_PI / 2) \
		* SPEED, d->p_y - sin(d->p_angle + M_PI / 2) * SPEED, RIGHT))
		return ;
	d->p_x -= cos(d->p_angle + M_PI / 2) * SPEED;
	d->p_y -= sin(d->p_angle + M_PI / 2) * SPEED;
	d->m->player->instances[0].x = (d->p_x * d->m->tile_size);
	d->m->player->instances[0].y = (d->p_y * d->m->tile_size);
}
