/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:41:39 by gloms             #+#    #+#             */
/*   Updated: 2023/12/28 19:50:12 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_display *display;

	display = malloc(sizeof(t_display));
	mlx_get_monitor_size(0, &display->width, &display->height);
	printf("width : %d\n", (int)display->width);
	printf("height: %d\n", (int)display->height);
	// display->mlx = mlx_init(25*64, 25*64, "cub3d", false);
	// mlx_loop(display->mlx);
}
