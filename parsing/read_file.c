/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:57:31 by gloms             #+#    #+#             */
/*   Updated: 2024/01/26 19:12:57 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**read_and_store(char *file, t_mem_alloc *lst)
{
	int		fd;
	char	*line;
	char	buf[2];

	line = NULL;
	buf[1] = '\0';
	fd = open(file, O_RDONLY);
	while (read(fd, buf, 1) == 1)
		line = ft_strjoin(line, buf, lst);
	return (ft_split(line, '\n', lst));
}
