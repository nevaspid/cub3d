/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 01:21:22 by oliove            #+#    #+#             */
/*   Updated: 2024/05/27 23:53:01 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_struct(t_display *display)
{
    (void)display;
    // Pour plus tard, j'y metterai toute les alloc
   
}

void init_player(t_display *display, t_player *player)
{
    player->pos.x = display->m->player->instances[0].x;
    player->pos.y = display->m->player->instances[0].y;
    player->angle = display->m->p_angle;
    player->dir.x = 0;
    player->dir.y = 0;
    player->plane.x = 0;
    player->plane.y = 0;

}

void init_ray(t_ray *ray)
{
    ray->dir.x = 0;
    ray->dir.y = 0;
    ray->draw_end = 0;
    ray->draw_start = 0;
    ray->step.x = 0;
    ray->step.y = 0;
    ray->map.x = 0;
    ray->map.y = 0;
    ray->delta_dist.x = 0;
    ray->delta_dist.y = 0;
    ray->wall_dist = 0;
    ray->line_height = 0;
    ray->side = 0;
    ray->hit = 0;
    ray->hit_side = 0;
    ray->angle = 0;
    ray->fov = 0;
    ray->wall_x = 0;
    ray->prev_ray.x = 0;
    ray->prev_ray.y = 0;
    ray->nb_ray = 0;
    ray->start.x = 0;
    ray->start.y = 0;
    ray->end.x = 0;
    ray->end.y = 0;
}

void init_camma(t_camera *camera)
{
    camera->angle_cam = 0;
    camera->angle_min = 0;
    camera->angle_max = 0;
    camera->angle_ray = 0;
    camera->dir.x = 0;
    camera->dir.y = 0;
    camera->nb_ray = 0;
    camera->plane.x = 0;
    camera->plane.y = 0;
}

void init_layers(t_display *data)
{
    t_raycast *raycast;

    raycast = data->raycast;
    raycast->compass->img = mlx_new_image(data->mlx, WIDTH * SCALE, HEIGHT * SCALE);
}


void init_compass(t_compass *cmp)
{
   cmp->radius = 100;
   cmp->center_x = (WIDTH - cmp->radius) - 1;
   cmp->center_y = cmp->radius;
   cmp->needle_length = cmp->radius * 0.8;
}


void draw_line(mlx_image_t *img, t_vec_d start, t_vec_d end, int color)
{
    t_line l;
  
    l.x1 = start.x;
    l.y1 = start.y;
    l.x2 = end.x;
    l.y2 = end.y;    
    l.dx = abs(l.x2 - l.x1);
    l.dy = abs(l.y2 - l.y1);
    if (l.x1 < l.x2)
        l.sx = 1;
    else
        l.sx = -1;
    if (l.y1 < l.y2)
        l.sy = 1;
    else
        l.sy = -1;
    l.err = l.dx - l.dy;
    if (l.x1 < 0 || l.x1 >= WIDTH || l.x2 < 0 || l.x2 >= WIDTH || l.y1 < 0 || l.y1 >= HEIGHT || l.y2 < 0 || l.y2 >= HEIGHT) {
        return;
    }
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


void draw_circle(mlx_image_t *img, int center_x, int center_y, int radius, int color, int fill)
{
    int x;
    int y;
    int d;
    
    y = radius;
    x = 0;
    d = 3 - 2 * radius;
    while (x <= y)
    {
        if(fill == 1){
            draw_fill_circle(img, center_x - x, center_x + x, center_y + y, MY_BLACK);
            draw_fill_circle(img, center_x - x, center_x + x, center_y - y, MY_BLACK);
            draw_fill_circle(img, center_x - y, center_x + y, center_y + x, MY_BLACK);
            draw_fill_circle(img, center_x - y, center_x + y, center_y - x, MY_BLACK);   
        }
        mlx_put_pixel(img, center_x + x,center_y + y, color);
        mlx_put_pixel(img, center_x + x, center_y + y, color);
        mlx_put_pixel(img, center_x - x, center_y + y, color);
        mlx_put_pixel(img, center_x + x, center_y - y, color);
        mlx_put_pixel(img, center_x - x, center_y - y, color);
        mlx_put_pixel(img, center_x + y, center_y + x, color);
        mlx_put_pixel(img, center_x - y, center_y + x, color);
        mlx_put_pixel(img, center_x + y, center_y - x, color);
        mlx_put_pixel(img, center_x - y, center_y - x, color);

        if (d < 0)
            d = d + 4 * x + 6;
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}


void draw_compass(t_display *display, t_compass *compass , t_player *player)
{
    init_player(display,player);
    init_compass(compass);
    draw_circle(compass->img,compass->center_x, compass->center_y, compass->radius, MY_WHITE,1);
    draw_circle(compass->img,compass->center_x, compass->center_y, compass->radius -2 , MY_BLACK,0);
    draw_circle(compass->img,compass->center_x, compass->center_y, compass->radius - 1, MY_WHITE,0);
    
    compass->needle_length = compass->radius * 0.8;
    compass->needle_end_x = compass->center_x + compass->needle_length * cos(player->angle);
    compass->needle_end_y = compass->center_y + compass->needle_length * sin(player->angle);
    draw_line(compass->img, (t_vec_d){compass->center_x, compass->center_y}, (t_vec_d){compass->needle_end_x, compass->needle_end_y}, MY_RED);
    mlx_put_pixel(compass->img, compass->center_x, compass->center_y, MY_WHITE);
    mlx_image_to_window(display->mlx, compass->img, WIDTH /2,0);
}
