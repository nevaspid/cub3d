/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:52:56 by gloms             #+#    #+#             */
/*   Updated: 2024/05/21 14:47:10 by gloms            ###   ########.fr       */
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
	printf("x: %d, y: %d\n", display->m->player->instances[0].x,
		display->m->player->instances[0].y);
}

int	is_2pi(double number)
{
	double	epsilon;

	epsilon = 0.01;
	if (number < 0)
		number = number * -1;
	if (fabs(number - 2.0 * PI) < epsilon)
		return (1);
	else
		return (0);
}

void	player_angle(void *param)
{
	t_display	*display;

	display = (t_display *)param;
	if (mlx_is_key_down(display->mlx, MLX_KEY_LEFT))
		display->m->p_angle -= 0.01;
	if (mlx_is_key_down(display->mlx, MLX_KEY_RIGHT))
		display->m->p_angle += 0.01;
	if (is_2pi(display->m->p_angle))
		display->m->p_angle = 0;
	printf("angle: %f\n", display->m->p_angle);
}
