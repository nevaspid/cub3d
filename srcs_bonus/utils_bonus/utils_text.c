/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 01:47:03 by oliove            #+#    #+#             */
/*   Updated: 2024/07/11 01:51:00 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	inverse_lerp(double min, double max, double value)
{
	if (min != max)
		return (clamp01((value - min) / (max - min)));
	else
		return (0.0);
}

double	lerp(double min, double max, double t)
{
	return (min + clamp01(t) * (max - min));
}

double	clamp01(double value)
{
	if (value < 0)
		return (0);
	else if (value > 1)
		return (1);
	else
		return (value);
}
