/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:57:31 by gloms             #+#    #+#             */
/*   Updated: 2024/07/08 15:29:27 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_parse_store(char *file, t_mem_alloc *lst, t_display *d)
{
	int		fd;
	char	*line;
	char	buf[2];

	if (!check_filename(file))
	{
		printf("Error\nFile is not a .cub file\n");
		free_and_exit(lst);
	}
	line = NULL;
	buf[1] = '\0';
	fd = open(file, O_RDONLY);
	if(fd < 0)
	{
		printf("Error\nFile not found\n");
		free_and_exit(lst);
	}
	while (read(fd, buf, 1) == 1)
		line = ft_strjoin(line, buf, lst);
	d->m->file = ft_split(line, '\n', lst);
	check_tab(d, lst);
	return ;
}
