/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 00:46:50 by oliove            #+#    #+#             */
/*   Updated: 2024/05/27 01:19:33 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_camera(t_display *d, t_camera *camera)
{
    camera->angle_cam = atan2(d->player->dir.y, d->player->dir.x) * 180 / PI;
    camera->angle_min = d->player->angle - FOV / 2;
    camera->angle_max = d->player->angle + FOV / 2;
    camera->nb_ray = 2; // a changer peut etre "WIDTH"-> ou += / 10;
    camera->angle_ray = FOV / camera->nb_ray;
    camera->dir.x = d->player->dir.x;
    camera->plane.x = d->player->dir.y * tan(FOV / 2 * PI / 180); // je met ca de cote pour le moment je vais voir 
    // camera->plane.y = d->display->player->dir.x * tan(FOV / 2 * PI / 180);// juste avec angle et dir
}


void init_raycast(t_display *data)
{
    
    
}