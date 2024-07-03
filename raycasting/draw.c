/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:56:32 by oliove            #+#    #+#             */
/*   Updated: 2024/07/03 06:26:11 by oliove           ###   ########.fr       */
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

// void get_text(t_display *s_display, t_ray *ray, t_texture *current)
// {
//     if (ray->side == 1)
//     {
//         if (ray->step.y > 0)
//             current->img = s_display->raycast->text->west_img;
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

mlx_image_t *get_texture(t_display *s_display, t_ray *ray)
{
    mlx_image_t *img;

    // print_texture(s_display->raycast->text, "get_texture","start");
    if (ray->side == 1)
    {
        if (ray->step.y > 0)
            img = s_display->raycast->text->west_img;
        else
            img = s_display->raycast->text->south_img;
    }
    else
    {
        if (ray->step.x > 0)
            img = s_display->raycast->text->west_img;
        else
            img = s_display->raycast->text->east_img;
    }
    // printf("side = [%d] step = [%f,%f]\n", ray->side, ray->step.y, ray->step.x);
    // printf("get texture img = %p\n", img);
    return (img);
}


void draw_wall_orientation(t_display *display, t_ray *ray, int x)
{
   mlx_image_t *img;
   // REPRENDRE APRES REFACOTRISATION
    // DES PARAMETTRES DE LA FONCTION draw_wall_orientation
    img = get_texture(display, ray);
    printf("img = %p\n", img);
    if (ray->side == 1){
        if (ray->step.y > 0) 
            draw_ligne_height(display,img,  x, ray->draw_start, ray->draw_end);
            // draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, MY_WHITE);
        else
            draw_ligne_height(display,img, x, ray->draw_start, ray->draw_end );
    }
    else{
        if(ray->step.x > 0)
            draw_ligne_height(display,img, x, ray->draw_start, ray->draw_end);
        else 
            draw_ligne_height(display,img,  x, ray->draw_start, ray->draw_end);
    } 
}
// void draw_wall_orientation(t_display *display, t_ray *ray,int x)//original function
// {
//     if (ray->side == 1){
//         if (ray->step.y > 0) 
//                 draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end,PURPLE );
//             // draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end, MY_WHITE);
//         else
//             draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end,MAGENTA );
//     }
//     else{
//         if(ray->step.x > 0)
//             draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end,BLUE );
//         else 
//             draw_ligne_height(display->img, x, ray->draw_start, ray->draw_end,MY_WHITE );
//     } 
// }


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