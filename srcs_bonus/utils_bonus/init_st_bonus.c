/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_st_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:49:55 by oliove            #+#    #+#             */
/*   Updated: 2024/07/11 19:48:08 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct_camera(t_camera *camera)
{
	camera->angle_cam = 0;
	camera->angle_min = 0;
	camera->angle_max = 0;
	camera->angle_ray = 0;
	camera->dir.x = 0;
	camera->dir.y = 0;
	camera->nb_ray = 0;
	camera->plane.x = 0;
	camera->plane.y = 0;
}

// void	init_player(t_display *display, t_player *player)
// {
// 	player->pos.x = display->p_x; 
// 	player->pos.y = display->p_y;
// 	player->angle = display->p_angle;
// 	player->dir.x = 0;
// 	player->dir.y = 0;
// 	player->plane.x = 0;
// 	player->plane.y = 0;
// }

// void	init_malloc(t_mem_alloc *mylloc, t_display *display)
// {
// 	display->m = mem_alloc(mylloc, sizeof(t_minimap));
// 	display->m->paths = mem_alloc(mylloc, sizeof(t_paths));
// 	display->raycast = mem_alloc(mylloc, sizeof(t_raycast));
// 	display->raycast->compass = mem_alloc(mylloc, sizeof(t_compass));
// 	display->raycast->player = mem_alloc(mylloc, sizeof(t_player));
// 	display->raycast->ray = mem_alloc(mylloc, sizeof(t_ray));
// 	display->raycast->camera = mem_alloc(mylloc, sizeof(t_camera));
// 	display->raycast->text = mem_alloc(mylloc, sizeof(t_texture));
// }