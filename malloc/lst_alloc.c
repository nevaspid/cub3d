/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:45:59 by gloms             #+#    #+#             */
/*   Updated: 2024/01/19 17:09:16 by gloms            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_mem_alloc	*mem_lstnew(void)
{
	t_mem_alloc	*new_alloc;

	new_alloc = malloc(sizeof(t_mem_alloc));
	if (!new_alloc)
		return (0);
	new_alloc->next = NULL;
	return (new_alloc);
}

void	lst_add_back(t_mem_alloc *lst, t_mem_alloc *new_alloc)
{
	while (lst->next)
		lst = lst->next;
	lst->next = new_alloc;
}

void	*mem_alloc(t_mem_alloc *lst, size_t size)
{
	void 		*ret;
	t_mem_alloc *new_alloc;

	new_alloc = mem_lstnew();
	ret = malloc(size);
	new_alloc->content = ret;
	lst_add_back(lst, new_alloc);
	return (ret);
}
