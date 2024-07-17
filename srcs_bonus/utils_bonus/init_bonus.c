/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doctor <doctor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 01:21:22 by oliove            #+#    #+#             */
/*   Updated: 2024/07/13 13:32:07 by doctor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_malloc(t_mem_alloc *mylloc, t_display *display)
{
	display->m = mem_alloc(mylloc, sizeof(t_minimap));
	display->m->paths = mem_alloc(mylloc, sizeof(t_paths));
	display->raycast = mem_alloc(mylloc, sizeof(t_raycast));
	display->raycast->compass = mem_alloc(mylloc, sizeof(t_compass));
	display->raycast->player = mem_alloc(mylloc, sizeof(t_player));
	display->raycast->ray = mem_alloc(mylloc, sizeof(t_ray));
	display->raycast->camera = mem_alloc(mylloc, sizeof(t_camera));
	display->raycast->text = mem_alloc(mylloc, sizeof(t_texture));
	display->raycast->gf = mem_alloc(mylloc, sizeof(t_gf));
	display->raycast->gf->b = mem_alloc(mylloc, sizeof(t_ray));
}

void	init_player(t_display *display, t_player *player)
{
	player->pos.x = display->p_x;
	player->pos.y = display->p_y;
	player->angle = display->p_angle;
	player->dir.x = 0;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0;
}

void	init_struct_camera(t_camera *camera)
{
	camera->angle_cam = 0;
	camera->angle_min = 0;
	camera->angle_max = 0;
	camera->dir.x = 0;
	camera->dir.y = 0;
}

void	init_camera(t_display *display, t_camera *camera)
{
	camera->fov = FOV;
	camera->camera_x = 0;
	camera->angle_cam = display->p_angle;
	camera->angle_min = display->p_angle - angle_rad(FOV) / 2;
	camera->angle_max = display->p_angle + angle_rad(FOV) / 2;
	camera->dir.x = cos(display->raycast->player->angle);
	camera->dir.y = sin(display->raycast->player->angle);
}

void	init_value_st(t_display *display)
{
	init_player(display, display->raycast->player);
	init_camera(display, display->raycast->camera);
	init_compass(display->raycast->compass);
}
