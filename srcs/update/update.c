/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:44:28 by oliove            #+#    #+#             */
/*   Updated: 2024/06/23 21:49:38 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void update_player(t_display *display, t_player *player)
{
    player->pos.x = display->p_x; //* display->m->tile_size * display->m->tile_size / 2; // display->raycast->ray->img->instances[0].x;
    player->pos.y = display->p_y; //* display->m->tile_size * display->m->tile_size / 2; // display->raycast->ray->img->instances[0].y;
    player->angle = display->p_angle;
}