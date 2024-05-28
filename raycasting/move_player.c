/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:52:56 by gloms             #+#    #+#             */
/*   Updated: 2024/05/28 03:05:45 by oliove           ###   ########.fr       */
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
		display->raycast->ray->img->instances[0].x -= SPEED;
	if (mlx_is_key_down(display->mlx, MLX_KEY_D))
		display->raycast->ray->img->instances[0].x += SPEED;
	if (mlx_is_key_down(display->mlx, MLX_KEY_W)){
		display->raycast->ray->img->instances[0].y -= SPEED;
		run_raycast(display, display->raycast->ray, display->raycast->player);
	}
	if (mlx_is_key_down(display->mlx, MLX_KEY_S))
		display->raycast->ray->img->instances[0].y += SPEED;
	// run_raycast(display, display->raycast->ray, display->raycast->player);
	// printf("x: %d, y: %d\n", display->m->player->instances[0].x,
		// display->m->player->instances[0].y);
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
	draw_compass(display, display->raycast->compass, display->raycast->player);
	// printf("angle: %f\n", display->m->p_angle);
}
