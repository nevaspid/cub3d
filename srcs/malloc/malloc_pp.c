/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_pp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:12:32 by oliove            #+#    #+#             */
/*   Updated: 2024/07/11 01:52:54 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	lstadd_back(t_mem_alloc **first, t_mem_alloc *new)
{
	t_mem_alloc	*tmp;

	printf("hey %p\n", first);
	if (!first)
		return ;
	if (*first == NULL)
		*first = new;
	else
	{
		tmp = *first;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_mem_alloc	*ft_lst_new_malloc(void *content)
{
	t_mem_alloc	*new;

	new = malloc(sizeof(t_mem_alloc));
	if (!new)
		return (NULL);
	if (new)
	{
		new->content = content;
		new->next = NULL;
	}
	return (new);
}

void	*malloc_new(t_mem_alloc **lst, size_t size)
{
	t_mem_alloc		*new;
	size_t			i;
	unsigned char	*ret;

	i = 0;
	ret = malloc(size);
	if (!ret)
		return (NULL);
	while (i < size)
		ret[i++] = 0;
	new = ft_lst_new_malloc(ret);
	if (!new)
		return (NULL);
	lstadd_back(lst, new);
	return (ret);
}

void	free_maloc(t_mem_alloc **lst)
{
	t_mem_alloc	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	free(*lst);
	*lst = NULL;
}
