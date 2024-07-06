/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 01:45:14 by oliove            #+#    #+#             */
/*   Updated: 2024/07/06 13:34:41 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
#define RAYCAST_H

#include "MLX42/include/MLX42/MLX42.h"


#define FOV 60
#define SCALE 0.5
#define V_MAGIE 0.02

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FFFF
# define YELLOW 0xFFFF00FF
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define ORANGE 0xFFA500FF
# define PURPLE 0x800080FF
# define PINK 0xFFC0CBFF
# define MY_WHITE 0xFEFEFAFF
# define MY_BLACK 0x54626FFF

# define MY_RED 0x8B0000FF


typedef enum e_direction
{
	UP,
	DOWN,
	RIGHT,
	LEFT
}   t_direction;


/*
                                 |  \
 __     __   ______    _______  _| $$_     ______    ______
|  \   /  \ /      \  /       \|   $$ \   /      \  /      \
 \$$\ /  $$|  $$$$$$\|  $$$$$$$ \$$$$$$  |  $$$$$$\|  $$$$$$\
  \$$\  $$ | $$    $$| $$        | $$ __ | $$  | $$| $$   \$$
   \$$ $$  | $$$$$$$$| $$_____   | $$|  \| $$__/ $$| $$
    \$$$    \$$     \ \$$     \   \$$  $$ \$$    $$| $$
     \$      \$$$$$$$  \$$$$$$$    \$$$$   \$$$$$$  \$$
*/

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_vec_d
{
	double	x;
	double	y;
}	t_vec_d;

/*
_______   ______   _____  ____    ______    ______    _______  _______
 /       | /      \ /     \/    \  /      \  /      \  /       |/       |
/$$$$$$$/ /$$$$$$  |$$$$$$ $$$$  |/$$$$$$  | $$$$$$  |/$$$$$$$//$$$$$$$/
$$ |      $$ |  $$ |$$ | $$ | $$ |$$ |  $$ | /    $$ |$$      \$$      \
$$ \_____ $$ \__$$ |$$ | $$ | $$ |$$ |__$$ |/$$$$$$$ | $$$$$$  |$$$$$$  |
$$       |$$    $$/ $$ | $$ | $$ |$$    $$/ $$    $$ |/     $$//     $$/
 $$$$$$$/  $$$$$$/  $$/  $$/  $$/ $$$$$$$/   $$$$$$$/ $$$$$$$/ $$$$$$$/
                                  $$ |
                                  $$ |
                                  $$/
*/

typedef struct s_compass
{
	mlx_image_t		*img;
	t_vec			*start;
	t_vec			*end;
	int 			radius;
	int 			center_x;
	int 			center_y;
	double			angle;
	double 			needle_length;
	double 			needle;
	double 			needle_angle;
	double 			needle_end_x;
	double 			needle_end_y;

}	t_compass;



/*

  _______  ______   ______ ____    ______    ______   ______
 /       \|      \ |      \    \  /      \  /      \ |      \
|  $$$$$$$ \$$$$$$\| $$$$$$\$$$$\|  $$$$$$\|  $$$$$$\ \$$$$$$\
| $$      /      $$| $$ | $$ | $$| $$    $$| $$   \$$/      $$
| $$_____|  $$$$$$$| $$ | $$ | $$| $$$$$$$$| $$     |  $$$$$$$
 \$$     \\$$    $$| $$ | $$ | $$ \$$     \| $$      \$$    $$
  \$$$$$$$ \$$$$$$$ \$$  \$$  \$$  \$$$$$$$ \$$       \$$$$$$$


*/


typedef struct s_camera
{
	double	fov; // filed of view
	double camera_x; // camera plane
	double angle_cam; // angle of view
	double angle_min; // fov / 2 side left
	double angle_max; // fov / 2 side right
	double angle_ray; // angle between each ray
	int 	nb_ray;// number of ray
	t_vec_d	plane;
	t_vec_d	dir;


}	t_camera;

/*
  ______   ______   __    __   ______   _______
 /      \ |      \ |  \  |  \ /      \ |       \
|  $$$$$$\ \$$$$$$\| $$  | $$|  $$$$$$\| $$$$$$$\
| $$   \$$/      $$| $$  | $$| $$  | $$| $$  | $$
| $$     |  $$$$$$$| $$__/ $$| $$__/ $$| $$  | $$
| $$      \$$    $$ \$$    $$ \$$    $$| $$  | $$
 \$$       \$$$$$$$ _\$$$$$$$  \$$$$$$  \$$   \$$
                   |  \__| $$
                    \$$    $$
                     \$$$$$$

*/

typedef struct s_ray
{
	mlx_image_t		*img;
	int 			id;
	
	t_vec_d			map;
	t_vec_d			dir;
	
	t_vec_d			prev_ray;
	
	t_vec_d			start;
	t_vec_d			end;
	
	t_vec_d			step;
	
	t_vec_d			side_dist;
	t_vec_d			delta_dist;
	
	int 			nb_ray;
	int				draw_start;
	int 			draw_end;


	double			angle_ray;
	
	double			wall_dist;
	double 			wall_x;
	// int 			wall_x;
	int 			hit;
	int				hit_side;
	
	int 			side;
	double			fov;
	double			angle;
	
	
	double 			line_height;
	
	struct s_ray			*next;

}	t_ray;

/*
           __
          |  \
  ______  | $$  ______   __    __   ______    ______
 /      \ | $$ |      \ |  \  |  \ /      \  /      \
|  $$$$$$\| $$  \$$$$$$\| $$  | $$|  $$$$$$\|  $$$$$$\
| $$  | $$| $$ /      $$| $$  | $$| $$    $$| $$   \$$
| $$__/ $$| $$|  $$$$$$$| $$__/ $$| $$$$$$$$| $$
| $$    $$| $$ \$$    $$ \$$    $$ \$$     \| $$
| $$$$$$$  \$$  \$$$$$$$ _\$$$$$$$  \$$$$$$$ \$$
| $$                    |  \__| $$
| $$                     \$$    $$
 \$$                      \$$$$$$

*/

typedef struct s_player
{
	mlx_image_t	*img;
	t_vec_d	pos;
	t_vec_d	dir;
	t_vec 	map;
	t_vec_d	plane;
	int		turn_direction;
	int		walk_direction;
	int		walk_speed;

	int		turn_speed;
	int		rotation_angle;
	int		move_step;
	int		rotation_step;
	int		fov;
	int 	px;
	int		py;
	char 	pos_start;

	int 			map_x;
	int 			map_y;
	double 			angle;
	int 			delta_x;
	int 			delta_y;
	double 			perp_wall_dist;
	t_vec_d			ray_len;
}	t_player;

/*
 __        __
/  |      /  |
$$ |      $$/  _______    ______
$$ |      /  |/       \  /      \
$$ |      $$ |$$$$$$$  |/$$$$$$  |
$$ |      $$ |$$ |  $$ |$$    $$ |
$$ |_____ $$ |$$ |  $$ |$$$$$$$$/
$$       |$$ |$$ |  $$ |$$       |
$$$$$$$$/ $$/ $$/   $$/  $$$$$$$/
*/
typedef struct s_line
{
	int x1;
	int y1;
	int x2;
	int y2;
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int err2;

}	t_line;

/*
______   _______   ______  _______   ________
 /      \ /       \ /      |/       \ /        |
/$$$$$$  |$$$$$$$  |$$$$$$/ $$$$$$$  |$$$$$$$$/
$$ | _$$/ $$ |__$$ |  $$ |  $$ |  $$ |$$ |__
$$ |/    |$$    $$<   $$ |  $$ |  $$ |$$    |
$$ |$$$$ |$$$$$$$  |  $$ |  $$ |  $$ |$$$$$/
$$ \__$$ |$$ |  $$ | _$$ |_ $$ |__$$ |$$ |_____
$$    $$/ $$ |  $$ |/ $$   |$$    $$/ $$       |
 $$$$$$/  $$/   $$/ $$$$$$/ $$$$$$$/  $$$$$$$$/
*/

typedef struct s_grille // rename en grid
{
	mlx_image_t		*img;
	t_vec			*start;
	t_vec			*end;
}	t_grille;


/*
   __                            __                                   
  /  |                          /  |                                  
 _$$ |_     ______   __    __  _$$ |_    __    __   ______    ______  
/ $$   |   /      \ /  \  /  |/ $$   |  /  |  /  | /      \  /      \ 
$$$$$$/   /$$$$$$  |$$  \/$$/ $$$$$$/   $$ |  $$ |/$$$$$$  |/$$$$$$  |
  $$ | __ $$    $$ | $$  $$<    $$ | __ $$ |  $$ |$$ |  $$/ $$    $$ |
  $$ |/  |$$$$$$$$/  /$$$$  \   $$ |/  |$$ \__$$ |$$ |      $$$$$$$$/ 
  $$  $$/ $$       |/$$/ $$  |  $$  $$/ $$    $$/ $$ |      $$       |
   $$$$/   $$$$$$$/ $$/   $$/    $$$$/   $$$$$$/  $$/        $$$$$$$/ 
*/


typedef struct s_texture
{
	mlx_texture_t	*west;
	mlx_texture_t	*east;
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	
	mlx_image_t		*north_img;
	mlx_image_t		*south_img;
	mlx_image_t		*east_img;
	mlx_image_t		*west_img;

	mlx_image_t		*img_portal;
	mlx_texture_t	*portal;
	
	mlx_image_t     *img;
	double			step;
	double			pos;
	int				x;
	int				y;
	int 			size;
	
}	t_texture;

/*
                                                              __
                                                             /  |
  ______   ______   __    __   _______   ______    _______  _$$ |_
 /      \ /      \ /  |  /  | /       | /      \  /       |/ $$   |
/$$$$$$  |$$$$$$  |$$ |  $$ |/$$$$$$$/  $$$$$$  |/$$$$$$$/ $$$$$$/
$$ |  $$/ /    $$ |$$ |  $$ |$$ |       /    $$ |$$      \   $$ | __
$$ |     /$$$$$$$ |$$ \__$$ |$$ \_____ /$$$$$$$ | $$$$$$  |  $$ |/  |
$$ |     $$    $$ |$$    $$ |$$       |$$    $$ |/     $$/   $$  $$/
$$/       $$$$$$$/  $$$$$$$ | $$$$$$$/  $$$$$$$/ $$$$$$$/     $$$$/
                   /  \__$$ |
                   $$    $$/
                    $$$$$$/
*/

typedef struct s_raycast
{
    t_player    *player;
    t_compass   *compass;
    t_ray       *ray;
	t_camera	*camera;
	t_texture	*text;
	int 		nb;
}               t_raycast;

/*commentaire pour comit un msg*/

#endif
