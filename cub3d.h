/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:06:55 by gloms             #+#    #+#             */
/*   Updated: 2023/12/28 18:55:51 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "MLX42/include/MLX42/MLX42.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>


/*-------------STRUCTS-------------*/

typedef struct s_display
{
	mlx_t			*mlx;
	int32_t			width;
	int32_t			height;
}	t_display;

/*--------------TEMP--------------*/


#endif
