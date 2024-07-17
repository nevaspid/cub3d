/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_alloc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doctor <doctor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:45:59 by gloms             #+#    #+#             */
/*   Updated: 2024/07/17 20:25:20 by doctor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char    *ft_strncpy(char *dest, const char *src, size_t n)
{
    size_t    i;

    i = 0;
    while (i < n && src[i])
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
	size_t i;
    
	i = 0;
	new_alloc = mem_lstnew();
	ret = malloc(size);
	if( ret == 0)
		free_and_exit(lst, "Error\nMalloc failed\n");
	while(i < size)
		((char *)ret)[i++] = 0;
	new_alloc->content = ret;
	lst_add_back(lst, new_alloc);
	return (ret);
}

char    **map_w_null_background(t_mem_alloc *x_chain, char **map)
{
    int        i;
    char    **new;
    int        max_len;

    new = mem_alloc(x_chain, sizeof(char *) * (count_lines(map) + 3));
    max_len = 0;
    i = -1;
    while (map[++i])
        if (ft_strlen(map[i]) > max_len)
            max_len = ft_strlen(map[i]);
    i = -1;
    while (++i < count_lines(map) + 2)
        new[i] = mem_alloc(x_chain, sizeof(char) * (max_len + 3));
    new[i] = NULL;
    i = -1;
    while (map[++i])
        ft_strncpy(&new[i + 1][1], map[i], ft_strlen(map[i]));
    return (new);
}
