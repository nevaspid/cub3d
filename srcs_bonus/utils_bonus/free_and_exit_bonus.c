/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:41:34 by gloms             #+#    #+#             */
/*   Updated: 2024/07/12 00:13:59 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_and_exit(t_mem_alloc *malloc, char *str)
{
	t_mem_alloc	*tmp;

	if (str != NULL)
		printf("%s\n", str);
	if (!malloc)
		exit(0);
	while (malloc)
	{
		tmp = malloc->next;
		if (malloc->content)
			free(malloc->content);
		free(malloc);
		malloc = tmp;
	}
	exit(0);
}
