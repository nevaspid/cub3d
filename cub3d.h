/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:06:55 by gloms             #+#    #+#             */
/*   Updated: 2024/06/13 04:01:30 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "raycast.h"
#include "MLX42/include/MLX42/MLX42.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <stdint.h>
#include <stddef.h>
#include <stdint.h>




/*-------------DEFINES-------------*/

// # define PI 3.14159265358979323846
# define HEIGHT 1095
# define WIDTH 1800
# define SPEED 0.2f
# define ROTATE 0.04f
# define NB_RAYS 50

/*-------------STRUCTS-------------*/

typedef struct s_mem_alloc
{
	void				*content;
	struct s_mem_alloc	*next;
}	t_mem_alloc;

typedef	struct s_paths
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
}	t_paths;

typedef struct s_minimap
{
	mlx_image_t			*minimap;
	mlx_image_t			*player;
	char				**file;
	char				**minimap_array;
	char				**copy;
	t_paths				*paths;
	int					p_x;
	int					p_y;
	int					tile_size;
}	t_minimap;

typedef struct s_display
{
	mlx_t			*mlx;
	int32_t			width;
	int32_t			height;
	double			p_x;
	double			p_y;
	double			p_angle;
	t_minimap		*m;
	t_raycast		*raycast;
	mlx_image_t		*img;
}	t_display;

/*------------raycasting-------------*/
void	move_player(mlx_key_data_t key, void *param);
void	player_angle(void *param);
void	move_forwards(t_display *d);
void	move_backwards(t_display *d);
void	move_left(t_display *d);
void	move_right(t_display *d);
void 	run_camera(t_display *d, t_camera *camera, t_player *player);
void 	init_struct_camera(t_camera *camera);
void 	init_camera(t_display *d, t_camera *camera);

double 	angle_rad(double angle);
double 	istance(t_vec_d a, t_vec_d b);
double 	re_distance(double ax, double ay, double bx, double by);
void 	rotate_player(t_player *player, double rotSpeed);
void 	init_mlx(t_display *display);
void 	init_player(t_display *display, t_player *player);
void 	init_value_st(t_display *display);
void 	draw_bg(t_display *display, mlx_image_t *img);
void 	draw_wall_orientation(t_display *display, t_ray *ray, int x);
void 	draw_ligne_height(mlx_image_t *img, int x, int star, int end, int color);
void 	move_rotated(mlx_key_data_t key, void *param);
int 	check_next_move(t_display *d,double x, double y, t_direction dir);
void 	init_asset(t_display *display, t_assets *asset);





/*
 ________                     __      __                     
/        |                   /  |    /  |                    
$$$$$$$$/______    _______  _$$ |_   $$/  _______    ______  
   $$ | /      \  /       |/ $$   |  /  |/       \  /      \ 
   $$ |/$$$$$$  |/$$$$$$$/ $$$$$$/   $$ |$$$$$$$  |/$$$$$$  |
   $$ |$$    $$ |$$      \   $$ | __ $$ |$$ |  $$ |$$ |  $$ |
   $$ |$$$$$$$$/  $$$$$$  |  $$ |/  |$$ |$$ |  $$ |$$ \__$$ |
   $$ |$$       |/     $$/   $$  $$/ $$ |$$ |  $$ |$$    $$ |
   $$/  $$$$$$$/ $$$$$$$/     $$$$/  $$/ $$/   $$/  $$$$$$$ |
                                                   /  \__$$ |
                                                   $$    $$/ 
                                                    $$$$$$/  
*/

uint8_t get_pixel(t_display *display, mlx_texture_t *texture,int x, int y);
void mouse_hook(void *param);
void init_mouse(t_display *display,t_mouse *mouse);

u_int32_t	get_color(int x, int y, mlx_image_t *img);
// u_int32_t	get_color(int x, int y, mlx_texture_t *img);















void init_asset(t_assets *asset);
void  load_asset(t_display *display,t_assets *asset, char *path);
u_int32_t	get_rgba_tex(u_int32_t color);
u_int32_t	get_color(t_display *display,mlx_image_t *img , int x, int y);

/*------------memory-alloc-------------*/

void	*mem_alloc(t_mem_alloc *lst, size_t size);
void	free_and_exit(t_mem_alloc *malloc);
void 	init_malloc(t_mem_alloc *mem_alloc, t_display *display);
/*-------------pixelling-------------*/

void	draw_player(t_display *minimap, int tile_size);
void	wall(t_minimap *minimap, int x, int y, int tile_size);
void	floors(t_minimap *minimap, int x, int y, int tile_size);
void	print_player(t_display *mlx, t_minimap *m, int tile_size);

void	print_minimap(t_display *mlx, t_minimap *minimap, int tile_size, t_mem_alloc *mylloc);
// void	print_minimap(t_display *mlx, t_minimap *minimap, int tile_size);
void print_value_player(t_player *player, char *where, char *who);

/*-------------parsing-------------*/

void	read_parse_store(char *file, t_mem_alloc *lst, t_display *d);
int		flood_fill(char **map, int x, int y);
char	*return_paths(char *to_search, char **file, t_mem_alloc *m);
char	*return_rgb(char *to_search, char **file, t_mem_alloc *m);
int		find_path_in_line(char *tab_line);
int		find_rgb_in_line(char *tab_line);
int		search_flag_in_tab(char *to_find, char **tab);
int		check_tab(t_display *d, t_mem_alloc *malloc);
void	store_paths(char **file, t_paths *p, t_mem_alloc *m);
void	store_minimap(char **file, t_minimap *m, t_mem_alloc *malloc);
int		check_map(char **map);

/*-------------utils-------------*/

char		*ft_strjoin(char *s1, char *s2, t_mem_alloc *lst);
char		**ft_split(char const *s, char c, t_mem_alloc *lst);
int			ft_strlen(char *str);
int			is_char(char c, t_display *d);
int			is_digit(char c);
int			longest_line(char **array);
int 		count_lines(char **array);
int			check_filename(char *file);
int			ft_strcmp(char *a, char *to_cmp);
char		*ft_substr(char *s, unsigned int start, size_t len, t_mem_alloc *lst);
int			go_to_endof_file(char **file);
int			is_space(char c);
char		*ft_strdup(char *s1, t_mem_alloc *lst);
char		**copy_tab(char **src, t_mem_alloc *m);
int			is_valid_char(char c);

/*--------------TEMP--------------*/

void	print_tab(char **tab);
void 	print_value_ray(t_ray *ray, t_player *player, char *where, char *who, int n);
void 	print_value_recast(t_player *player, t_ray *ray, char *where, char *who);
void 	print_value_camera(t_camera *camera, char *where, char *who);
// void 	print_direction(t_direction dir, int x);
// t_direction getRay_direction(float x0, float y0, float x1, float y1);
/*--------------PRIMITIVE-------------*/

void init_struct(t_display *display);
void init_layers(t_display *data);
void init_compass(t_compass *cmp);
void draw_line(mlx_image_t *img, t_vec_d start, t_vec_d end, int color);
void draw_fill_circle(mlx_image_t *img, int x1, int x2, int y,  int color);
void draw_circle(mlx_image_t *img, int center_x, int center_y, int radius, int color, int fill);
void draw_compass(t_display *display, t_compass *compass , t_player *player);

/*-------------DDA_AND_OTHER-----------*/
void run_raycast(t_display *display, t_ray *ray, t_player *player);

// int check_next_move(t_display *d, double x, double y);

#endif
