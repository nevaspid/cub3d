/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:22:10 by oliove            #+#    #+#             */
/*   Updated: 2024/06/01 03:18:03 by oliove           ###   ########.fr       */
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

