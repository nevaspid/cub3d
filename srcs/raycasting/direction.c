/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:17:39 by oliove            #+#    #+#             */
/*   Updated: 2024/07/12 01:46:47 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	west(t_player *player)
{
	if (player->pos_start == 'W')
	{
		player->dir.x = 0;
		player->dir.y = -1;
		player->plane.x = -0.66;
		player->plane.y = 0;
	}
	else if (player->pos_start == 'E')
	{
		player->dir.x = 0;
		player->dir.y = 1;
		player->plane.x = 0.66;
		player->plane.y = 0;
	}
}

void	norsh(t_player *player)
{
	if (player->pos_start == 'N')
	{
		player->dir.x = -1;
		player->dir.y = 0;
		player->plane.x = 0;
		player->plane.y = 0.66;
	}
	else if (player->pos_start == 'S')
	{
		player->dir.x = 1;
		player->dir.y = 0;
		player->plane.x = 0;
		player->plane.y = -0.66;
	}
}

void	run_camera(t_display *d, t_camera *camera, t_player *player)
{
	camera->angle_cam = atan2(player->dir.y, player->dir.x);
	camera->angle_min = player->angle - FOV / 2;
	camera->angle_max = player->angle + FOV / 2;
	(void)d;
}
