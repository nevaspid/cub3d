/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:22:10 by oliove            #+#    #+#             */
/*   Updated: 2024/06/30 22:31:41 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double angle_rad(double angle)
{
    return (angle * M_PI / 180);
}

double distance(t_vec_d a, t_vec_d b)
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

// t_direction getRay_direction(float x0, float y0, float x1, float y1) 
// {
//     float dx;
//     float dy;

   
//     dy = y1 - y0;
//     dx = x1 - x0;
//     if (fabs(dx) > fabs(dy)) {
//         if (dx > 0) {
//             return EAST;
//         } else {
//             return WEST;
//         }
//     }
//     else {
//         if (dy > 0) {
//             return SOUTH;
//         } else {
//             return NORTH;
//         }
//     }
// }


// void render_floor(t_display *d, t_ray *ray, t_player *player)
// {
//     int x;
//     int y;
//     int color;
//     (void)player;
//     (void)ray;

//     while (y < HEIGHT)
//     {
//         y = HEIGHT / 2;
        
//         while (x < WIDTH)
//         {
//             color = 0x000000;
//             mlx_pixel_put(d->mlx, x, y, color);
//             x++;
//         }
//         y++;
//     }
    
    

// }


    /**************************************************************************************************************************** */
    /**                                                 BUG DE MERGE                                                             */
    /************************************************************************************************************************** */

    
int	ft_atoi_mod(const char *str)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (ft_strlen((char *)str) > 3)
		return (-1);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	return (sign * nbr);
}


u_int32_t	create_rgbt(unsigned char r, unsigned char g, unsigned char b, unsigned char t)
{
	return (*(int *)(unsigned char [4]){t, b, g, r});
}

uint32_t	extract_color(char **color)
{
	return (create_rgbt(
			(unsigned char)ft_atoi_mod(color[0]),
			(unsigned char)ft_atoi_mod(color[1]),
			(unsigned char)ft_atoi_mod(color[2]),
			255));
}

void load_asset(t_display *display, t_texture *asset, char *path)
{
	
	asset->west = mlx_load_png(path);

	if(!asset->west)
	{
		printf("ERROR : Asset not found\n");
		exit(0);
	}
	asset->west_img = mlx_texture_to_image(display->mlx, asset->west);
	mlx_delete_texture(asset->west);
}


// u_int32_t	get_rgba_tex(u_int32_t color)
// {
// 	u_int8_t	r;
// 	u_int8_t	g;
// 	u_int8_t	b;
// 	u_int8_t	a;

// 	a = color >> 24;
// 	r = color >> 16;
// 	g = color >> 8;
// 	b = color;
// 	return (r << 8 | g << 16 | b << 24 | a << 0);
// }

// u_int32_t	get_color(t_display *display, mlx_image_t *img, int x, int y)
// {
// 	uint32_t	*pixel;
// 	u_int32_t	color;


// 	// printf("%d\n", *img->pixels);
// 	pixel = NULL;
// 	pixel = (uint32_t *)(img->pixels + (x + y * display->m->tile_size) * sizeof(uint32_t));
// 	color = *pixel;
// 	return (get_rgba_tex(color));
// 	// return (0);
// }

// uint8_t* get_image_color_pixel(mlx_texture_t* texture)
// uint32_t get_image_color_pixel(mlx_texture_t* texture, t_display *mlx)
// {
// 	mlx_image_t* image;
// 	mlx_texture_t* text;
// 	// mlx_image_t* image = mlx_new_image(mlx->mlx, texture->width, texture->height);
// 	// mlx->raycast->asset->ceiling = mlx_new_image(mlx->mlx, texture->width, texture->height);
// 	// image = mlx->raycast->asset->ceiling;
// 	text = mlx_load_png("srcs/assets/burger_shop.png");
// 	if (image == NULL)
// 		return NULL;
// 	image = mlx_texture_to_image(mlx->mlx, texture);
// 	mlx_delete_texture(text);
// 	// uint8_t* pixelx;
// 	// uint8_t* pixeli;
// 	return (image);
// }

u_int32_t	get_rgba_tex(u_int32_t color)
{
	u_int8_t	r;
	u_int8_t	g;
	u_int8_t	b;
	u_int8_t	a;

	a = color >> 24;
	r = color >> 16;
	g = color >> 8;
	b = color;
	// printf("r [%d] g [%d] b [%d] a [%d]\n", r, g, b, a);
	return (r << 8 | g << 16 | b << 24 | a << 0);
	
}

/*

******
******
******

****** ****** ******
*/

u_int32_t	get_color(int x, int y, mlx_image_t *img)
{
	(void)x;
	uint32_t	*pixel;
	u_int32_t	color;
	// int pixelPos = y * img->height + x;
	color = 0;
	pixel = NULL;
	// printf("bit_per_pixel [%d]\n", img->pixels);
	// printf("x [%d] y [%d]\n", x, y);
	pixel = (uint32_t *)(img->pixels + (x + y * (img->width)) * sizeof(uint32_t));
	// uint32_t c = 0;
	// c += img->pixels[(x+ y * img->height) * 4];
	// // printf("x [%d] y [%d]\n", x, y);
	// c += img->pixels[(x+y * img->height) * 4 + 1];
	// c += img->pixels[(x+y * img->height) * 4 + 2];
	// c += img->pixels[(x+y * img->height) * 4 + 3];
	// return (c);
	// printf("pixel == [%d]\n", *pixel);
	
	color = *pixel;
	return (get_rgba_tex(color));
	// return (0);
}


uint8_t get_pixel(t_display *display, mlx_texture_t *texture,int x, int y)
{
    (void)display;
    uint8_t *color;
    int i;
    int pixelPos = y * texture->height + x;
	printf("texture->pixels == [%d]\n", texture->bytes_per_pixel);
    color = 0;
    color = color + pixelPos* (texture->bytes_per_pixel / 8);


    // color = texture->addr + (y * texture->height + x * (texture->bytes_per_pixel / 8));
    i = *(unsigned int *)color;
    return (i);

}
double InverseLerp(double min, double max, double value)
{
	if (min != max)
		return Clamp01((value - min) / (max - min));
	else
		return 0.0;
}

double Lerp(double min, double max, double t)
{
	return min + (max - min) * Clamp01(t);
}

double Clamp01(double value)
{
	if (value < 0)
		return 0;
	else if (value > 1)
		return 1;
	else
		return value;
}

// void get_pixel_pos(t_display *display,mlx_image_t *image, t_ray *ray, int x)
// {
	
// 	// Hauteur du mur en pixels à l'écran
// 	double wallHeight = ray->line_height; // à déterminer

// 	// Hauteur de la texture
// 	double textureHeight = image->height; // à déterminer

// 	// Pour chaque pixel du mur à l'écran
// 	for (double y = 0; y < wallHeight; y++)
// 	{
// 		// Calculez la position relative sur le mur
// 		double relativePosition = InverseLerp(0, wallHeight, y);

// 		// Convertissez cette position en une position dans la texture
// 		double texturePosition = Lerp(0, textureHeight, relativePosition);

// 	 // Utilisez cette position pour obtenir la couleur du pixel dans la texture
//         int pixelIndex = (int)texturePosition * image->width;
//         int color = image->data[pixelIndex];

// 	}
// }

// size texture x, y
// size wall x, y
// x, y

// u_int8_t get_tex_scale(t_display *display, mlx_image_t *texture, int x, int y)
// {
// 	(void)display;
	
// 	u_int8_t scale_x;
// 	u_int8_t scale_y;
	

	
// 	// printf("scale_x [%d] scale_y [%d]\n", (x * texture->width) / display->m->tile_size,(y * texture->height) / display->m->tile_size);
// 	scale_x = (x * texture->width) / display->m->tile_size;
// 	scale_y = (y * texture->height) / display->m->tile_size;
	
	
// 	if(scale_x > 0 && scale_x < texture->width && scale_y > 0  && scale_y < texture->height)
// 		return (get_pixel(display, texture, scale_x, scale_y));
// 	return (0);
// }
// u_int8_t get_tex_scale(t_display *display, mlx_texture_t *texture, int x, int y)
// {
// 	(void)display;
	
// 	u_int8_t scale_x;
// 	u_int8_t scale_y;
	

	
// 	printf("scale_x [%d] scale_y [%d]\n", (x * texture->width) / display->m->tile_size,(y * texture->height) / display->m->tile_size);
// 	scale_x = (x * texture->width) / display->m->tile_size;
// 	scale_y = (y * texture->height) / display->m->tile_size;
	
	
// 	if(scale_x > 0 && scale_x < texture->width && scale_y > 0  && scale_y < texture->height)
// 		return (get_pixel(display, texture, scale_x, scale_y));
// 	return (0);
// }


// u_int32_t	get_rgba_tex(u_int32_t color)
// {
// 	u_int8_t	r;
// 	u_int8_t	g;
// 	u_int8_t	b;
// 	u_int8_t	a;

// 	a = color >> 24;
// 	r = color >> 16;
// 	g = color >> 8;
// 	b = color;
// 	return (r << 8 | g << 16 | b << 24 | a << 0);
// }


// u_int32_t	get_color(int x, int y, mlx_texture_t *img)
// u_int32_t	get_color(int x, int y, mlx_image_t *img)
// {
// 	uint32_t	*pixel;
// 	u_int32_t	color;

// 	pixel = NULL;
// 	pixel = (uint32_t *)(img->pixels + (x + y * (img->height * img->width) * sizeof(uint32_t)));
// 	color = *pixel;
// 	return (get_rgba_tex(color));
// 	return (0);
// }

// void render_floor(t_display *d, t_ray *ray, t_player *player)
// {
//     int x;
//     int y;
//     int color;
//     (void)player;
//     (void)ray;

//     while (y < HEIGHT)
//     {
//         y = HEIGHT / 2;
        
//         while (x < WIDTH)
//         {
//             color = 0x000000;
//             mlx_pixel_put(d->mlx, x, y, color);
//             x++;
//         }
//         y++;
//     }
    
    
// }
