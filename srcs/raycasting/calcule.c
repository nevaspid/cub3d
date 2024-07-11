/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:22:10 by oliove            #+#    #+#             */
/*   Updated: 2024/07/11 01:51:33 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	angle_rad(double angle)
{
	return (angle * M_PI / 180);
}

double	distance(t_vec_d a, t_vec_d b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}

// int	ft_atoi_mod(const char *str)
// {
// 	int	i;
// 	int	sign;
// 	int	nbr;

// 	i = 0;
// 	sign = 1;
// 	nbr = 0;
// 	if (ft_strlen((char *)str) > 3)
// 		return (-1);
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign *= -1;
// 		i++;
// 	}
// 	if (str[i] == '-' || str[i] == '+')
// 		return (0);
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		nbr = nbr * 10 + (str[i] - 48);
// 		i++;
// 	}
// 	return (sign * nbr);
// }

// u_int32_t	create_rgbt(unsigned char r, unsigned char g, unsigned char b,
		// unsigned char t)
// {
// 	return (*(int *)(unsigned char [4]){t, b, g, r});
// }

// uint32_t	extract_color(char **color)
// {
// 	return (create_rgbt(
// 			(unsigned char)ft_atoi_mod(color[0]),
// 			(unsigned char)ft_atoi_mod(color[1]),
// 			(unsigned char)ft_atoi_mod(color[2]),
// 			255));
// }

void	load_asset(t_display *display, mlx_texture_t *text, mlx_image_t **asset,
		char *path)
{
	text = mlx_load_png(path);
	if (!text)
	{
		printf("ERROR : Asset not found\n");
		exit(0);
	}
	*asset = mlx_texture_to_image(display->mlx, text);
	mlx_delete_texture(text);
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

/*

******
******
******

****** ****** ******
*/

u_int32_t	get_color(int x, int y, mlx_image_t *img)
{
	uint32_t	*pixel;
	u_int32_t	color;

	(void)x;
	color = 0;
	pixel = NULL;
	pixel = (uint32_t *)(img->pixels + (x + y * (img->width))
			* sizeof(uint32_t));
	color = *pixel;
	return (get_rgba_tex(color));
}
