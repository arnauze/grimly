/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:32:04 by amagnan           #+#    #+#             */
/*   Updated: 2018/10/22 10:32:05 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/grimly.h"

t_variables				*g_variables;

int						is_valid(char c)
{
	if (c == g_variables->full || c == g_variables->empty ||
		c == g_variables->entrance || c == g_variables->exit || c == '\n')
		return (1);
	return (-1);
}

int						syntax_error(char **map, int i, int j)
{
	int					ent;
	int					ex;

	ex = 0;
	ent = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_valid(map[i][j]) == -1)
				return (-1);
			if (map[i][j] == g_variables->entrance)
				ent++;
			else if (map[i][j] == g_variables->exit)
				ex++;
			j++;
		}
		i++;
	}
	if (ex == 0 || ent != 1)
		return (-1);
	return (1);
}

char					**get_map(int fd, int size_x, int size_y, int i)
{
	int					j;
	char				c;
	char				**map;

	map = (char **)malloc(sizeof(char *) * size_y + 1);
	map[i] = ft_strnew(size_x);
	j = 0;
	while (read(fd, &c, 1) == 1 && i <= size_y)
	{
		map[i][j++] = c;
		if (c == '\n' && j == size_x)
		{
			map[i][j] = '\0';
			j = 0;
			i++;
			map[i] = ft_strnew(size_x);
		}
	}
	map[i] = NULL;
	if (j != 0 || i >= size_y + 1)
	{
		ft_putstr_fd("MAP ERROR\n", 2);
		return (NULL);
	}
	return (map);
}
