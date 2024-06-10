/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:22:10 by oliove            #+#    #+#             */
/*   Updated: 2024/06/09 23:49:53 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double angle_rad(double angle)
{
    return (angle * M_PI / 180);
}

double distance(t_vec_d a, t_vec_d b)
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

t_direction getRay_direction(float x0, float y0, float x1, float y1) 
{
    float dx;
    float dy;

   
    dy = y1 - y0;
    dx = x1 - x0;
    if (fabs(dx) > fabs(dy)) {
        if (dx > 0) {
            return EAST;
        } else {
            return WEST;
        }
    }
    else {
        if (dy > 0) {
            return SOUTH;
        } else {
            return NORTH;
        }
    }
}


// void render_floor(t_display *d, t_ray *ray, t_player *player)
// {
//     int x;
//     int y;
//     int color;
//     (void)player;
//     (void)ray;

//     while (y < HEIGHT)
//     {
//         y = HEIGHT / 2;
        
//         while (x < WIDTH)
//         {
//             color = 0x000000;
//             mlx_pixel_put(d->mlx, x, y, color);
//             x++;
//         }
//         y++;
//     }
    
    
// }
