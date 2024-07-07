/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_primitive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 06:10:51 by oliove            #+#    #+#             */
/*   Updated: 2024/07/08 01:42:40 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void set_line(t_line *l, t_vec_d start, t_vec_d end)
{
    l->x1 = start.x;
    l->y1 = start.y;
    l->x2 = end.x;
    l->y2 = end.y;
    l->dx = abs(l->x2 - l->x1);
    l->dy = abs(l->y2 - l->y1);
    if (l->x1 < l->x2)
        l->sx = 1;
    else
        l->sx = -1;
    if (l->y1 < l->y2)
        l->sy = 1;
    else
        l->sy = -1;
    l->err = l->dx - l->dy;
    if (l->x1 < 0 || l->x1 >= WIDTH || l->x2 < 0 || l->x2 >= WIDTH || l->y1 < 0 || l->y1 >= HEIGHT || l->y2 < 0 || l->y2 >= HEIGHT) {
        return;
    }
}


void draw_line(mlx_image_t *img, t_vec_d start, t_vec_d end, int color)
{
    t_line l;

    set_line(&l, start, end);
    while (1)
    {
        mlx_put_pixel(img, l.x1, l.y1, color);
        if (l.x1 == l.x2 && l.y1 == l.y2)
            break;
        l.err2 = 2 * l.err;
        if (l.err2 > -l.dy)
        {
            l.err -= l.dy;
            l.x1 += l.sx;
        }
        if (l.err2 < l.dx)
        {
            l.err += l.dx;
            l.y1 += l.sy;
        }
    }
}

void draw_fill_circle(mlx_image_t *img, int x1, int x2, int y,  int color)
{
    while (x1 <= x2)
    {
        mlx_put_pixel(img, x1, y, color);
        mlx_put_pixel(img, x2, y, color);
        x1++;
        x2--;
    }
}

static void fill_circle(t_compass *compass, int x, int y, int color)
{
    draw_fill_circle(compass->img, compass->center_x - x, compass->center_x + x, compass->center_y + y, color);
    draw_fill_circle(compass->img, compass->center_x - x, compass->center_x + x, compass->center_y - y, color);
    draw_fill_circle(compass->img, compass->center_x - y, compass->center_x + y, compass->center_y + x, color);
    draw_fill_circle(compass->img, compass->center_x - y, compass->center_x + y, compass->center_y - x, color);
}

void draw_circle(t_compass *compass, int radius, int color, int fill)
{
    int x;
    int y;
    int d;

    y = radius;
    x = 0;
    d = 3 - 2 * radius;
    while (x <= y)
    {
        if(fill == 1)
            fill_circle(compass,x, y, MY_BLACK);
        mlx_put_pixel(compass->img, compass->center_x + x,compass->center_y + y, color);
        mlx_put_pixel(compass->img, compass->center_x + x,compass->center_y + y, color);
        mlx_put_pixel(compass->img, compass->center_x - x,compass->center_y + y, color);
        mlx_put_pixel(compass->img, compass->center_x + x,compass->center_y - y, color);
        mlx_put_pixel(compass->img, compass->center_x - x,compass->center_y - y, color);
        mlx_put_pixel(compass->img, compass->center_x + y,compass->center_y + x, color);
        mlx_put_pixel(compass->img, compass->center_x - y,compass->center_y + x, color);
        mlx_put_pixel(compass->img, compass->center_x + y,compass->center_y - x, color);
        mlx_put_pixel(compass->img, compass->center_x - y,compass->center_y - x, color);
        printf("d = %d x = %d, y = %d\n",d, x, y);
        // d = ajuste(d, x, y);
        if (d < 0)
            d = d + 4 * x + 6;
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        printf("d = %d\n\n",d);
        x++;
    }
}

int ajuste(int d, int x, int y)
{
    if (d < 0)
        d = d + 4 * x + 6;
    else
    {
        d = d + 4 * (x - y) + 10;
        y--;
    }
    printf("\033[1;31md = %d x = %d, y = %d\033[0m\n",d, x, y);
    return (d);
}

// void draw_circle(mlx_image_t *img, int center_x, int center_y, int radius, int color, int fill)
// {
//     int x;
//     int y;
//     int d;

//     y = radius;
//     x = 0;
//     d = 3 - 2 * radius;
//     while (x <= y)
//     {
//         if(fill == 1){
//             draw_fill_circle(img, center_x - x, center_x + x, center_y + y, MY_BLACK);
//             draw_fill_circle(img, center_x - x, center_x + x, center_y - y, MY_BLACK);
//             draw_fill_circle(img, center_x - y, center_x + y, center_y + x, MY_BLACK);
//             draw_fill_circle(img, center_x - y, center_x + y, center_y - x, MY_BLACK);
//         }
//         mlx_put_pixel(img, center_x + x,center_y + y, color);
//         mlx_put_pixel(img, center_x + x, center_y + y, color);
//         mlx_put_pixel(img, center_x - x, center_y + y, color);
//         mlx_put_pixel(img, center_x + x, center_y - y, color);
//         mlx_put_pixel(img, center_x - x, center_y - y, color);
//         mlx_put_pixel(img, center_x + y, center_y + x, color);
//         mlx_put_pixel(img, center_x - y, center_y + x, color);
//         mlx_put_pixel(img, center_x + y, center_y - x, color);
//         mlx_put_pixel(img, center_x - y, center_y - x, color);

//         if (d < 0)
//             d = d + 4 * x + 6;
//         else
//         {
//             d = d + 4 * (x - y) + 10;
//             y--;
//         }
//         x++;
//     }
// }


void draw_compass(t_display *display, t_compass *compass , t_player *player)
{
    init_value_st(display);
    draw_circle(compass, compass->radius, MY_WHITE,1);
    draw_circle(compass, compass->radius -2 , MY_BLACK,0);
    draw_circle(compass, compass->radius - 1, MY_WHITE,0);

    compass->needle_length = compass->radius * 0.8;
    compass->needle_end_x = compass->center_x + compass->needle_length * cos(player->angle);
    compass->needle_end_y = compass->center_y + compass->needle_length * sin(player->angle);
    draw_line(compass->img, (t_vec_d){compass->center_x, compass->center_y}, (t_vec_d){compass->needle_end_x, compass->needle_end_y}, MY_RED);
    mlx_put_pixel(compass->img, compass->center_x, compass->center_y, MY_WHITE);
}

// void draw_compass(t_display *display, t_compass *compass , t_player *player)// original
// {
//     init_value_st(display);
//     draw_circle(compass->img,compass->center_x, compass->center_y, compass->radius, MY_WHITE,1);
//     draw_circle(compass->img,compass->center_x, compass->center_y, compass->radius -2 , MY_BLACK,0);
//     draw_circle(compass->img,compass->center_x, compass->center_y, compass->radius - 1, MY_WHITE,0);

//     compass->needle_length = compass->radius * 0.8;
//     compass->needle_end_x = compass->center_x + compass->needle_length * cos(player->angle);
//     compass->needle_end_y = compass->center_y + compass->needle_length * sin(player->angle);
//     draw_line(compass->img, (t_vec_d){compass->center_x, compass->center_y}, (t_vec_d){compass->needle_end_x, compass->needle_end_y}, MY_RED);
//     mlx_put_pixel(compass->img, compass->center_x, compass->center_y, MY_WHITE);
// }
