/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_directions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:52:41 by gloms             #+#    #+#             */
/*   Updated: 2024/06/09 01:14:55 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int check_next_move(t_display *d, double x, double y)
{
	// t_vec pos;
	(void)d;
	(void)x;
	(void)y;
	

	// pos.x = (int)((x + d->m->tile_size) );
	// pos.y = (int)((y + d->m->tile_size) );
	// printf("x = %d, y = %d\n", pos.x, pos.y);
	// if (d->m->minimap_array[(int)y][(int)x] == '1')
	// 	return (1);
	return (0);
}


void	move_forwards(t_display *d)//tout droit
{
	d->p_x +=  cos(d->p_angle) * SPEED;
	d->p_y +=  sin(d->p_angle) * SPEED;
	d->m->player->instances[0].x = (d->p_x * d->m->tile_size);
	d->m->player->instances[0].y = (d->p_y * d->m->tile_size);
}

void	move_backwards(t_display *d)//reculer
{
	d->p_x -= cos(d->p_angle) * SPEED;
	d->p_y -= sin(d->p_angle) * SPEED;
	d->m->player->instances[0].x = (d->p_x * d->m->tile_size);
	d->m->player->instances[0].y = (d->p_y * d->m->tile_size);
}

void	move_left(t_display *d)//gauche
{
	d->p_x += cos(d->p_angle + M_PI /2) * SPEED;
	d->p_y += sin(d->p_angle + M_PI /2) * SPEED;
	d->m->player->instances[0].x = (d->p_x * d->m->tile_size);
	d->m->player->instances[0].y = (d->p_y * d->m->tile_size);
}

void	move_right(t_display *d)//droite
{
	d->p_x -= cos(d->p_angle + M_PI /2) * SPEED;
	d->p_y -= sin(d->p_angle + M_PI /2) * SPEED;
	d->m->player->instances[0].x = (d->p_x * d->m->tile_size);
	d->m->player->instances[0].y = (d->p_y * d->m->tile_size);
}
