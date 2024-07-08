/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:03:31 by oliove            #+#    #+#             */
/*   Updated: 2024/07/08 17:08:21 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_addr(char *where,void *addr)
{
	printf("%s == [%p]\n", where, addr);
}

void	print_info_struct(char *where, char *format, void *addr)
{
    printf("%s == ",where);
    printf(format,addr);
    printf("\n");
}

void	print_value_ray(t_ray *ray, t_player *player, char *where, char *who, int n)
{
	(void)player;
	(void)n;
	printf("\033\t[0;31m%s in %s\033[0;m \n",who,where);
	printf("\033\t[0;34mray->id[%d]\033[0;m\n", ray->id);
	printf("[%d]ray->dir->x [%f]\n",n, ray->dir.x);
	printf("[%d]ray->dir->y [%f]\n",n, ray->dir.y);
	printf("[%d]ray->map->x [%f]\n",n, ray->map.x);
	printf("[%d]ray->map->y [%f]\n",n, ray->map.y);
	printf("[%d]ray->step->x [%f]\n",n, ray->step.x);
	printf("[%d]ray->step->y [%f]\n",n, ray->step.y);
	printf("[%d]ray->side [%d]\n",n, ray->side);
	printf("[%d]ray->wall_x [%f]\n",n, ray->wall_x);
	printf("[%d]ray->wall_dist [%f]\n",n, ray->wall_dist);
	printf("[%d]ray->end.x [%f]\n",n, ray->end.x);
	printf("[%d]ray->end.y [%f]\n",n, ray->end.y);
	printf("\033[0;31m\t end [%d] %s\033[0;m\n",n,where);
}

void print_value_player(t_player *player, char *where, char *who)
{
	printf("\033[0;31m%s in %s\033[0;m \n",who,where);
	printf("player->angle [%f]\n ", player->angle);
	printf("player->dir->x [%f]\n", player->dir.x);
	printf("player->dir->y [%f]\n", player->dir.y);
	printf("player->plane->x [%f]\n", player->plane.x);
	printf("player->plane->y [%f]\n", player->plane.y);
	printf("player->pos.x [%f]\n", player->pos.x);
	printf("player->pos.y [%f]\n", player->pos.y);
	printf("\033[0;31mend %s\033[0;m\n",where);	
}

void print_move(t_display *display)
{
	printf("\033[0;31in print_move\033[0;m\n");
	printf("data->display->player->pos.x [%d]\n",
		display->raycast->player->img->instances[0].x);
	printf("data->display->player->pos.y [%d]\n",
		display->raycast->player->img->instances[0].y);
	printf("\033[0;33mend print_move\033[0;m\n");
}


void print_value_recast(t_player *player, t_ray *ray, char *where, char *who)
{
	printf("\033[0;31m%s in %s\033[0;m \n",who,where);
	printf("player->angle [%f] | ", player->angle);
	printf("player->pos.x [%f] player->pos.y [%f] | ",
		player->pos.x, player->pos.y);
	printf("ray->dir->x [%f] ray->dir->y [%f] | ", ray->dir.x, ray->map.x);
	printf("ray->map->x [%f] ray->map->y [%f |", ray->map.x, ray->map.y);
	printf("ray->step->x [%f] ray->step->y [%f] ", ray->step.x, ray->step.y);
	printf("ray->hit [%d]\n", ray->hit);
	printf("ray->side_dist->x [%f]\n", ray->side_dist.x);
	printf("\033[0;31end %s\033[0;m\n",where);
}


void print_value_camera(t_camera *camera, char *where, char *who)
{
	printf("\033[0;31m%s in %s\033[0;m \n",who,where);
	printf("camera->angle_cam [%f]\n", camera->angle_cam);
	printf("camera->angle_min [%f]\n", camera->angle_min);
	printf("camera->angle_max [%f]\n", camera->angle_max);
	printf("camera->angle_ray [%f]\n", camera->angle_ray);
	printf("camera->dir->x [%f]\n", camera->dir.x);
	printf("camera->dir->y [%f]\n", camera->dir.y);
	printf("camera->plane->x [%f]\n", camera->plane.x);
	printf("camera->plane->y [%f]\n", camera->plane.y);
	printf("camera->nb_ray [%d]\n", camera->nb_ray);
	printf("camera->angle_ray [%f]\n", camera->angle_ray);
	printf("\033[0;31mend %s\033[0;m\n",where);
}
void print_texture(t_texture *text, char *where, char *who)
{
	printf("\033[0;31m%s in %s\033[0;m \n",who,where);
	printf("text->north [%p] image == [%p]\n", text->north, text->north_img);
	printf("text->south [%p] image == [%p]\n", text->south, text->south_img);
	printf("text->west [%p] image == [%p]\n", text->west, text->west_img);
	printf("text->east [%p] image == [%p]\n", text->east, text->east_img);
	printf("\033[0;31mend %s\033[0;m\n",where);
}
