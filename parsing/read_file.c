/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:57:31 by gloms             #+#    #+#             */
/*   Updated: 2024/05/03 17:04:53 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	read_parse_store(char *file, t_mem_alloc *lst, t_display *d)
{
	int		fd;
	char	*line;
	char	buf[2];

	if (!check_filename(file))
	{
		printf("Error\nFile is not a .cub file\n");
		exit(0); //! a free & exit
	}
	line = NULL;
	buf[1] = '\0';
	fd = open(file, O_RDONLY);
	while (read(fd, buf, 1) == 1)
		line = ft_strjoin(line, buf, lst);
	d->m->file = ft_split(line, '\n', lst);
	check_tab(d, lst);
	//! suite du parsing part d'ici
	return;
}
