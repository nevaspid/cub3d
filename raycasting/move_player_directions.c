/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_directions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:52:41 by gloms             #+#    #+#             */
/*   Updated: 2024/05/24 19:12:32 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forwards(t_display *d)
{
	d->p_y -= SPEED;
	d->m->player->instances[0].y = d->p_y * d->m->tile_size;
	//d->m->player->instances[0].x += (int)(cos(d->p_angle) * SPEED);
	//d->m->player->instances[0].y += (int)(sin(d->p_angle) * SPEED);
}

void	move_backwards(t_display *d)
{
	d->p_y += SPEED;
	d->m->player->instances[0].y = d->p_y * d->m->tile_size;
	//d->m->player->instances[0].x -= cos(d->p_angle) * SPEED;
	//d->m->player->instances[0].y -= sin(d->p_angle) * SPEED;
}

void	move_left(t_display *d)
{
	d->p_x -= SPEED;
	d->m->player->instances[0].x = d->p_x * d->m->tile_size;
	//d->m->player->instances[0].x -= cos(d->p_angle + PI / 2) * SPEED;
	//d->m->player->instances[0].y -= sin(d->p_angle + PI / 2) * SPEED;
}

void	move_right(t_display *d)
{
	d->p_x += SPEED;
	d->m->player->instances[0].x = d->p_x * d->m->tile_size;
	//d->m->player->instances[0].x += cos(d->p_angle + PI / 2) * SPEED;
	//d->m->player->instances[0].y += sin(d->p_angle + PI / 2) * SPEED;
}