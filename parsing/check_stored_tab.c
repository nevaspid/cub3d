/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stored_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:49:34 by gloms             #+#    #+#             */
/*   Updated: 2024/04/24 21:40:40 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//- je veux chercher un morceau de string dans un char **, flaggé par une suite de lettres
//- je parcours chaque string du char ** en utilisant strcmp pour chercher le flag -> search_flag_in_tab
//- je retourne le nº de la ligne flaggée
//- je cherche dans la ligne flaggée le morceau de string commençant part "./" -> find_path_in_line
//- je le stocke dans la structure adéquate
//- je recommence

int	check_tab(t_display *d, t_mem_alloc *malloc)
{
	store_paths(d->m->file, &d->m->paths, malloc);
}

int	store_paths(char **file, t_paths *p, t_mem_alloc *m)
{
	p->NO = return_paths("NO ", file, m);
	p->SO = return_paths("SO ", file, m);
	p->WE = return_paths("WE ", file, m);
	p->EA = return_paths("EA ", file, m);
	p->F = return_rgb("F ", file, m);
	p->C = return_rgb("C ", file, m);
}

char	*return_paths(char *to_search, char **file, t_mem_alloc *m)
{
	int		file_line;
	int		start;
	char	*path;

	if (search_flag_in_tab(to_search, file))
		file_line = search_flag_in_tab(to_search, file);
	else
	{
		printf("ERROR : missing flag %s\n", to_search);
		exit(0); //! a free and exit
	}
	if (find_path_in_line(file[file_line]) != ft_strlen(file[file_line]))
		start = find_path_in_line(file[file_line]);
	else
		exit(0); //! a free and exit
	path = ft_substr(file[file_line], start, ft_strlen(file[file_line]) - start, m);
	printf("path : %s\n", path);
	return (path);
}

char *return_rgb(char *to_search, char **file, t_mem_alloc *m)
{
	int		file_line;
	int		start;
	char	*rgb;

	if (search_flag_in_tab(to_search, file))
		file_line = search_flag_in_tab(to_search, file);
	else
	{
		printf("ERROR : missing flag %s\n", to_search);
		exit(0); //! a free and exit
	}
	if (find_rgb_in_line(file[file_line]) != ft_strlen(file[file_line]))
		start = find_rgb_in_line(file[file_line]);
	else
		exit(0); //! a free and exit
	rgb = ft_substr(file[file_line], start, ft_strlen(file[file_line]) - start, m);
	printf("rgb : %s\n", rgb);
	return (rgb);
}
