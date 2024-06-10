/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:56:32 by oliove            #+#    #+#             */
/*   Updated: 2024/06/10 05:13:42 by oliove           ###   ########.fr       */
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


void draw_wall_orientation(t_display *display, t_ray *ray,int x)
{
    if (ray->side == 1){
        if (ray->step.y > 0) 
            draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, MY_WHITE);
        else
            draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, MAGENTA);
    }
    else{
        if(ray->step.x > 0)
            draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, ORANGE);
        else 
            draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, BLUE);
    } 
}
