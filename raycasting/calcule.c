/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 00:46:50 by oliove            #+#    #+#             */
/*   Updated: 2024/05/30 20:47:56 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_camera(t_display *d, t_camera *camera)
{
    camera->angle_cam = atan2(d->raycast->player->dir.y, d->raycast->player->dir.x) * 180 / PI;
    camera->angle_min = d->raycast->player->angle - FOV / 2;
    camera->angle_max = d->raycast->player->angle + FOV / 2;
    camera->nb_ray = 2; // a changer peut etre "WIDTH"-> ou += / 10;
    camera->angle_ray = FOV / camera->nb_ray;
    camera->dir.x = d->raycast->player->dir.x;
    camera->plane.x = d->raycast->player->dir.y * tan(FOV / 2 * PI / 180); // je met ca de cote pour le moment je vais voir 
    // camera->plane.y = d->display->player->dir.x * tan(FOV / 2 * PI / 180);// juste avec angle et dir
}

void init_player_dir(t_player *player)
{
    // print_addr("in init_player_dir player->pos_start",&player->pos_start);
    if (player->pos_start == 'N')
    {
        player->dir.x = -1;
        player->dir.y = 0;
        player->plane.x = 0;
        player->plane.y = 0.66;
    }
    else if (player->pos_start == 'S')
    {
        player->dir.x = 1;
        player->dir.y = 0;
        player->plane.x = 0;
        player->plane.y = -0.66;
    }
    else if (player->pos_start == 'W')
    {
        player->dir.x = 0;
        player->dir.y = -1;
        player->plane.x = -0.66;
        player->plane.y = 0;
    }
    else if (player->pos_start == 'E')
    {
        player->dir.x = 0;
        player->dir.y = 1;
        player->plane.x = 0.66;
        player->plane.y = 0;
    }
}

void init_dda(t_ray *ray, t_player *player)
{
    printf("player->pos (%f,%f)\n",player->pos.x,player->pos.y);
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1ray->dir (%f,%f)\n",ray->dir.x,ray->dir.y);
    printf("ray->map (%d,%d)\n",ray->map.x,ray->map.y);
    if (ray->dir.x < 0)
    {
        ray->step.x = -1;
        ray->side_dist.x = (player->pos.x - ray->map.x) * ray->delta_dist.x;
    }
    else
    {
        ray->step.x = 1;
        ray->side_dist.x = (ray->map.x + 1.0 - player->pos.x) * ray->delta_dist.x;
    }
    if (ray->dir.y < 0)
    {
        ray->step.y = -1;
        ray->side_dist.y = (player->pos.y - ray->map.y) * ray->delta_dist.y;
    }
    else
    {
        ray->step.y = 1;
        ray->side_dist.y = (ray->map.y + 1.0 - player->pos.y) * ray->delta_dist.y;
    }
}

void calculate_height_line(t_ray *ray, t_player *player)
{
    if (ray->side == 0)
        ray->wall_dist = (ray->side_dist.x - ray->delta_dist.x);
    else
        ray->wall_dist = (ray->side_dist.y - ray->delta_dist.y);
    ray->line_height = (int)(HEIGHT / ray->wall_dist);
    ray->draw_start = -ray->line_height / 2 + (int)HEIGHT / 2;
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    ray->draw_end = ray->line_height / 2 + (int)HEIGHT / 2;
    if (ray->draw_end >= HEIGHT)
        ray->draw_end = HEIGHT - 1;
    if (ray->side == 0)
        ray->wall_x = player->pos.y + ray->wall_dist * ray->dir.y;
    else
        ray->wall_x = player->pos.x + ray->wall_dist * ray->dir.x;
    ray->wall_x -= floor(ray->wall_x);
}

void calculate_dda(t_display *display, t_ray *ray)
{
    int hit;
    int tile;

	tile = display->m->tile_size;
    hit  = 0;
    while (hit == 0)
    {
        if (ray->side_dist.x < ray->side_dist.y)
        {
            ray->side_dist.x += ray->delta_dist.x;
            ray->map.x += ray->step.x;
            ray->side = 0;
        }
        else
        {
            ray->side_dist.y += ray->delta_dist.y;
            ray->map.y += ray->step.y;
            ray->side = 1;
        }
        printf("ray->map.y = %d\n",ray->map.y);
        printf("ray->map.x = %d\n",ray->map.x);
        if (display->m->minimap_array[ray->map.y / tile ][ray->map.x / tile ] == '1'){
            printf("Hit wall\n");
            hit = 1;
        }
    }

}

void run_raycast(t_display *display, t_ray *ray, t_player *player)
{
    int x;
    t_vec_d end_pos;
    x = 0;

    // player->angle = display->p_angle;
    // player->pos.x = display->p_x;
    // player->pos.y = display->p_y;
    while (x < WIDTH)
    {
        ray->angle = player->angle + FOV / 2 - x * FOV / WIDTH;
        
        double ray_angle_rad = ray->angle * PI / 180;
        printf("ray_angle_rad = %f\n",ray_angle_rad);
        ray->dir.x = cos(ray_angle_rad);
        ray->dir.y = sin(ray_angle_rad);
        printf("COS_&&_SIN ray->dir.x = %f ray->dir.y = %f\n",ray->dir.x,ray->dir.y);
        // ray->dir.x = player->dir.x + player->plane.x * tan(ray->angle * PI / 180);
        // ray->dir.y = player->dir.y + player->plane.y * tan(ray->angle * PI / 180);
        printf("+PLANE ray->dir.x = %f ray->dir.y = %f\n",ray->dir.x,ray->dir.y);
        
        ray->map.x = (int)player->pos.x;// display->m->tile_size;
        ray->map.y = (int)player->pos.y;// display->m->tile_size;
        printf("ray->map.x = %d ray->map.y = %d\n",ray->map.x,ray->map.y);
        ray->delta_dist.x = sqrt(1 + (ray->dir.y * ray->dir.y) / (ray->dir.x * ray->dir.x));
        ray->delta_dist.y = sqrt(1 + (ray->dir.x * ray->dir.x) / (ray->dir.y * ray->dir.y));
        init_dda(ray, player);
        calculate_dda(display, ray);
        calculate_height_line(ray, player);
        
        int max_ray_lenght = 100;
        end_pos = (t_vec_d){ray->map.x, ray->map.y};
        
        if (hypot(end_pos.x - player->pos.x, end_pos.y - player->pos.y) > max_ray_lenght)
        {
            end_pos.x = player->pos.x + max_ray_lenght * ray->dir.x;
            end_pos.y = player->pos.y + max_ray_lenght * ray->dir.y;
        }
        printf("display->m->tile_size = %d\n",display->m->tile_size);
        printf("ray->angle = %f\n",ray->angle);
        printf("pos.x = %f pos.y = %f\n",player->pos.x, player->pos.y);
        printf("map.x = %d map.y = %d\n",ray->map.x, ray->map.y);
        printf("end_pos.x = %f end_pos.y = %f\n",end_pos.x, end_pos.y);

        double scale = display->m->tile_size;
        t_vec_d start = (t_vec_d){player->pos.x * scale, player->pos.y * scale};
        t_vec_d end = (t_vec_d){end_pos.x * scale, end_pos.y * scale};
        draw_line(display->raycast->ray->img,(t_vec_d){start.x, start.y}, (t_vec_d){end.x, end.y }, MY_RED);
        // draw_line(display->raycast->ray->img, (t_vec_d){player->pos.x * SCALE, player->pos.y * SCALE}, (t_vec_d){ray->map.x * SCALE, ray->map.y * SCALE}, MY_RED);
        // draw_line(display->raycast->ray->img, (t_vec_d){player->pos.x, player->pos.y}, (t_vec_d){ray->map.x, ray->map.y}, MY_RED);
        // draw_line(display->mlx, (t_vec_d){}, x);
        x++;
    }
    // mlx_image_to_window(display->mlx, ray->img,0,0);
}

