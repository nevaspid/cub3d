/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:48:13 by gloms             #+#    #+#             */
/*   Updated: 2024/07/20 15:51:42 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_player(char **map, int x, int y)
{
	if (map[y][x] == 'N' || map[y][x] == 'S' ||
		map[y][x] == 'E' || map[y][x] == 'W')
		return (1);
	return (0);
}

int	search_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map, j, i))
			{
				*x = j;
				*y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
