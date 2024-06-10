/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 01:21:22 by oliove            #+#    #+#             */
/*   Updated: 2024/06/10 21:09:24 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

////// refactory !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1111

void init_malloc(t_mem_alloc *mylloc, t_display *display)
{
    display->m = mem_alloc(mylloc, sizeof(t_minimap));
	display->m->paths = mem_alloc(mylloc, sizeof(t_paths));
	display->raycast = mem_alloc(mylloc, sizeof(t_raycast));
	display->raycast->compass = mem_alloc(mylloc, sizeof(t_compass));
	display->raycast->player = mem_alloc(mylloc,sizeof(t_player));
	display->raycast->ray = mem_alloc(mylloc,sizeof(t_ray));
	display->raycast->camera = mem_alloc(mylloc,sizeof(t_camera));
    display->raycast->assets = mem_alloc(mylloc,sizeof(t_assets));
    display->raycast->assets->portal = mem_alloc(mylloc,sizeof(t_img_portal));
    
}

void init_mlx(t_display *display)
{
    display->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
    display->m->minimap = mlx_new_image(display->mlx, WIDTH * SCALE, HEIGHT * SCALE);
    display->raycast->compass->img = mlx_new_image(display->mlx, WIDTH * SCALE, HEIGHT * SCALE);
    display->raycast->ray->img = mlx_new_image(display->mlx, WIDTH * SCALE, HEIGHT * SCALE);
    display->img = mlx_new_image(display->mlx, WIDTH , HEIGHT );
}



/*
 __            __    __                      __                                         
/  |          /  |  /  |                    /  |                                        
$$/  _______  $$/  _$$ |_           ______  $$ |  ______   __    __   ______    ______  
/  |/       \ /  |/ $$   |         /      \ $$ | /      \ /  |  /  | /      \  /      \ 
$$ |$$$$$$$  |$$ |$$$$$$/         /$$$$$$  |$$ | $$$$$$  |$$ |  $$ |/$$$$$$  |/$$$$$$  |
$$ |$$ |  $$ |$$ |  $$ | __       $$ |  $$ |$$ | /    $$ |$$ |  $$ |$$    $$ |$$ |  $$/ 
$$ |$$ |  $$ |$$ |  $$ |/  |      $$ |__$$ |$$ |/$$$$$$$ |$$ \__$$ |$$$$$$$$/ $$ |      
$$ |$$ |  $$ |$$ |  $$  $$/______ $$    $$/ $$ |$$    $$ |$$    $$ |$$       |$$ |      
$$/ $$/   $$/ $$/    $$$$//      |$$$$$$$/  $$/  $$$$$$$/  $$$$$$$ | $$$$$$$/ $$/       
                          $$$$$$/ $$ |                    /  \__$$ |                    
                                  $$ |                    $$    $$/                     
                                  $$/                      $$$$$$/                      
*/

void init_player(t_display *display, t_player *player)
{
    player->pos.x = display->p_x; //* display->m->tile_size * display->m->tile_size / 2; // display->raycast->ray->img->instances[0].x;
    player->pos.y = display->p_y; //* display->m->tile_size * display->m->tile_size / 2; // display->raycast->ray->img->instances[0].y;
    player->angle = display->p_angle;
    player->dir.x = 0;
    player->dir.y = 0;
    player->plane.x = 0;
    player->plane.y = 0;

}

/*
 __            __    __                                        
/  |          /  |  /  |                                       
$$/  _______  $$/  _$$ |_           ______   ______   __    __ 
/  |/       \ /  |/ $$   |         /      \ /      \ /  |  /  |
$$ |$$$$$$$  |$$ |$$$$$$/         /$$$$$$  |$$$$$$  |$$ |  $$ |
$$ |$$ |  $$ |$$ |  $$ | __       $$ |  $$/ /    $$ |$$ |  $$ |
$$ |$$ |  $$ |$$ |  $$ |/  |      $$ |     /$$$$$$$ |$$ \__$$ |
$$ |$$ |  $$ |$$ |  $$  $$/______ $$ |     $$    $$ |$$    $$ |
$$/ $$/   $$/ $$/    $$$$//      |$$/       $$$$$$$/  $$$$$$$ |
                          $$$$$$/                    /  \__$$ |
                                                     $$    $$/ 
                                                      $$$$$$/  
*/

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
    ray->nb_ray = 0;
    ray->angle_ray = 0;
}
 /*
 __            __    __                        __                                      __                                                                         
/  |          /  |  /  |                      /  |                                    /  |                                                                        
$$/  _______  $$/  _$$ |_           _______  _$$ |_     ______   __    __   _______  _$$ |_          _______   ______   _____  ____    ______    ______   ______  
/  |/       \ /  |/ $$   |         /       |/ $$   |   /      \ /  |  /  | /       |/ $$   |        /       | /      \ /     \/    \  /      \  /      \ /      \ 
$$ |$$$$$$$  |$$ |$$$$$$/         /$$$$$$$/ $$$$$$/   /$$$$$$  |$$ |  $$ |/$$$$$$$/ $$$$$$/        /$$$$$$$/  $$$$$$  |$$$$$$ $$$$  |/$$$$$$  |/$$$$$$  |$$$$$$  |
$$ |$$ |  $$ |$$ |  $$ | __       $$      \   $$ | __ $$ |  $$/ $$ |  $$ |$$ |        $$ | __      $$ |       /    $$ |$$ | $$ | $$ |$$    $$ |$$ |  $$/ /    $$ |
$$ |$$ |  $$ |$$ |  $$ |/  |       $$$$$$  |  $$ |/  |$$ |      $$ \__$$ |$$ \_____   $$ |/  |     $$ \_____ /$$$$$$$ |$$ | $$ | $$ |$$$$$$$$/ $$ |     /$$$$$$$ |
$$ |$$ |  $$ |$$ |  $$  $$/______ /     $$/   $$  $$/ $$ |      $$    $$/ $$       |  $$  $$/______$$       |$$    $$ |$$ | $$ | $$ |$$       |$$ |     $$    $$ |
$$/ $$/   $$/ $$/    $$$$//      |$$$$$$$/     $$$$/  $$/        $$$$$$/   $$$$$$$/    $$$$//      |$$$$$$$/  $$$$$$$/ $$/  $$/  $$/  $$$$$$$/ $$/       $$$$$$$/ 
                          $$$$$$/                                                           $$$$$$/                                                               
*/


void init_struct_camera(t_camera *camera)
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



/*
  _______   ______   _____  ____   _____  ____    ______    ______   ______  
 /       | /      \ /     \/    \ /     \/    \  /      \  /      \ /      \ 
/$$$$$$$/  $$$$$$  |$$$$$$ $$$$  |$$$$$$ $$$$  |/$$$$$$  |/$$$$$$  |$$$$$$  |
$$ |       /    $$ |$$ | $$ | $$ |$$ | $$ | $$ |$$    $$ |$$ |  $$/ /    $$ |
$$ \_____ /$$$$$$$ |$$ | $$ | $$ |$$ | $$ | $$ |$$$$$$$$/ $$ |     /$$$$$$$ |
$$       |$$    $$ |$$ | $$ | $$ |$$ | $$ | $$ |$$       |$$ |     $$    $$ |
 $$$$$$$/  $$$$$$$/ $$/  $$/  $$/ $$/  $$/  $$/  $$$$$$$/ $$/       $$$$$$$/ 
*/


void init_camera(t_display *display, t_camera *camera)
{
    t_player *player;
    
    player = display->raycast->player;
    camera->fov = FOV;
    camera->camera_x = 0;
    camera->angle_cam = display->p_angle;
    camera->angle_min = display->p_angle - angle_rad(FOV) /2;
    camera->angle_max = display->p_angle + angle_rad(FOV) / 2;
    camera->nb_ray = NB_RAYS;
    camera->angle_ray = FOV / NB_RAYS;
    camera->dir.x = cos(display->raycast->player->angle);
    camera->dir.y = sin(display->raycast->player->angle);
    camera->plane.x = player->dir.x * tan(angle_rad(camera->angle_cam));
    camera->plane.y = player->dir.y * tan(angle_rad(camera->angle_cam));
}

/*
 __                            __        __                            __                                   
/  |                          /  |      /  |                          /  |                                  
$$ |  ______    ______    ____$$ |     _$$ |_     ______   __    __  _$$ |_    __    __   ______    ______  
$$ | /      \  /      \  /    $$ |    / $$   |   /      \ /  \  /  |/ $$   |  /  |  /  | /      \  /      \ 
$$ |/$$$$$$  | $$$$$$  |/$$$$$$$ |    $$$$$$/   /$$$$$$  |$$  \/$$/ $$$$$$/   $$ |  $$ |/$$$$$$  |/$$$$$$  |
$$ |$$ |  $$ | /    $$ |$$ |  $$ |      $$ | __ $$    $$ | $$  $$<    $$ | __ $$ |  $$ |$$ |  $$/ $$    $$ |
$$ |$$ \__$$ |/$$$$$$$ |$$ \__$$ |      $$ |/  |$$$$$$$$/  /$$$$  \   $$ |/  |$$ \__$$ |$$ |      $$$$$$$$/ 
$$ |$$    $$/ $$    $$ |$$    $$ |______$$  $$/ $$       |/$$/ $$  |  $$  $$/ $$    $$/ $$ |      $$       |
$$/  $$$$$$/   $$$$$$$/  $$$$$$$//      |$$$$/   $$$$$$$/ $$/   $$/    $$$$/   $$$$$$/  $$/        $$$$$$$/ 
                                 $$$$$$/                                                                    
*/

void load_texture(t_display *display, t_img_portal *portal)
{
    (void)display;
    portal->tile_case_x = 32;
    portal->tile_case_y = 32;
    portal->img_portal_1 = mlx_load_png("srcs/assets/portal/portal_1.png");
    portal->img_portal_2 = mlx_load_png("srcs/assets/portal/portal_2.png");
    portal->img_portal_3 = mlx_load_png("srcs/assets/portal/portal_3.png");
    portal->img_portal_4 = mlx_load_png("srcs/assets/portal/portal_4.png");
    portal->img_portal_5 = mlx_load_png("srcs/assets/portal/portal_5.png");
    portal->img_portal_6 = mlx_load_png("srcs/assets/portal/portal_6.png");
    
}

void init_value_st(t_display *display)
{
    // (void)display;

    init_player(display, display->raycast->player);
    init_camera(display, display->raycast->camera);
    init_compass(display->raycast->compass);
    // Pour plus tard, j'y metterai toute les alloc

}