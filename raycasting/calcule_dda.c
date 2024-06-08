/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 00:46:50 by oliove            #+#    #+#             */
/*   Updated: 2024/06/07 02:05:16by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


/*
  _______   ______   _____  ____   _____  ____    ______    ______   ______  
 /       | /      \ /     \/    \ /     \/    \  /      \  /      \ /      \ 
/$$$$$$$/  $$$$$$  |$$$$$$ $$$$  |$$$$$$ $$$$  |/$$$$$$  |/$$$$$$  |$$$$$$  |
$$ |       /    $$ |$$ | $$ | $$ |$$ | $$ | $$ |$$    $$ |$$ |  $$/ /    $$ |
$$ \_____ /$$$$$$$ |$$ | $$ | $$ |$$ | $$ | $$ |$$$$$$$$/ $$ |     /$$$$$$$ |
$$       |$$    $$ |$$ | $$ | $$ |$$ | $$ | $$ |$$       |$$ |     $$    $$ |
 $$$$$$$/  $$$$$$$/ $$/  $$/  $$/ $$/  $$/  $$/  $$$$$$$/ $$/       $$$$$$$/ 
*/

void run_camera(t_display *d, t_camera *camera, t_player *player)
{
    // camera->angle = 0;
    camera->angle_cam = atan2(player->dir.y, player->dir.x) ;//* 180 / M_PI;
    camera->angle_min = player->angle - FOV /2;// angle_rad(FOV) / 2;
    camera->angle_max = player->angle + FOV /2;// angle_rad(FOV) / 2;
    camera->nb_ray = 2; // a changer peut etre "WIDTH"-> ou += / 10;
    camera->angle_ray = FOV / camera->nb_ray;
    camera->dir.x = d->raycast->player->dir.x;
    // camera->plane.x = d->raycast->player->dir.y * tan(FOV / 2 * M_pi/ 180); // je met ca de cote pour le moment je vais voir
    // camera->plane.y = d->display->player->dir.x * tan(FOV / 2 * M_pi/ 180);// juste avec angle et dir
}

/*
 __            __    __                      __                                                __  __           
/  |          /  |  /  |                    /  |                                              /  |/  |          
$$/  _______  $$/  _$$ |_           ______  $$ |  ______   __    __   ______    ______    ____$$ |$$/   ______  
/  |/       \ /  |/ $$   |         /      \ $$ | /      \ /  |  /  | /      \  /      \  /    $$ |/  | /      \ 
$$ |$$$$$$$  |$$ |$$$$$$/         /$$$$$$  |$$ | $$$$$$  |$$ |  $$ |/$$$$$$  |/$$$$$$  |/$$$$$$$ |$$ |/$$$$$$  |
$$ |$$ |  $$ |$$ |  $$ | __       $$ |  $$ |$$ | /    $$ |$$ |  $$ |$$    $$ |$$ |  $$/ $$ |  $$ |$$ |$$ |  $$/ 
$$ |$$ |  $$ |$$ |  $$ |/  |      $$ |__$$ |$$ |/$$$$$$$ |$$ \__$$ |$$$$$$$$/ $$ |      $$ \__$$ |$$ |$$ |      
$$ |$$ |  $$ |$$ |  $$  $$/______ $$    $$/ $$ |$$    $$ |$$    $$ |$$       |$$ |______$$    $$ |$$ |$$ |      
$$/ $$/   $$/ $$/    $$$$//      |$$$$$$$/  $$/  $$$$$$$/  $$$$$$$ | $$$$$$$/ $$//      |$$$$$$$/ $$/ $$/       
                          $$$$$$/ $$ |                    /  \__$$ |             $$$$$$/                        
                                  $$ |                    $$    $$/                                             
                                  $$/                      $$$$$$/                                              
*/
void init_player_dir(t_player *player)
{
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

/*

 __            __    __                 __        __           
/  |          /  |  /  |               /  |      /  |          
$$/  _______  $$/  _$$ |_          ____$$ |  ____$$ |  ______  
/  |/       \ /  |/ $$   |        /    $$ | /    $$ | /      \ 
$$ |$$$$$$$  |$$ |$$$$$$/        /$$$$$$$ |/$$$$$$$ | $$$$$$  |
$$ |$$ |  $$ |$$ |  $$ | __      $$ |  $$ |$$ |  $$ | /    $$ |
$$ |$$ |  $$ |$$ |  $$ |/  |     $$ \__$$ |$$ \__$$ |/$$$$$$$ |
$$ |$$ |  $$ |$$ |  $$  $$/______$$    $$ |$$    $$ |$$    $$ |
$$/ $$/   $$/ $$/    $$$$//      |$$$$$$$/  $$$$$$$/  $$$$$$$/ 
                          $$$$$$/                              
*/

//#-> init_dda
 
void init_dda(t_ray *ray, t_player *player)
{
    (void)player;
    if (ray->dir.x < 0)
    {
        ray->step.x = -1;
        // ray->side_dist.x = (player->pos.x- ray->map.x) * ray->delta_dist.x;
        // ray->side_dist.x = (player->pos.x);
    }
    else
    {
        ray->step.x = 1;
        // ray->side_dist.x = (ray->map.x + 1.0 - player->pos.x) * ray->delta_dist.x;
        // ray->side_dist.x = (player->pos.x);
    }
    if (ray->dir.y < 0)
    {
        ray->step.y = -1;
        // ray->side_dist.y = (player->pos.y - ray->map.y) * ray->delta_dist.y;
        // ray->side_dist.y = (player->pos.y);
    }
    else
    {
        ray->step.y = 1;
        // ray->side_dist.y = (ray->map.y + 1.0 - player->pos.y) * ray->delta_dist.y;
        // ray->side_dist.y = (player->pos.y);
    }
    ray->side_dist.x = 0;
    ray->side_dist.y = 0;
    // int x = 0;
    // print_value_ray(ray, player, "init_dda", "ray",  x++);
}
/*
                     __                      __              __
                    /  |                    /  |            /  |
  _______   ______  $$ |  _______  __    __ $$ |  ______   _$$ |_     ______
 /       | /      \ $$ | /       |/  |  /  |$$ | /      \ / $$   |   /      \
/$$$$$$$/  $$$$$$  |$$ |/$$$$$$$/ $$ |  $$ |$$ | $$$$$$  |$$$$$$/   /$$$$$$  |
$$ |       /    $$ |$$ |$$ |      $$ |  $$ |$$ | /    $$ |  $$ | __ $$    $$ |
$$ \_____ /$$$$$$$ |$$ |$$ \_____ $$ \__$$ |$$ |/$$$$$$$ |  $$ |/  |$$$$$$$$/
$$       |$$    $$ |$$ |$$       |$$    $$/ $$ |$$    $$ |  $$  $$/ $$       |
 $$$$$$$/  $$$$$$$/ $$/  $$$$$$$/  $$$$$$/  $$/  $$$$$$$/    $$$$/   $$$$$$$/
*/

void calculate_height_line(t_ray *ray, t_player *player)
{
    if (ray->side == 0)
        // ray->wall_dist = ray->map.x - player->pos.x + (1 - ray->step.x) / 2 / ray->dir.x;   
        ray->wall_dist = (ray->side_dist.x - ray->delta_dist.x * SPEED);
    else
        // ray->wall_dist = ray->map.y - player->pos.y + (1 - ray->step.y) / 2 / ray->dir.y;
        ray->wall_dist = (ray->side_dist.y - ray->delta_dist.y * SPEED);
        
    ray->wall_dist = ray->wall_dist / fabs(cos(angle_rad(ray->angle )- angle_rad(player->angle) ));// gere le fish eye
    ray->line_height = ((float)HEIGHT / ray->wall_dist);
    ray->draw_start = -ray->line_height / 2.0f + (float)HEIGHT / 2.0f;
    // ray->draw_start = ray->draw_start / cos(ray->angle);
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    ray->draw_end = ray->line_height / 2.0f + (float)HEIGHT / 2.0f;
    // ray->draw_end = ray->draw_end / cos(ray->angle);
    if (ray->draw_end >= HEIGHT)
        ray->draw_end = HEIGHT - 1;
    if (ray->side == 0)
        ray->wall_x = player->pos.y + ray->wall_dist * ray->dir.y;
    else
        ray->wall_x = player->pos.x + ray->wall_dist * ray->dir.x;
    ray->wall_x -= floor(ray->wall_x);
}

void draw_ligne_height(mlx_image_t *img, int x, int star, int end, int color)
{
    int y;

    y = star;
    while ( y < end)
    {
        mlx_put_pixel(img, x, y, color);
        y++;
    }

}

/*
                     __                      __              __                            __        __           
                    /  |                    /  |            /  |                          /  |      /  |          
  _______   ______  $$ |  _______  __    __ $$ |  ______   _$$ |_     ______          ____$$ |  ____$$ |  ______  
 /       | /      \ $$ | /       |/  |  /  |$$ | /      \ / $$   |   /      \        /    $$ | /    $$ | /      \ 
/$$$$$$$/  $$$$$$  |$$ |/$$$$$$$/ $$ |  $$ |$$ | $$$$$$  |$$$$$$/   /$$$$$$  |      /$$$$$$$ |/$$$$$$$ | $$$$$$  |
$$ |       /    $$ |$$ |$$ |      $$ |  $$ |$$ | /    $$ |  $$ | __ $$    $$ |      $$ |  $$ |$$ |  $$ | /    $$ |
$$ \_____ /$$$$$$$ |$$ |$$ \_____ $$ \__$$ |$$ |/$$$$$$$ |  $$ |/  |$$$$$$$$/       $$ \__$$ |$$ \__$$ |/$$$$$$$ |
$$       |$$    $$ |$$ |$$       |$$    $$/ $$ |$$    $$ |  $$  $$/ $$       |______$$    $$ |$$    $$ |$$    $$ |
 $$$$$$$/  $$$$$$$/ $$/  $$$$$$$/  $$$$$$/  $$/  $$$$$$$/    $$$$/   $$$$$$$//      |$$$$$$$/  $$$$$$$/  $$$$$$$/ 
                                                                             $$$$$$/                              
*/

void calculate_dda(t_display *display, t_ray *ray)
{
    int hit;

    hit  = 0;
    while (hit == 0)
    {
        if (ray->side_dist.x < ray->side_dist.y)
        {
            ray->side_dist.x += ray->delta_dist.x * SPEED;
            ray->map.x += ray->step.x * SPEED;
            ray->side = 0;
        }
        else
        {
            ray->side_dist.y += ray->delta_dist.y * SPEED;
            ray->map.y += ray->step.y * SPEED;
            ray->side = 1;
        }
        if (ray->map.y >= 0 || ray->map.x >= 0 || ray->map.y <= display->m->minimap->height || ray->map.x <= display->m->minimap->width)
        {
            if (display->m->minimap_array[(int)ray->map.y][(int)ray->map.x] == '1')
            {
                hit = 1;
                ray->hit = 1;
            }
        }
        else
        {
            hit = 1;
            ray->hit = 1;
        }
    }

}

/*
           __                                 __                                             
          /  |                               /  |                                            
  _______ $$ |  ______    ______    ______   $$/  _____  ____    ______    ______    ______  
 /       |$$ | /      \  /      \  /      \  /  |/     \/    \  /      \  /      \  /      \ 
/$$$$$$$/ $$ |/$$$$$$  | $$$$$$  |/$$$$$$  | $$ |$$$$$$ $$$$  | $$$$$$  |/$$$$$$  |/$$$$$$  |
$$ |      $$ |$$    $$ | /    $$ |$$ |  $$/  $$ |$$ | $$ | $$ | /    $$ |$$ |  $$ |$$    $$ |
$$ \_____ $$ |$$$$$$$$/ /$$$$$$$ |$$ |       $$ |$$ | $$ | $$ |/$$$$$$$ |$$ \__$$ |$$$$$$$$/ 
$$       |$$ |$$       |$$    $$ |$$ |______ $$ |$$ | $$ | $$ |$$    $$ |$$    $$ |$$       |
 $$$$$$$/ $$/  $$$$$$$/  $$$$$$$/ $$//      |$$/ $$/  $$/  $$/  $$$$$$$/  $$$$$$$ | $$$$$$$/ 
                                     $$$$$$/                             /  \__$$ |          
                                                                         $$    $$/           
                                                                          $$$$$$/            
*/

void clear_image(mlx_image_t *img, uint32_t a)
{
    uint32_t x;
    uint32_t y;

    y = 0;

    while (y < img->height)
    {
        x = 0;
        while (x < img->width)
        {
            mlx_put_pixel(img, x, y, a);
            x++;
        }
        y++;
    }
}

/*
                                                                                                   __     
                                                                                                  /  |    
  ______   __    __  _______           ______   ______   __    __   _______   ______    _______  _$$ |_   
 /      \ /  |  /  |/       \         /      \ /      \ /  |  /  | /       | /      \  /       |/ $$   |  
/$$$$$$  |$$ |  $$ |$$$$$$$  |       /$$$$$$  |$$$$$$  |$$ |  $$ |/$$$$$$$/  $$$$$$  |/$$$$$$$/ $$$$$$/   
$$ |  $$/ $$ |  $$ |$$ |  $$ |       $$ |  $$/ /    $$ |$$ |  $$ |$$ |       /    $$ |$$      \   $$ | __ 
$$ |      $$ \__$$ |$$ |  $$ |       $$ |     /$$$$$$$ |$$ \__$$ |$$ \_____ /$$$$$$$ | $$$$$$  |  $$ |/  |
$$ |      $$    $$/ $$ |  $$ |______ $$ |     $$    $$ |$$    $$ |$$       |$$    $$ |/     $$/   $$  $$/ 
$$/        $$$$$$/  $$/   $$//      |$$/       $$$$$$$/  $$$$$$$ | $$$$$$$/  $$$$$$$/ $$$$$$$/     $$$$/  
                             $$$$$$/                    /  \__$$ |                                        
                                                        $$    $$/                                         
                                                         $$$$$$/                                          
*/


void run_raycast(t_display *display, t_ray *ray, t_player *player)
{
    int x;
    t_vec_d end_pos;
    t_camera *camera;
    
   camera = display->raycast->camera;
    x = 0;
    clear_image(display->raycast->ray->img, 0x000000);
    clear_image(display->img, 0x000000);
    ray->angle = camera->angle_min;
    // ray->angle = player->angle - angle_rad(FOV) / 2;
    while (x < WIDTH)
    // while (ray->angle <= player->angle + angle_rad(FOV) / 2)
    {
        camera->camera_x = 2 * x / (double)WIDTH - 1;// sert a faire [plan -1 1]
        
     
        ray->dir.x = cos(ray->angle) + player->plane.x * camera->camera_x;
        ray->dir.y = sin(ray->angle) + player->plane.y * camera->camera_x;
        // ray->dir.x = cos(ray->angle);// + player->plane.x * camera->camera_x;
        // ray->dir.y = sin(ray->angle);// + player->plane.y * camera->camera_x;
        ray->map.x = player->pos.x;
        ray->map.y = player->pos.y;
        ray->delta_dist.x = sqrt(1.0f + (ray->dir.y * ray->dir.y) / (ray->dir.x * ray->dir.x));
        ray->delta_dist.y = sqrt(1.0f + (ray->dir.x * ray->dir.x) / (ray->dir.y * ray->dir.y));
        // ray->delta_dist.x = fabs(1 / ray->dir.x );
        // ray->delta_dist.y = fabs(1 / ray->dir.y);
        init_dda(ray, player);
        calculate_dda(display, ray);
        calculate_height_line(ray, player);
        
        int max_ray_lenght = 5;
        end_pos = (t_vec_d){ray->map.x , ray->map.y};
        if (hypot(ray->map.x - player->pos.x, ray->map.y - player->pos.y) > max_ray_lenght)
        {
            end_pos.x = player->pos.x + max_ray_lenght * ray->dir.x;
            end_pos.y = player->pos.y + max_ray_lenght * ray->dir.y;
        }
        if (ray->angle != player->angle)
            draw_line(display->raycast->ray->img, (t_vec_d){player->pos.x * display->m->tile_size, player->pos.y * display->m->tile_size},
                                                (t_vec_d){end_pos.x * display->m->tile_size, end_pos.y * display->m->tile_size}, MY_RED);
        else
            draw_line(display->raycast->ray->img, (t_vec_d){player->pos.x * display->m->tile_size, player->pos.y * display->m->tile_size},
                                                (t_vec_d){end_pos.x * display->m->tile_size, end_pos.y * display->m->tile_size}, 0x800080);
        // print_value_ray(ray, player, "calculate_height_line", "ray",x++);
        draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, MY_WHITE);
        ray->angle += 0.0015; 
        x++;
   
    }
    print_value_player(display->raycast->player, "run_raycast", "player");
    print_value_camera(display->raycast->camera, "run_raycast", "camera");
    mlx_image_to_window(display->mlx, display->img,0,0);
    // display->img->instances[0].z = 0;
}


double re_distance(double ax, double ay, double bx, double by)
{
    return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}