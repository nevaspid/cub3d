/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:06:55 by gloms             #+#    #+#             */
/*   Updated: 2024/07/12 01:41:32 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "raycast.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
}						t_mem_alloc;

typedef struct s_paths
{
	char	*no;
	char	*so;
	char	*se;
	char	*ea;
	char	*f;
	char	*c;
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
}						t_minimap;

typedef struct s_display
{
	mlx_t				*mlx;
	int32_t				width;
	int32_t				height;
	double				p_x;
	double				p_y;
	double				p_angle;
	t_minimap			*m;
	t_raycast			*raycast;
	mlx_image_t			*img;
	mlx_image_t			*current_tex;
}						t_display;

/*------------raycasting-------------*/

void					move_player(mlx_key_data_t key, void *param);
void					player_angle(void *param);
void					move_forwards(t_display *d);
void					move_backwards(t_display *d);
void					move_left(t_display *d);
void					move_right(t_display *d);
void					run_camera(t_display *d, t_camera *camera,
							t_player *player);
void					init_struct_camera(t_camera *camera);
void					init_camera(t_display *d, t_camera *camera);

double					angle_rad(double angle);
double					istance(t_vec_d a, t_vec_d b);
void					rotate_player(t_player *player, double rotSpeed);
void					init_mlx(t_display *display);
void					init_player(t_display *display, t_player *player);
void					init_value_st(t_display *display);
void					draw_bg(mlx_image_t *img);
void					draw_wall_orientation(t_display *display, t_ray *ray,
							int x);
void					move_rotated(mlx_key_data_t key, void *param);
int						check_next_move(t_display *d, double x, double y,
							t_direction dir);
/*------------memory-alloc-------------*/

void					*mem_alloc(t_mem_alloc *lst, size_t size);
void					free_and_exit(t_mem_alloc *malloc, char *str);
void					init_malloc(t_mem_alloc *mem_alloc, t_display *display);
/*-------------pixelling-------------*/

void					draw_player(t_display *minimap, int tile_size);
void					wall(t_minimap *minimap, int x, int y, int tile_size);
void					floors(t_minimap *minimap, int x, int y, int tile_size);
void					print_player(t_display *mlx, t_minimap *m,
							int tile_size);

void					print_minimap(t_display *mlx, t_minimap *minimap,
							int tile_size, t_mem_alloc *mylloc);
void					print_value_player(t_player *player, char *where,
							char *who);

/*-------------parsing-------------*/

void					read_parse_store(char *file, t_mem_alloc *lst,
							t_display *d);
int						flood_fill(char **map, int x, int y);
char					*return_paths(char *to_search, char **file,
							t_mem_alloc *m);
char					*return_rgb(char *to_search, char **file,
							t_mem_alloc *m);
int						find_path_in_line(char *tab_line);
int						find_rgb_in_line(char *tab_line);
int						search_flag_in_tab(char *to_find, char **tab);
int						check_tab(t_display *d, t_mem_alloc *malloc);
void					store_paths(char **file, t_paths *p, t_mem_alloc *m);
void					store_minimap(char **file, t_minimap *m,
							t_mem_alloc *malloc);
int						check_map(char **map);

/*-------------utils-------------*/

char					*ft_strjoin(char *s1, char *s2, t_mem_alloc *lst);
char					**ft_split(char const *s, char c, t_mem_alloc *lst);
int						ft_strlen(char *str);
int						is_char(char c, t_display *d);
int						is_digit(char c);
int						longest_line(char **array);
int						count_lines(char **array);
int						check_filename(char *file);
int						ft_strcmp(char *a, char *to_cmp);
char					*ft_substr(char *s, unsigned int start, size_t len,
							t_mem_alloc *lst);
int						go_to_endof_file(char **file);
int						is_space(char c);
char					*ft_strdup(char *s1, t_mem_alloc *lst);
char					**copy_tab(char **src, t_mem_alloc *m);
int						is_valid_char(char c);

/*--------------TEMP--------------*/

// void					print_tab(char **tab);
// void					print_value_ray(t_ray *ray, t_player *player,
// 							char *where, char *who, int n);
// void					print_value_recast(t_player *player, t_ray *ray,
// 							char *where, char *who);
// void					print_value_camera(t_camera *camera, char *where,
// 							char *who);

/*--------------PRIMITIVE-------------*/

void					init_struct(t_display *display);
void					init_layers(t_display *data);
void					init_compass(t_compass *cmp);
void					draw_line(mlx_image_t *img, t_vec_d start, t_vec_d end,
							int color);
void					draw_fill_circle(mlx_image_t *img, t_vec *x, int y,
							int color); // x1, int x2, int y,  int color);
void					draw_circle(t_compass *compass, int radius, int color,
							int fill);
void					draw_compass(t_display *display, t_compass *compass,
							t_player *player);
int						ajuste(int d, int x, int *y);
/*-------------DDA_AND_OTHER-----------*/
void					run_raycast(t_display *display, t_ray *ray,
							t_player *player);
void					image_to_window(t_display *display);
void					clear_image(mlx_image_t *img, uint32_t a);
void					init_game(t_display *display, t_mem_alloc *mylloc);
void					update_game(t_display *display);
void					draw_game(t_display *display);
void					update_cam(t_display *display, t_ray *ray,
							t_player *player, int x);
void					draw_ray(t_display *display, t_ray *ray,
							t_player *player);
double					lerp(double min, double max, double t);
double					inverse_lerp(double min, double max, double value);
double					clamp01(double value);
void					load_asset(t_display *display, mlx_texture_t *text,
							mlx_image_t **asset, char *path);
void					init_text(t_display *display);
void					draw_ligne_height(t_display *display, int x, int star,
							int end);
u_int32_t				get_color(int x, int y, mlx_image_t *img);
void					get_text(t_display *s_display, t_ray *ray,
							t_texture *current);
void					init_tab_ray(t_display *display);

void					game_loop(t_display *display, t_mem_alloc *mylloc);
t_ray					*new_node(int nb);
void					init_tab_ray(t_display *display);
t_ray					*ft_lst_get_last(t_ray *ray);
mlx_image_t				*get_texture(t_display *s_display, t_ray *ray);
void					init_text_to_img(t_display *display);
void					print_texture(t_texture *text, char *where, char *who);
void					west(t_player *player);
void					norsh(t_player *player);

void					print_circle(t_compass *compass, int x, int y,
							int color);
void					fill_circle(t_compass *compass, int x, int y,
							int color);
void					define_tile_size(t_display *display);
#endif
