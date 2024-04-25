/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:11:16 by gloms             #+#    #+#             */
/*   Updated: 2024/04/24 20:49:30 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//- je veux chercher un morceau de string dans un char **, flaggé par une suite de lettres
//- je parcours chaque string du char ** en utilisant strcmp pour chercher le flag
//- je retourne le nº de la ligne flaggée
//- je cherche dans la ligne flaggée le morceau de string commençant part "./"
//- je le stocke dans la structure adéquate
//- je recommence

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *a, char *to_cmp)
{
	int	j;

	j = 0;
	while(*a)
	{
		if (*a == to_cmp[j])
		{
			while (*a == to_cmp[j])
			{
				a++;
				j++;
				if (to_cmp[j] == '\0')
					return (1);
			}
		}
		j = 0;
		a++;
	}
	return (0);
}

int	find_path_in_line(char *tab_line)
{
	int	path_start;

	path_start = 0;
	while (tab_line[path_start] != '.')
		path_start++;
	if (path_start == ft_strlen(tab_line))
		printf("ERROR : path is not referenced as following : ./PATH");
	return (path_start); //! verifier si path_start == len(tab_line) dans la fonction parente
}

int	find_rgb_in_line(char *tab_line)
{
	int	path_start;

	path_start = 0;
	while (!is_digit(tab_line[path_start]))
		path_start++;
	if (path_start == ft_strlen(tab_line))
		printf("ERROR : RGB code is not referenced as following : R,G,B");
	return (path_start); //! verifier si path_start == len(tab_line) dans la fonction parente
}

int search_flag_in_tab(char *to_find, char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
	{
		if (ft_strcmp(tab[i], to_find))
			return (i);
	}
	return (-1);
}
