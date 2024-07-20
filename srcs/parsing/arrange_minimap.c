/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 01:14:17 by gloms             #+#    #+#             */
/*   Updated: 2024/07/20 05:23:19 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*fill_with_ones(int len, t_mem_alloc *malloc)
{
	char	*str;
	int		i;

	i = 0;
	str = mem_alloc(malloc, sizeof(char) * (len + 1));
	str[len] = '\0';
	while (i < len)
	{
		str[i] = '1';
		i++;
	}
	return (str);
}

char	*put_one_start_end(char *to_surround, char *prev, char *next,
		t_mem_alloc *malloc)
{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen(to_surround);
	if (ft_strlen(prev) > len)
		len = ft_strlen(prev);
	if (ft_strlen(next) > len)
		len += ft_strlen(next) - len + 1;
	str = mem_alloc(malloc, sizeof(char) * (len + 3));
	str[0] = '1';
	i = 1;
	while (i <= ft_strlen(to_surround))
	{
		str[i] = to_surround[i - 1];
		i++;
	}
	while (i < len)
		str[i++] = '1';
	str[i + 1] = '\0';
	return (str);
}
