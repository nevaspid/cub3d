/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:06:55 by gloms             #+#    #+#             */
/*   Updated: 2024/05/03 16:49:27 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "MLX42/include/MLX42/MLX42.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

/*-------------DEFINES-------------*/

# define PI 3.14159265358979323846
# define HEIGHT 1095
# define WIDTH 1800
# define SPEED 1
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
	t_paths				*paths;
	int					p_x;
	int					p_y;
	double				p_angle;
	int					tile_size;
}	t_minimap;

typedef struct s_display
{
	mlx_t			*mlx;
	int32_t			width;
	int32_t			height;
	t_minimap		*m;
}	t_display;

/*------------raycasting-------------*/

void	move_player(void *param);
void	player_angle(void *param);

/*------------memory-alloc-------------*/

void	*mem_alloc(t_mem_alloc *lst, size_t size);

/*-------------pixelling-------------*/

void	draw_player(t_minimap *minimap, int tile_width, int tile_height);
void	wall(t_minimap *minimap, int x, int y, int tile_width, int tile_height);
void	floors(t_minimap *minimap, int x, int y, int tile_width, int tile_height);
void	print_player(t_display *mlx, t_minimap *m, int tile_width, int tile_height);
void	print_minimap(t_display *mlx, t_minimap *minimap, int tile_width, int tile_height);

/*-------------parsing-------------*/

void	read_parse_store(char *file, t_mem_alloc *lst, t_display *d);
char	*return_paths(char *to_search, char **file, t_mem_alloc *m);
char	*return_rgb(char *to_search, char **file, t_mem_alloc *m);
int		find_path_in_line(char *tab_line);
int		find_rgb_in_line(char *tab_line);
int		search_flag_in_tab(char *to_find, char **tab);
int		check_tab(t_display *d, t_mem_alloc *malloc);
void	store_paths(char **file, t_paths *p, t_mem_alloc *m);
void	store_minimap(char **file, t_minimap *m, t_mem_alloc *malloc);

/*-------------utils-------------*/

char		*ft_strjoin(char *s1, char *s2, t_mem_alloc *lst);
char		**ft_split(char const *s, char c, t_mem_alloc *lst);
int			ft_strlen(char *str);
int			is_char(char c, t_minimap *minimap);
int			is_digit(char c);
int			longest_line(char **array);
int 		count_lines(char **array);
int			check_filename(char *file);
int			ft_strcmp(char *a, char *to_cmp);
char		*ft_substr(char *s, unsigned int start, size_t len, t_mem_alloc *lst); //! a verifier
int			go_to_endof_file(char **file);
int			is_space(char c);
int			is_empty_line(char *line);

/*--------------TEMP--------------*/

void	print_tab(char **tab);

#endif
