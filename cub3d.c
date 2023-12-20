/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:41:39 by gloms             #+#    #+#             */
/*   Updated: 2023/12/19 20:05:08 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_display *display;

	display = malloc(sizeof(t_display));
	display->mlx = mlx_init(25 * 64, 25 * 64, "cub3d", true);
}
