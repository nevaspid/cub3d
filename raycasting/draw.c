/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:56:32 by oliove            #+#    #+#             */
/*   Updated: 2024/06/22 18:06:58 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_bg(t_display *display, mlx_image_t *img)
{
    (void)display;
    int x;
    int y;

    y = 0;
    while (y < HEIGHT)
    {
        // uint32_t color;
        x = 0;
        // printf("y [%d]\n", y);
        while (x < WIDTH)
        {
            // printf("x [%d]\n", x);
            if (y < HEIGHT / 2){
                
                // color = get_color(display,display->raycast->assets->ceiling , x, y);
                mlx_put_pixel(img, x, y, MY_BLACK);
            }
            else
                mlx_put_pixel(img, x, y, MY_RED);
            x++;
        }
        y++;
    }
}


void draw_wall_orientation(t_display *display, t_ray *ray,int x)
{
//     uint32_t d_color;
//     double t = InverseLerp(0, WIDTH, x);
//     Lerp(0,display->raycast->asset->ceiling->width,t );
//     d_color = get_color(x, (int)t, display->raycast->asset->ceiling);
    // d_color = get_color(display, display->raycast->assets->ceiling, ray->draw_start, x);
    if (ray->side == 1){
        if (ray->step.y > 0){
            // draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, d_color);
            draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, MY_WHITE);
        } 
        else
            draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, MAGENTA);
    }
    else{
        if(ray->step.x > 0)
            draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, ORANGE);
        else 
            draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, BLUE);
    }
    // get_tex_scale(display, display->raycast->assets->ceiling, x, 1);
}

