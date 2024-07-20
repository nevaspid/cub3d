/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_alloc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 05:31:47 by oliove            #+#    #+#             */
/*   Updated: 2024/07/20 05:32:13 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src && i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

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
	void		*ret;
	t_mem_alloc	*new_alloc;
	size_t		i;

	i = 0;
	new_alloc = mem_lstnew();
	ret = malloc(size);
	if (ret == 0)
		free_and_exit(lst, "Error\nMalloc failed\n");
	while (i < size)
		((char *)ret)[i++] = 0;
	new_alloc->content = ret;
	lst_add_back(lst, new_alloc);
	return (ret);
}
