/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:22:10 by oliove            #+#    #+#             */
/*   Updated: 2024/06/16 22:46:34 by oliove           ###   ########.fr       */
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

// void get_pixel_tex(t_display *display, t_assets *asset, t_ray *ray)
// {
//     int X;
//     int Y;
//     int color;

//     y = 0;
//     while (y <= asset->img->height)
//     {
//         x = 0;
//         while (x <= asset->img->width)
//         {
//             // if (x == asset->img->bytes_per_pixel && y == ray->tex_y){
//             //     asset->color = asset->img->bytes_per_pixel;
//                 // color = mlx_get_pixel(asset->img, x, y);
//                 // color = mlx_get_pixel(asset->img, x, y);
//                 // mlx_put_pixel(display->img, ray->x, ray->draw_start + y, color);
                
//             // }
//             x++;
//         }
//         y++;
//     }

// }


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

// void load_asset(t_display *display, t_assets *asset, char *path)
// {
	
// 	asset->texture = mlx_load_png(path);
// 	if(!asset->texture)
// 	{
// 		printf("ERROR : Asset not found\n");
// 		exit(0);
// 	}
// 	asset->ceiling = mlx_texture_to_image(display->mlx, asset->texture);
// 	mlx_delete_texture(asset->texture);
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
	return (r << 8 | g << 16 | b << 24 | a << 0);
}

u_int32_t	get_color(t_display *display, mlx_image_t *img, int x, int y)
{
	uint32_t	*pixel;
	u_int32_t	color;


	// printf("%d\n", *img->pixels);
	pixel = NULL;
	pixel = (uint32_t *)(img->pixels + (x + y * display->m->tile_size) * sizeof(uint32_t));
	color = *pixel;
	return (get_rgba_tex(color));
	// return (0);
}

// uint8_t* get_image_color_pixel(mlx_texture_t* texture)
void get_image_color_pixel(mlx_texture_t* texture, t_display *mlx)
{
	mlx_image_t* image;
	// mlx_image_t* image = mlx_new_image(mlx->mlx, texture->width, texture->height);
	mlx->raycast->asset->ceiling = mlx_new_image(mlx->mlx, texture->width, texture->height);
	image = mlx->raycast->asset->ceiling;
	if (image == NULL)
		return ;

	uint8_t* pixelx;
	uint8_t* pixeli;
	for (uint32_t i = 0; i < texture->height; i++)
	{
		pixelx = &texture->pixels[(i * texture->width) * texture->bytes_per_pixel];
		pixeli = &image->pixels[(i * image->width) * texture->bytes_per_pixel];
		// memmove(pixeli, pixelx, texture->width * texture->bytes_per_pixel);
		printf("pixeli [%d] pixelx [%d]\n", *pixeli, *pixelx);
	}
	// return (image);
}


// uint8_t get_pixel(t_display *display, mlx_image_t *texture, int x, int y)
// {
//     (void)display;
//     uint8_t *color;
//     int i;
    
// 	printf("%p\n", texture->pixels);
//     color = 0;
    
//     color = color + (y * texture->height + x * (*texture->pixels / 8));


//     // color = texture->addr + (y * texture->height + x * (texture->bytes_per_pixel / 8));
//     i = *(unsigned int *)color;
//     return (i);

// }
// }

uint8_t get_pixel(t_display *display, mlx_texture_t *texture,int x, int y)
{
    (void)display;
    uint8_t *color;
    int i;
    
	printf("texture->pixels == [%d]\n", texture->bytes_per_pixel);
    color = 0;
    color = color + (y * texture->height + x * (texture->bytes_per_pixel / 8));


    // color = texture->addr + (y * texture->height + x * (texture->bytes_per_pixel / 8));
    i = *(unsigned int *)color;
    return (i);

}
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
