/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:52:56 by gloms             #+#    #+#             */
/*   Updated: 2024/02/23 15:53:32 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_player(void *param)
{
	t_display	*display;

	display = (t_display *)param;
	if (mlx_is_key_down(display->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(display->mlx);
	if (mlx_is_key_down(display->mlx, MLX_KEY_A))
		display->m->player->instances[0].x -= SPEED;
	if (mlx_is_key_down(display->mlx, MLX_KEY_D))
		display->m->player->instances[0].x += SPEED;
	if (mlx_is_key_down(display->mlx, MLX_KEY_W))
		display->m->player->instances[0].y -= SPEED;
	if (mlx_is_key_down(display->mlx, MLX_KEY_S))
		display->m->player->instances[0].y += SPEED;
	printf("x: %d, y: %d\n", display->m->player->instances[0].x, display->m->player->instances[0].y);
}
