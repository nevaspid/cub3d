/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:52:56 by gloms             #+#    #+#             */
/*   Updated: 2024/06/10 09:15:36 by oliove           ###   ########.fr       */
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


void	player_angle(void *param)
{
	t_display	*display;
	// t_vec_d		p;
	
	display = (t_display *)param;
	// p.x = display->raycast->player->pos.x;
	// p.y = display->raycast->player->pos.y;
	// if (check_next_move(display, display->raycast->player->pos.x + cos(display->p_angle) * SPEED, display->raycast->player->pos.y + sin(display->p_angle) * SPEED) == 0)
	// {		
		if (mlx_is_key_down(display->mlx, MLX_KEY_ESCAPE))
			mlx_close_window(display->mlx);
		if ( mlx_is_key_down(display->mlx, MLX_KEY_A))
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
	// }
	draw_compass(display, display->raycast->compass, display->raycast->player);
	run_raycast(display, display->raycast->ray, display->raycast->player);
}
void move_rotated(mlx_key_data_t key, void *param)
{
	(void)key;
	t_display	*display;
	display = (t_display *)param;
	// t_vec_d		p;
	// p.x = display->raycast->player->pos.x;
	// p.y = display->raycast->player->pos.y;
	// if (check_next_move(display, p.x, p.y) == 0)
	// {
	// 	display->raycast->player->pos.x += cos(angle) * SPEED;
	// 	display->raycast->player->pos.y += sin(angle) * SPEED;
	// }
	if (mlx_is_key_down(display->mlx, MLX_KEY_LEFT))
		display->p_angle -= ROTATE;
	if (mlx_is_key_down(display->mlx, MLX_KEY_RIGHT))
		display->p_angle += ROTATE;
	if (is_2pi(display->p_angle))
		display->p_angle = 0;
	print_value_recast(display->raycast->player, display->raycast->ray, "move_rotated", "move_rotated");
	return ;
}

void	move_player(mlx_key_data_t key, void *param)
{
	t_display	*display;
	// t_vec_d		p;
	(void)key;
	display = (t_display *)param;
	// p.x = display->raycast->player->pos.x;
	// p.y = display->raycast->player->pos.y;
	// if (check_next_move(display, display->raycast->player->pos.x + cos(display->p_angle) * SPEED, display->raycast->player->pos.y + sin(display->p_angle) * SPEED) == 0)
	// {		
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
	// }
	draw_compass(display, display->raycast->compass, display->raycast->player);
	run_raycast(display, display->raycast->ray, display->raycast->player);
}


void rotate_player(t_player *player, double rotSpeed)
{
    double oldDirX = player->dir.x;
    player->dir.x = player->dir.x * cos(rotSpeed) - player->dir.y * sin(rotSpeed);
    player->dir.y = oldDirX * sin(rotSpeed) + player->dir.y * cos(rotSpeed);

    double oldPlaneX = player->plane.x;
    player->plane.x = player->plane.x * cos(rotSpeed) - player->plane.y * sin(rotSpeed);
    player->plane.y = oldPlaneX * sin(rotSpeed) + player->plane.y * cos(rotSpeed);
}