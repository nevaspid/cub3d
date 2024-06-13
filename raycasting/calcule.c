/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:22:10 by oliove            #+#    #+#             */
/*   Updated: 2024/06/13 03:48:56 by oliove           ###   ########.fr       */
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

uint8_t get_pixel(t_display *display, mlx_texture_t *texture,int x, int y)
{
    (void)display;
    uint8_t *color;
    int i;
    
    color = 0;
    
    color = color + (y * texture->height + x * (texture->bytes_per_pixel / 8));


    // color = texture->addr + (y * texture->height + x * (texture->bytes_per_pixel / 8));
    i = *(unsigned int *)color;
    return (i);

}


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


// u_int32_t	get_color(int x, int y, mlx_texture_t *img)
u_int32_t	get_color(int x, int y, mlx_image_t *img)
{
	uint32_t	*pixel;
	u_int32_t	color;

	pixel = NULL;
	pixel = (uint32_t *)(img->pixels + (x + y * (img->height * img->width) * sizeof(uint32_t)));
	color = *pixel;
	return (get_rgba_tex(color));
	return (0);
}

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
