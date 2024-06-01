/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:52:56 by gloms             #+#    #+#             */
/*   Updated: 2024/06/01 04:03:30 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
		display->p_angle -= 0.04;
	if (mlx_is_key_down(display->mlx, MLX_KEY_RIGHT))
		display->p_angle += 0.04;
	if (is_2pi(display->p_angle))
		display->p_angle = 0;
	draw_compass(display, display->raycast->compass, display->raycast->player);
	//run_raycast(display, display->raycast->ray, display->raycast->player);
}
