/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:52:56 by gloms             #+#    #+#             */
/*   Updated: 2024/05/30 02:28:05 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_player(void *param)
{
	t_display	*display;

	display = (t_display *)param;
	//printf("%f cos: %f ; sin: %f\n", display->p_angle, cos(display->p_angle), sin(display->p_angle));
	if (mlx_is_key_down(display->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(display->mlx);
	if (mlx_is_key_down(display->mlx, MLX_KEY_A))
		move_left(display);//display->m->player->instances[0].x -= SPEED;
	if (mlx_is_key_down(display->mlx, MLX_KEY_D))
		move_right(display);//display->m->player->instances[0].x += SPEED;
	if (mlx_is_key_down(display->mlx, MLX_KEY_W))
		move_forwards(display);//display->m->player->instances[0].y -= SPEED;
	if (mlx_is_key_down(display->mlx, MLX_KEY_S))
		move_backwards(display);//display->m->player->instances[0].y += SPEED;
	printf("x: %f ; y: %f\n", display->p_x, display->p_y);
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
		display->p_angle -= 0.41;
	if (mlx_is_key_down(display->mlx, MLX_KEY_RIGHT))
		display->p_angle += 0.04;
	if (is_2pi(display->p_angle))
		display->p_angle = 0;
	draw_compass(display, display->raycast->compass, display->raycast->player);
	// printf("angle: %f\n", display->m->p_angle);
}
