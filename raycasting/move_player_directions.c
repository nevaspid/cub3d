/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_directions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:52:41 by gloms             #+#    #+#             */
/*   Updated: 2024/05/30 02:26:02 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forwards(t_display *d)//tout droit
{
	d->p_x += cos(d->p_angle) * SPEED;
	d->p_y += sin(d->p_angle) * SPEED;
	d->raycast->ray->img->instances[0].y = d->p_y * d->m->tile_size;
	d->raycast->ray->img->instances[0].y = d->p_y * d->m->tile_size;
}

void	move_backwards(t_display *d)//reculer
{
	d->p_x -= cos(d->p_angle) * SPEED;
	d->p_y -= sin(d->p_angle) * SPEED;
	d->raycast->ray->img->instances[0].y = d->p_y * d->m->tile_size;
	d->raycast->ray->img->instances[0].y = d->p_y * d->m->tile_size;
}

void	move_left(t_display *d)//gauche
{
	d->p_x -= cos(d->p_angle) * SPEED;
	d->p_x -= sin(d->p_angle) * SPEED;
	d->raycast->ray->img->instances[0].x = d->p_x * d->m->tile_size;
	d->raycast->ray->img->instances[0].y = d->p_y * d->m->tile_size;
}

void	move_right(t_display *d)//droite
{
	d->p_x += cos(d->p_angle) * SPEED;
	d->p_x += sin(d->p_angle) * SPEED;
	d->raycast->ray->img->instances[0].x = d->p_x * d->m->tile_size;
	d->raycast->ray->img->instances[0].y = d->p_y * d->m->tile_size;
}
