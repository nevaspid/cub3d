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
    camera->angle_cam = atan2(player->dir.y, player->dir.x) ;//* 180 / M_PI;
    camera->angle_min = player->angle - FOV /2;// angle_rad(FOV) / 2;
    camera->angle_max = player->angle + FOV /2;// angle_rad(FOV) / 2;
    camera->nb_ray = 2; // a changer peut etre "WIDTH"-> ou += / 10;
    camera->angle_ray = FOV / camera->nb_ray;
    camera->dir.x = d->raycast->player->dir.x;
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
        ray->step.x = -1;
    else
        ray->step.x = 1;
    if (ray->dir.y < 0)
        ray->step.y = -1;
    else
        ray->step.y = 1;
    ray->side_dist.x = 0;
    ray->side_dist.y = 0;
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
        ray->wall_dist = (ray->side_dist.x - ray->delta_dist.x * V_MAGIE);
    else
        ray->wall_dist = (ray->side_dist.y - ray->delta_dist.y * V_MAGIE);
    ray->line_height = ((int)HEIGHT / ray->wall_dist);
    ray->line_height = ray->line_height / cos(ray->angle - player->angle);
    ray->draw_start = -ray->line_height / 2.0f + (int)HEIGHT / 2.0f;
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    ray->draw_end = ray->line_height / 2.0f + (int)HEIGHT / 2.0f;
    if (ray->draw_end >= HEIGHT)
        ray->draw_end = HEIGHT - 1;
    if (ray->side == 0)
        ray->wall_x = player->pos.y + ray->wall_dist * ray->dir.y;
    else
        ray->wall_x = player->pos.x + ray->wall_dist * ray->dir.x;
    ray->wall_x -= floor(ray->wall_x);
    // printf("ray->wall_x = %d\n", ray->wall_x);
}

// void draw_ligne_height(t_display *display , mlx_image_t *img, int x, int star, int end)
// {
//     int y;
//     // // int tex_x;
//     // double t;
//     // // u_int32_t d_color;
//     t_ray *ray = display->raycast->ray;
//     // // t_texture *tex = display->raycast->text;
//     double r = 1.0 * (end - star) / img->height;
//     // // tex_x = (int)(ray->wall_x * (double)tex->west_img->width);
//     // t = InverseLerp(0, WIDTH, ray->wall_x);
//     // Lerp(0,display->raycast->text->west_img->width,t);
//     // d_color = 
//     t_texture *tmp = malloc(sizeof(t_texture));

//     get_text(display, display->raycast->ray, tmp);



//     y = star;
//     printf("star = %d\n", star);
//     printf("y - star = %d\n", y - star);

//     while ( y < end)
//     {
//         if (y < 192)
//             mlx_put_pixel(img, x, y ,get_color(ray->wall_x, (y ) / r, display->raycast->text->west_img));
//         // printf("r = %f\n", r);
//         // printf("y = %d x = %d\n", y,x);
//         // printf("ray->wall_x = %d\n", ray->wall_x);

//         y++;
//     }
//     free(tmp);
// }

// void draw_ligne_height(mlx_image_t *img, int x, int star, int end, int color) // original function
// {
//     int y;

//     // (void)color;
//     // u_int32_t d_color;
//     // d_color = get_color(x, (int)t, display->raycast->text->west_img);
//     y = star;
//     while ( y < end)
//     {
//         mlx_put_pixel(img, x, y, color);
//         y++;
//     }

// }
void draw_ligne_height(t_display *display , mlx_image_t *img, int x, int star, int end, int color, int flags)
{
    int y;

    // (void)color;
    // u_int32_t d_color;
    
    double t;

    t = InverseLerp(0, WIDTH / display->m->tile_size, x);
    // t = Lerp(0,display->raycast->text->west_img->width,t);
    // d_color = get_color(x, (int)t, display->raycast->text->west_img);
    y = star;
    while ( y < end)
    {
        if (flags == 1)
            mlx_put_pixel(img, x, y, color);
        else{
        //    printf("x = %d\n", x);
            mlx_put_pixel(img, x, y, get_color(x, (int)t, display->raycast->text->west_img));
 
        }
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
            ray->side_dist.x += ray->delta_dist.x * V_MAGIE;
            ray->map.x += ray->step.x* V_MAGIE;
            ray->side = 0;
        }
        else
        {
            ray->side_dist.y += ray->delta_dist.y* V_MAGIE;
            ray->map.y += ray->step.y * V_MAGIE;
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
    t_camera *camera;
    t_ray tab[WIDTH];

    x = 0;
    camera = display->raycast->camera;
    clear_image(display->raycast->ray->img, 0x000000);
    clear_image(display->img, 0x000000);
    ray->angle = camera->angle_min;

    draw_bg(display, display->img);

    int i = 0;
    while (i < WIDTH)
    {
        tab[i] = *ray;
        if(x % 2 == 0)
            tab[i].angle += angle_rad(FOV) / (WIDTH / 2);
        // tab[i].angle = ray->angle;
        tab[i].n_ray = i;
        i++;
        x++;
    }

    // i = 0;
    x = 0;
    while (x < WIDTH)
    {
        update_cam(display, &tab[x], player, x);
        init_dda(&tab[x], player);
        calculate_dda(display, &tab[x]);
        calculate_height_line(&tab[x], player);
        // draw_ray(display, &tab[x], player);
        draw_wall_orientation(display, &tab[x], x);
        if (x % 2 == 0)
            tab[x].angle += angle_rad(FOV) / (WIDTH / 2);
        x++;
    }
    i = 0;
    while (i < WIDTH)
    {
        draw_ray(display, &tab[i], player);
        i++;
    }
}






// void run_raycast(t_display *display, t_ray *ray, t_player *player)
// {
//     int x;
//     t_camera *camera;
    
//     x = 0;
//     camera = display->raycast->camera;
//     clear_image(display->raycast->ray->img, 0x000000);
//     clear_image(display->img, 0x000000);
//     ray->angle = camera->angle_min;

//     draw_bg(display, display->img);
//     while (x < WIDTH)
//     {
//         update_cam(display, ray, player, x);
//         init_dda(ray, player);
//         calculate_dda(display, ray);
//         calculate_height_line(ray, player);
//         draw_ray(display, ray, player);
//         draw_wall_orientation(display, ray, x);
//         if (x % 2 == 0)
//             ray->angle += angle_rad(FOV) / (WIDTH / 2);
//         x++;
//     }
// }

void draw_ray(t_display *display, t_ray *ray, t_player *player)
{
    t_vec_d end_pos;
    int max_ray_lenght;
    
    printf("ray_n_ray = %d\n", ray->n_ray);
    max_ray_lenght = 3;
    end_pos = (t_vec_d){ray->map.x , ray->map.y};
    if (hypot(ray->map.x - player->pos.x, ray->map.y - player->pos.y) > max_ray_lenght)
    {
        end_pos.x = player->pos.x + max_ray_lenght * ray->dir.x;
        end_pos.y = player->pos.y + max_ray_lenght * ray->dir.y;
    }
    if (ray->angle >= player->angle)
    draw_line(display->raycast->ray->img, (t_vec_d){player->pos.x * display->m->tile_size, player->pos.y * display->m->tile_size},
                                        (t_vec_d){end_pos.x * display->m->tile_size, end_pos.y * display->m->tile_size}, MY_RED);
    else
    draw_line(display->raycast->ray->img, (t_vec_d){player->pos.x * display->m->tile_size, player->pos.y * display->m->tile_size},
                                        (t_vec_d){end_pos.x * display->m->tile_size, end_pos.y * display->m->tile_size}, 0x800080);


}
// void draw_ray(t_display *display, t_ray *ray, t_player *player)// original function
// {
//     t_vec_d end_pos;
//     int max_ray_lenght;
    
//     max_ray_lenght = 3;
//     end_pos = (t_vec_d){ray->map.x , ray->map.y};
//     if (hypot(ray->map.x - player->pos.x, ray->map.y - player->pos.y) > max_ray_lenght)
//     {
//         end_pos.x = player->pos.x + max_ray_lenght * ray->dir.x;
//         end_pos.y = player->pos.y + max_ray_lenght * ray->dir.y;
//     }
//     if (ray->angle >= player->angle)
//     draw_line(display->raycast->ray->img, (t_vec_d){player->pos.x * display->m->tile_size, player->pos.y * display->m->tile_size},
//                                         (t_vec_d){end_pos.x * display->m->tile_size, end_pos.y * display->m->tile_size}, MY_RED);
//     else
//     draw_line(display->raycast->ray->img, (t_vec_d){player->pos.x * display->m->tile_size, player->pos.y * display->m->tile_size},
//                                         (t_vec_d){end_pos.x * display->m->tile_size, end_pos.y * display->m->tile_size}, 0x800080);


// }
