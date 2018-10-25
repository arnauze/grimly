/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:22:41 by amagnan           #+#    #+#             */
/*   Updated: 2018/10/22 15:22:42 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/grimly.h"

t_variables				*g_variables;

int						is_empty(char c)
{
	int					i;

	i = (c == g_variables->empty) ? 1 : -1;
	return (i);
}

char					**allocate_map(int x, int y)
{
	int					i;
	char				**new_map;

	i = 0;
	if (!(new_map = (char **)malloc(sizeof(char *) * y)))
		return (NULL);
	while (new_map[i])
		new_map[i] = ft_strnew(x);
	new_map[y] = NULL;
	return (new_map);
}

t_coord					*allocate_coord(int x, int y)
{
	t_coord				*coord;

	if (!(coord = (t_coord *)malloc(sizeof(t_coord))))
		return (NULL);
	coord->x = x;
	coord->y = y;
	return (coord);
}

int						is_exit(int x, int y, t_point *exit)
{
	while (exit)
	{
		if (x == exit->coord->x && y == exit->coord->y)
			return (1);
		exit = exit->next;
	}
	return (-1);
}

t_point					*get_entrance(char **map)
{
	int					i;
	int					j;
	t_point				*point;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == g_variables->entrance)
				break ;
			j++;
		}
		if (map[i][j] == g_variables->entrance)
			break ;
		i++;
	}
	point = make_node(allocate_coord(j, i), 0, NULL, NULL);
	return (point);
}
