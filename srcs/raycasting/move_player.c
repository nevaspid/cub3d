/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:52:56 by gloms             #+#    #+#             */
/*   Updated: 2024/07/12 20:46:22 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_2pi(double number)
{
	double	epsilon;

	epsilon = 0.01;
	if (number < 0)
		number = number * -1;
	if (fabs(number - 2.0 * M_PI) < epsilon)
		return (1);
	else
		return (0);
}

void	player_angle(void *param)
{
	t_display	*display;

	display = (t_display *)param;
	if (mlx_is_key_down(display->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(display->mlx);
	if (mlx_is_key_down(display->mlx, MLX_KEY_D))
		move_left(display);
	if (mlx_is_key_down(display->mlx, MLX_KEY_A))
		move_right(display);
	if (mlx_is_key_down(display->mlx, MLX_KEY_W))
		move_forwards(display);
	if (mlx_is_key_down(display->mlx, MLX_KEY_S))
		move_backwards(display);
	if (mlx_is_key_down(display->mlx, MLX_KEY_LEFT))
		display->p_angle -= ROTATE;
	if (mlx_is_key_down(display->mlx, MLX_KEY_RIGHT))
		display->p_angle += ROTATE;
	if (is_2pi(display->p_angle))
		display->p_angle = 0;
	draw_compass(display, display->raycast->compass, display->raycast->player);
	run_raycast(display, display->raycast->ray, display->raycast->player);
}

void	move_rotated(mlx_key_data_t key, void *param)
{
	t_display	*display;

	(void)key;
	display = (t_display *)param;
	if (mlx_is_key_down(display->mlx, MLX_KEY_LEFT))
		display->p_angle -= ROTATE;
	if (mlx_is_key_down(display->mlx, MLX_KEY_RIGHT))
		display->p_angle += ROTATE;
	if (is_2pi(display->p_angle))
		display->p_angle = 0;
	return ;
}

void	move_player(mlx_key_data_t key, void *param)
{
	t_display	*display;

	(void)key;
	display = (t_display *)param;
	if (mlx_is_key_down(display->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(display->mlx);
	if (mlx_is_key_down(display->mlx, MLX_KEY_A))
		move_left(display);
	if (mlx_is_key_down(display->mlx, MLX_KEY_D))
		move_right(display);
	if (mlx_is_key_down(display->mlx, MLX_KEY_W))
		move_forwards(display);
	if (mlx_is_key_down(display->mlx, MLX_KEY_S))
		move_backwards(display);
	if (mlx_is_key_down(display->mlx, MLX_KEY_LEFT))
		display->p_angle -= ROTATE;
	if (mlx_is_key_down(display->mlx, MLX_KEY_RIGHT))
		display->p_angle += ROTATE;
	if (is_2pi(display->p_angle))
		display->p_angle = 0;
	draw_compass(display, display->raycast->compass, display->raycast->player);
	run_raycast(display, display->raycast->ray, display->raycast->player);
}

void	init_player_dir(t_player *player)
{
	if (player->pos_start == 'N' || player->pos_start == 'S')
		norsh(player);
	else if (player->pos_start == 'W' || player->pos_start == 'E')
		west(player);
}
