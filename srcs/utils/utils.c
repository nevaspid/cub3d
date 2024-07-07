/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:34:03 by gloms             #+#    #+#             */
/*   Updated: 2024/07/07 21:31:29 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoin(char *s1, char *s2, t_mem_alloc *lst)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	str = mem_alloc(lst, sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i++] = s2[j];
		j++;
	}
	str[i] = '\0';
	return (str);
}

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

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

int	is_char(char c, t_display *d)
{
	if (c == 'N')
		d->p_angle = 3 * M_PI / 2;
	else if (c == 'S')
		d->p_angle = M_PI / 2;
	else if (c == 'E')
		d->p_angle = 0;
	else if (c == 'W')
		d->p_angle = M_PI;
	else
		return (0);
	return (1);
}

char	*ft_substr(char *s, unsigned int start, size_t len, t_mem_alloc *lst)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	str = mem_alloc(lst, sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
