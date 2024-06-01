#include "../cub3d.h"


void    print_addr(char *where,void *addr)
{
    printf("%s == [%p]\n",where, addr);
}


void print_info_struct(char *where, char *format, void *addr)
{

    printf("%s == ",where);
    printf(format,addr);
    printf("\n");
}


void print_value_ray(t_ray *ray, t_player *player, char *where, char *who)
{
    printf("\033[0;31m%s in %s\033[0;m \n",who,where);
	printf("player->dir->x [%f]\n", player->dir.x);
	printf("player->dir->y [%f]\n", player->dir.y);
	printf("player->plane->x [%f]\n", player->plane.x);
	printf("player->plane->y [%f]\n", player->plane.y);
	printf("player->pos.x [%f]\n", player->pos.x);
	printf("player->pos.y [%f]\n", player->pos.y);
	printf("ray->dir->x [%f]\n", ray->dir.x);
	printf("ray->dir->y [%f]\n", ray->dir.y);
	printf("ray->map->x [%f]\n", ray->map.x);
	printf("ray->map->y [%f]\n", ray->map.y);
	// printf("ray->img_ray.width [%d]\n",ray->img_ray->width);
	// printf("ray->img_ray.height [%d]\n",ray->img_ray->height);
    printf("\033[0;31end %s\033[0;m\n",where);
}

void print_value_player(t_player *player, char *where, char *who)
{
	printf("\033[0;31m%s in %s\033[0;m \n",who,where);
	printf("player->dir->x [%f]\n", player->dir.x);
	printf("player->dir->y [%f]\n", player->dir.y);
	printf("player->plane->x [%f]\n", player->plane.x);
	printf("player->plane->y [%f]\n", player->plane.y);
	printf("player->pos.x [%f]\n", player->pos.x);
	printf("player->pos.y [%f]\n", player->pos.y);
	printf("player->px [%d]\n", player->px);
	printf("player->py [%d]\n", player->py);
	printf("\033[0;31end %s\033[0;m\n",where);
}

void print_move(t_display *display)
{
	printf("\033[0;31in print_move\033[0;m\n");
	printf("data->display->player->pos.x [%d]\n", display->raycast->player->img->instances[0].x);
	printf("data->display->player->pos.y [%d]\n", display->raycast->player->img->instances[0].y);
	// printf("data->display->player->dir->x [%f]\n", data->display->player->dir->x);
	// printf("data->display->player->dir->y [%f]\n", data->display->player->dir->y);
	// printf("data->display->player->plane->x [%f]\n", data->display->player->plane->x);
	// printf("data->display->player->plane->y [%f]\n", data->display->player->plane->y);
	printf("\033[0;33mend print_move\033[0;m\n");
}


void print_value_recast(t_player *player, t_ray *ray, char *where, char *who)
{
	printf("\033[0;31m%s in %s\033[0;m \n",who,where);

	printf("player->pos.x [%f] player->pos.y [%f]\n", player->pos.x, player->pos.y);
	printf("player->angle [%f]\n", player->angle);
	printf("ray->dir->x [%f] ray->dir->y [%f]\n", ray->dir.x, ray->map.x);
	printf("ray->map->x [%f] ray->map->y [%f\n", ray->map.x, ray->map.y);
	printf("ray->step->x [%f] ray->step->y [%f]\n", ray->step.x, ray->step.y);
	printf("ray->hit [%d]\n", ray->hit);
	
	
	
	// printf("ray->side_dist->x [%f]\n", ray->side_dist.x);
	// printf("ray->side_dist->y [%f]\n", ray->side_dist.y);
	// printf("ray->side [%d]\n", ray->side);
	printf("\033[0;31end %s\033[0;m\n",where);
}