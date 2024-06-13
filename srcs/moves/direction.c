/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 01:10:18 by oliove            #+#    #+#             */
/*   Updated: 2024/06/13 03:23:31 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
// mlx_mousefunc ;
void mouse_hook(void *param)
{
    t_display *display;
    
    int32_t x;
    int32_t y;
    display = (t_display *)param;
    mlx_get_mouse_pos(display->mlx , &x, &y);
    
    mlx_set_mouse_pos(display->mlx, (int32_t)display->raycast->player->pos.x, (int32_t)display->raycast->player->pos.y);
    if(mlx_is_mouse_down(display->mlx, 1))
        printf("Pixel == [%d] [%d]\n",x, y );
    // mlx_set_mouse_pos(display->mlx, (int32_t)WIDTH / 2, (int32_t)HEIGHT / 2);
    printf("Pixel == [%d] [%d]\n",x, y );
    
    

}