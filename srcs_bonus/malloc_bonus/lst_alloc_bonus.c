/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_alloc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:45:59 by gloms             #+#    #+#             */
/*   Updated: 2024/07/18 04:53:04by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char    *ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t    i;

	i = 0;
	while (src && i < n && src[i])
	{
		printf("\033[1;33mft_strncpy %p\033[0m\n", dest);
		dest[i] = src[i];
		i++;
	}
	// printf("\033[1;33mdest = %s src = %s n = %zu\n\033[0m", dest, src, n);
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

// rajouter des 1 sup NULL
	// F() for 1

char **map_gf(t_mem_alloc *malloc, char **map)
{
	int i;
	char **new;
	int max_len;
	int j;

	new = mem_alloc(malloc, sizeof(char *) * (count_lines(map) + 3));
	max_len = 0;
	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) > max_len)
			max_len = ft_strlen(map[i]);
	}
	i = -1;
	while (++i < count_lines(map) + 2)
	{
		printf("\033[1;31mcount_line = %p i = %d \033[0m\n", &map[i], i);
		if (i > count_lines(map))
			new[i] = mem_alloc(malloc, sizeof(char) * (ft_strlen(map[i -1]) + 3));
		else
			new[i] = mem_alloc(malloc, sizeof(char) * (ft_strlen(map[i]) + 3));
	}
	// new[i] = NULL;
	i = -1;
	j = -1;
	while (++i < count_lines(map) + 2)
	{
		j = -1;
		printf("\033[1;31mcount_line = %s i = %d \033[0m\n",map[i], i);
		if (i == 0)
		{
			while (i == 0 && *map && ++j < ft_strlen(map[i]) + 2){
				
				new[i][j] = '1';
			}
			printf("\033[1;32m IF new[%d]  = %s \033[0m\n",i, new[i]);
			// new[i][j + 1] = '\0';
		}
		else if (i == count_lines(map) + 2)
		{
			while (++j < ft_strlen(map[i - 1]) + 2)
				new[i][j] = '1';
			printf("\033[1;32m else if new[%d]  = %s \033[0m\n",i, new[i]);
			// new[i][j + 1] = '\0';
		}
		else
		{
			while (i < count_lines(map) + 2 && i != 0 && i != count_lines(map) + 1)
			{
				printf("\033[1;32m else i = %d \033[0m\n", i);
				printf("\033[1;32m i = %d poi %p \033[0m\n", i, new[i]);
				new[i][0] = '1';
				ft_strncpy(&new[i][1], map[i - 1], ft_strlen(map[i - 1]) + 1);
				printf("\033[1;32m1111 else new[%d]  = %s \033[0m\n", i, new[i]);
				new[i][ft_strlen(map[i]) + 1] = '1';
				new[i][ft_strlen(map[i]) + 2] = '\0';
				printf("\033[1;32m  else new[%d] end = %s \033[0m\n", i, new[i]);
				i++;
			}
		}
	}
	// new[i] = '\0';
	i = -1;
	while (new[++i])
		printf("#%s#  i = %d\n",new[i],i);
	
	return (new);

}
// char **map_gf(t_mem_alloc *malloc, char **map)
// {
// 	int i;
// 	char **new;
// 	int max_len;
// 	int j;

// 	new = mem_alloc(malloc, sizeof(char *) * (count_lines(map) + 3));
// 	max_len = 0;
// 	i = -1;
// 	while (map[++i])
// 	{
// 		if (ft_strlen(map[i]) > max_len)
// 			max_len = ft_strlen(map[i]);
// 	}
// 	i = -1;
// 	while (++i < count_lines(map) + 2)
// 	{
// 		new[i] = mem_alloc(malloc, sizeof(char) * (max_len + 3));
// 	}
// 	new[i] = NULL;
// 	i = -1;
// 	j = -1;
// 	printf("\033[1;31m new == %d\033[0m\n", count_lines(new));
// 	while (++i < count_lines(map) + 2)
// 	{
	
// 		if (i == 0 || i == count_lines(new) - 1)
// 		{
// 			printf("\033[1;31mcount_line = %d i = %d \033[0m\n",count_lines(map) + 1, i);
// 			if ( i == 0)
// 			{
				
// 				while (++j < ft_strlen(map[i]) + 2)
// 					new[i][j] = '1';
// 			}
// 			else if (i == count_lines(map))
// 			{
// 				while (++j < ft_strlen(map[i]) + 2)
// 					new[i][j] = '1';
// 				// if (i == count_lines(map))
// 				// 	while (++j < ft_strlen(map[i]) + 2)
// 				// 		new[i][j] = '1';
// 			}
// 			printf("\033[1;31m if new[i] = %s \033[0m\n", new[i]);
// 		}
// 		else
// 		{
// 			printf("\033[1;32m else i = %d \033[0m\n", i);
// 			new[i][0] = '1';
// 			ft_strncpy(&new[i][1], map[i - 1], ft_strlen(map[i - 1]) + 2);
// 			printf("\033[1;32m1111 else new[%d]  = %s \033[0m\n",i, new[i]);
// 			new[i][ft_strlen(map[i]) + 1] = '1';
// 			new[i][ft_strlen(map[i]) + 2] = '\0';
// 			printf("\033[1;32m else new[%d] end = %s \033[0m\n",i, new[i]);
// 		}
// 	}
// 	i = -1;
// 	while (new[++i])
// 		printf("%s\n",new[i]);
	
// 	return (new);

// }


// char    **map_w_null_background(t_mem_alloc *x_chain, char **map)
// {
// 	int        i;
// 	char    **new;
// 	int        max_len;

// 	new = mem_alloc(x_chain, sizeof(char *) * (count_lines(map) + 3));
// 	max_len = 0;
// 	i = -1;
// 	printf("\033[1;31mwhile == 1 before copy \033[0m\n");
// 	while (map[++i]){
// 		printf("%s\n",map[i]);
// 		if (ft_strlen(map[i]) > max_len)
// 			max_len = ft_strlen(map[i]);
// 	}
// 	i = -1;
// 	//-->rapel reprise -> // commence a faire la fonction pour mettre des 1 
// 		//  au lieu de NULL!!!!!!
// 	while (++i < count_lines(map) + 2){
// 		new[i] = mem_alloc(x_chain, sizeof(char) * (max_len + 3));
// 	}
// 	new[i] = NULL;// Cette ligne reste nécessaire pour marquer la fin du tableau de pointeurs
// 	// i = -1;	
	
// 	i = -1;
// 	int j = -1;
// 	printf("\033[1;32m Count_line new = %d \033[0m\n", count_lines(new));
// 	printf("\033[1;32m Count_line map = %d \033[0m\n", count_lines(map));
// 	printf("\033[1;31mwhile == 1 after copy \033[0m\n");
// 	while (++i < count_lines(map) + 2)
// 	{
// 		if (i == 0 || i == count_lines(map) + 1)
// 		{
// 			j = -1;
// 			while (++j < ft_strlen(map[i]) + 2)
// 				new[i][j] = '1';
// 			printf("\033[1;33m p_new[i] = %p\n p_new[i][j] = %p \n new[i][j] = %s \033[0m\n", new, &new[i], new[i]);
// 			if (i == count_lines(map) + 1)
// 			{
// 				printf("laaaaaaaaaaaaaaalalallallllll\n");
// 				while (++j < ft_strlen(map[i -1]) + 2)
// 					new[i][j] = '1';
// 				printf("\033[1;33mi = %d p_new[i] = %p\n p_new[i][j] = %p \n new[i][j] = %s \033[0m\n",i, new, &new[i], new[i]);
// 				check_map_d(new); 
// 				if (i == count_lines(map - 1))
// 					while (++j < ft_strlen(map[i - 1]) + 2)
// 						new[i][j] = '1';
// 			}
// 		}
// 		else	
// 		{
// 			// if (i == count_lines(map) + 1)
// 			// 	while (++j < ft_strlen(map[i]) + 2)
// 			// 		new[i][j] = '1';
// 			// else{
				
// 			// }
// 			new[i][0] = '1';
// 			// printf("\033[1;33m p_new[i] = %p\n p_new[i][j] = %p \n new[i][j] = %s \033[0m\n", new, &new[i], new[i]);
// 			// printf("\033[1;33m new = %p \n else new[i] = %s \033[0m\n", new, new[i]);
// 			// printf("\033[1;33m i = [%d] &&  p_new[i] = %d \033[0m\n",i, ft_strlen(map[i]));
// 			ft_strncpy(&new[i][1], map[i], ft_strlen(map[i]) + 2);// Assurez-vous que le '1' est toujours le premier caractère, même après la copie
// 			new[i][ft_strlen(map[i]) + 1] = '1';
// 			new[i][ft_strlen(map[i]) + 2] = '\0';
// 			printf("\033[1;33m%delse new[i][j] = %s \033[0m\n",i, new[i]);
// 			// printf("\033[1;33m p_new[i] = %p\n p_new[i][j] = %p \n new[i][j] = %s eslse\033[0m\n", new, &new[i], new[i]);
			
// 		}
// 		// ft_strncpy(&new[i][1],map[i],ft_strlen(map[i]));
// 		// printf("\033[1;31m new = %p \n map[i] = %s \033[0m\n", new, map[i]);
// 		// printf("%s\n",map[i]);
// 	}
// 	printf("\033[1;31mmap_w_null_background \033[0m\n");
// 	check_map_d(new); 
// 	return (new);
// }
