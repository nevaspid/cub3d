/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:56:32 by oliove            #+#    #+#             */
/*   Updated: 2024/06/29 03:46:22 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_bg(t_display *display, mlx_image_t *img)
{
    (void)display;
    int x;
    int y;

    y = 0;
    while (y <= HEIGHT)
    {
        x = 0;
        while (x <= WIDTH)
        {
            if (y < HEIGHT / 2)
                mlx_put_pixel(img, x, y, MY_BLACK);
            else
                mlx_put_pixel(img, x, y, MY_RED);
            x++;
        }
        y++;
    }
}

// void get_text(t_display *s_display, t_ray *ray)
// {
//     if (ray->side == 1)
//     {
//         if (ray->step.y > 0)
//             ray->text = s_display->raycast->text->north;
//         // else
//         //     ray->text = s_display->raycast->text->south;
//     }
//     // else
//     // {
//     //     if (ray->step.x > 0)
//     //         ray->text = s_display->raycast->text->west;
//     //     else
//     //         ray->text = s_display->raycast->text->east;
//     // }

// }



void draw_wall_orientation(t_display *display, t_ray *ray,int x)
{
    uint32_t d_color;
    int y;
    t_texture *tex = display->raycast->text;
    // tex->size = tex->west_img->width;
    // tex->x = (int)(ray->wall_x * tex->size);    
    // if ((ray->side == 0 && ray->dir.x < 0)
    // || (ray->side == 1 && ray->dir.y > 0))
    // tex->x = tex->size - tex->x - 1;
	// tex->step = 1.0 * tex->size / ray->line_height;
	// tex->pos = (ray->draw_start - HEIGHT / 2
	// 		+ ray->line_height / 2) * tex->step;
    // y = ray->draw_start;
	// while (y < ray->draw_end)
	// {
	// 	tex->y = (int)tex->pos & (tex->size - 1);
	// 	tex->pos += tex->step;
    //     d_color = get_color(x, tex->size * tex->y + tex->x, display->raycast->text->west_img);
    //     if(ray->side == 1){
    //         if (ray->step.y > 0) 
    //             draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, d_color);
    //     }
            
	// 	// color = data->textures[tex->index][tex->size * tex->y + tex->x];
	// 	// if (tex->index == NORTH || tex->index == EAST)
	// 	// 	color = (color >> 1) & 8355711;
	// 	// if (color > 0)
	// 	// 	data->texture_pixels[y][x] = color;
	// 	y++;
	// }

    
    double t = InverseLerp(0, WIDTH, x);
    Lerp(0,display->raycast->text->west_img->width,t );
    d_color = get_color(x, (int)t, display->raycast->text->west_img);
    // d_color = get_color(display, display->raycast->text->west_img, ray->draw_start, x);
    
    
    (void)y;
    (void)tex;
    if (ray->side == 1){
        if (ray->step.y > 0) 
                draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, d_color);
            // draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, MY_WHITE);
        else
            draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, MAGENTA);
    }
    else{
        if(ray->step.x > 0)
            draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, ORANGE);
        else 
            draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, BLUE);
    } 
}


// void	update_texture_pixels(t_data *data, t_texinfo *tex, t_ray *ray, int x)
// {
// 	int			y;
// 	int			color;

// 	get_texture_index(data, ray);
// 	tex->x = (int)(ray->wall_x * tex->size);
// 	if ((ray->side == 0 && ray->dir_x < 0)
// 		|| (ray->side == 1 && ray->dir_y > 0))
// 		tex->x = tex->size - tex->x - 1;
// 	tex->step = 1.0 * tex->size / ray->line_height;
// 	tex->pos = (ray->draw_start - data->win_height / 2
// 			+ ray->line_height / 2) * tex->step;
// 	y = ray->draw_start;
// 	while (y < ray->draw_end)
// 	{
// 		tex->y = (int)tex->pos & (tex->size - 1);
// 		tex->pos += tex->step;
// 		color = data->textures[tex->index][tex->size * tex->y + tex->x];
// 		if (tex->index == NORTH || tex->index == EAST)
// 			color = (color >> 1) & 8355711;
// 		if (color > 0)
// 			data->texture_pixels[y][x] = color;
// 		y++;
// 	}
// }