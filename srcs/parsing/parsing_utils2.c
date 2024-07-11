/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:57:09 by gloms             #+#    #+#             */
/*   Updated: 2024/07/12 00:12:55 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*return_paths(char *to_search, char **file, t_mem_alloc *m)
{
	int		file_line;
	int		start;
	char	*path;

	file_line = 0;
	start = 0;
	if (search_flag_in_tab(to_search, file) != -1)
		file_line = search_flag_in_tab(to_search, file);
	else
	{
		printf("ERROR : missing flag %s\n", to_search);
		free_and_exit(m, NULL);
	}
	if (find_path_in_line(file[file_line]) != ft_strlen(file[file_line]))
		start = find_path_in_line(file[file_line]);
	else
		free_and_exit(m, NULL);
	path = ft_substr(file[file_line], start, ft_strlen(file[file_line]) - start,
			m);
	return (path);
}

char	*return_rgb(char *to_search, char **file, t_mem_alloc *m)
{
	int		file_line;
	int		start;
	char	*rgb;

	file_line = 0;
	start = 0;
	if (search_flag_in_tab(to_search, file) != -1)
		file_line = search_flag_in_tab(to_search, file);
	else
	{
		printf("ERROR : missing flag %s\n", to_search);
		free_and_exit(m, NULL);
	}
	if (find_rgb_in_line(file[file_line]) != ft_strlen(file[file_line]))
		start = find_rgb_in_line(file[file_line]);
	else
		free_and_exit(m, NULL);
	rgb = ft_substr(file[file_line], start, ft_strlen(file[file_line]) - start,
			m);
	return (rgb);
}

int	go_to_endof_file(char **file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	return (--i);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == '\0')
		return (1);
	return (0);
}

char	**copy_tab(char **src, t_mem_alloc *m)
{
	char	**dst;
	int		i;

	i = 0;
	dst = mem_alloc(m, sizeof(char *) * (count_lines(src) + 1));
	while (src[i])
	{
		dst[i] = ft_strdup(src[i], m);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
