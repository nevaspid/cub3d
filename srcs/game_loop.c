/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:44:31 by oliove            #+#    #+#             */
/*   Updated: 2024/07/08 00:01:27 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*


  ______                                            __                                     
 /      \                                          /  |                                    
/$$$$$$  |  ______   _____  ____    ______         $$ |        ______    ______    ______  
$$ | _$$/  /      \ /     \/    \  /      \        $$ |       /      \  /      \  /      \ 
$$ |/    | $$$$$$  |$$$$$$ $$$$  |/$$$$$$  |       $$ |      /$$$$$$  |/$$$$$$  |/$$$$$$  |
$$ |$$$$ | /    $$ |$$ | $$ | $$ |$$    $$ |       $$ |      $$ |  $$ |$$ |  $$ |$$ |  $$ |
$$ \__$$ |/$$$$$$$ |$$ | $$ | $$ |$$$$$$$$/        $$ |_____ $$ \__$$ |$$ \__$$ |$$ |__$$ |
$$    $$/ $$    $$ |$$ | $$ | $$ |$$       |______ $$       |$$    $$/ $$    $$/ $$    $$/ 
 $$$$$$/   $$$$$$$/ $$/  $$/  $$/  $$$$$$$//      |$$$$$$$$/  $$$$$$/   $$$$$$/  $$$$$$$/  
                                           $$$$$$/                               $$ |      
                                                                                 $$ |      
                                                                                 $$/       
   
   Elle contient les fonctions qui permettent de lancer le jeu et de le mettre a jour
   et de l'afficher;
   
   je gere la logique du jeu dans update_game, donc si probleme de logique du jeu c'est ici
   que ca se passe
   
   je gere l'affichage dans draw_game, donc si probleme d'affichage c'est ici que ca se passe
   
   game_loop est la fonction qui lance le jeu et qui appelle les fonctions precedentes
   elle est appellee dans main.c                                                                                        
*/


void image_to_window(t_display *display)
{
	mlx_image_to_window(display->mlx, display->img, 0, 0);
	mlx_image_to_window(display->mlx, display->raycast->compass->img, WIDTH /2,0);
}

void init_game(t_display *display, t_mem_alloc *mylloc)
{
    init_malloc(mylloc, display);
    init_mlx(display);
}

void update_cam(t_display *display, t_ray *ray, t_player *player, int x)
{
    t_camera *camera;
    (void)x; 
    camera = display->raycast->camera;
    ray->dir.x = cos(ray->angle) + player->plane.x * camera->camera_x;
    ray->dir.y = sin(ray->angle) + player->plane.y * camera->camera_x;
    ray->map.x = player->pos.x;
    ray->map.y = player->pos.y;
    ray->delta_dist.x = fabs( 1 / ray->dir.x);
    ray->delta_dist.y = fabs(1 /  ray->dir.y);
}