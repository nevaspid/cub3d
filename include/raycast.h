/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 01:45:14 by oliove            #+#    #+#             */
/*   Updated: 2024/07/12 21:13:16 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "../MLX42/include/MLX42/MLX42.h"

# define FOV 60
# define SCALE 0.5
# define V_MAGIE 0.02

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
}					t_direction;

typedef struct s_vec
{
	int				x;
	int				y;
}					t_vec;

typedef struct s_vec_d
{
	double			x;
	double			y;
}					t_vec_d;

typedef struct s_compass
{
	mlx_image_t		*img;
	t_vec			*start;
	t_vec			*end;
	int				radius;
	int				center_x;
	int				center_y;
	double			angle;
	double			needle_length;
	double			needle;
	double			needle_angle;
	double			needle_end_x;
	double			needle_end_y;

}					t_compass;

typedef struct s_camera
{
	double	fov;
	double	camera_x;
	double	angle_cam;
	double	angle_min;
	double	angle_max;
	t_vec_d	dir;
}	t_camera;

typedef struct s_ray
{
	mlx_image_t		*img;
	int				id;
	t_vec_d			map;
	t_vec_d			dir;
	t_vec_d			prev_ray;
	t_vec_d			start;
	t_vec_d			end;
	t_vec_d			step;
	t_vec_d			side_dist;
	t_vec_d			delta_dist;
	int				nb_ray;
	int				draw_start;
	int				draw_end;
	double			angle_ray;
	double			wall_dist;
	double			wall_x;
	int				hit;
	int				hit_side;
	int				side;
	double			fov;
	double			angle;
	double			line_height;
	double			line_size;
	struct s_ray	*next;

}					t_ray;

typedef struct s_player
{
	mlx_image_t		*img;
	t_vec_d			pos;
	t_vec_d			dir;
	t_vec			map;
	t_vec_d			plane;
	int				turn_direction;
	int				walk_direction;
	int				walk_speed;
	int				turn_speed;
	int				rotation_angle;
	int				move_step;
	int				rotation_step;
	int				fov;
	int				px;
	int				py;
	char			pos_start;
	int				map_x;
	int				map_y;
	double			angle;
	int				delta_x;
	int				delta_y;
	double			perp_wall_dist;
	t_vec_d			ray_len;
}					t_player;

typedef struct s_line
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				err2;

}					t_line;

typedef struct s_grille
{
	mlx_image_t	*img;
	t_vec		*start;
	t_vec		*end;
}					t_grille;

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
	mlx_image_t		*img;
	double			step;
	double			pos;
	int				x;
	int				y;
	int				size;

}					t_texture;

typedef struct s_gf
{
	t_ray		*r;
	t_ray		*l;
	t_ray		*f;
	t_ray		*b;
}				t_gf;

typedef struct s_raycast
{
	t_player		*player;
	t_compass		*compass;
	t_ray			*ray;
	t_camera		*camera;
	t_texture		*text;
	int				nb;
	t_gf			*gf;
}					t_raycast;

#endif
