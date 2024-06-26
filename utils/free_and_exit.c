/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:41:34 by gloms             #+#    #+#             */
/*   Updated: 2024/05/21 13:50:50 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_and_exit(t_mem_alloc *malloc)
{
	t_mem_alloc	*tmp;

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
