/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:56:38 by gloms             #+#    #+#             */
/*   Updated: 2024/05/21 14:40:30 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_filename(char *file)
{
	int	i;

	i = -1;
	while (file[++i] != '\0')
	{
		if (file[i] == '.')
		{
			if (file[i + 1] == 'c' && file[i + 2] == 'u' && file[i + 3] == 'b'
				&& file[i + 4] == '\0')
				return (1);
		}
	}
	return (0);
}
