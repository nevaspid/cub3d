/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:56:32 by oliove            #+#    #+#             */
/*   Updated: 2024/06/09 17:30:04 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"



void draw_bg(t_display *display, mlx_image_t *img)
{
    (void)display;
    int x;
    int y;

    y = 0;
    while (y <= HEIGHT)
    {
        x = 0;
        while (x <= WIDTH)
        {
            if (y < HEIGHT / 2)
                mlx_put_pixel(img, x, y, MY_BLACK);
            else
                mlx_put_pixel(img, x, y, MY_RED);
            x++;
        }
        y++;
    }
}


void draw_wall_orientation(t_display *display, t_ray *ray, t_direction dir, int x)
{

    if (dir == NORTH || dir == SOUTH)
    {
        if (dir == NORTH)
            draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, MY_WHITE);
        else
            draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, MY_BLACK);
    }
    else
    {
        if (dir == EAST)
            draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, 0xFFC0CBFF);
        else
            draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, ORANGE);
    }
}


// void draw_3d(t_display *display, t_camera *camera, int x, t_player *player)
// {

    

// }