/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 04:07:31 by oliove            #+#    #+#             */
/*   Updated: 2024/07/04 04:29:51 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// int check_colision(t_display *d, t_ray *ray)
// {
//     if (d->m->minimap_array[(int)ray->end.y][(int)ray->end.x] == '1')
//         return (1);
//     return (0);
// }

// void move_left(t_display *display)
// {
//     t_vec_d new_pos;

//     new_pos.x = display->raycast->player->pos.x - cos(display->raycast->player->angle + M_PI_2) * SPEED;
//     new_pos.y = display->raycast->player->pos.y - sin(display->raycast->player->angle + M_PI_2) * SPEED;
//     if (!check_colision(display, &(t_ray){display->raycast->player->pos, new_pos}))
//     {
//         display->raycast->player->pos.x = new_pos.x;
//         display->raycast->player->pos.y = new_pos.y;
//     }
// }