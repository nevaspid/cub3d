/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_st_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:49:55 by oliove            #+#    #+#             */
/*   Updated: 2024/07/20 20:03:58 by oliove           ###   ########.fr       */
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
