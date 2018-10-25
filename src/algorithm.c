/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:33:26 by amagnan           #+#    #+#             */
/*   Updated: 2018/10/22 15:33:27 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/grimly.h"

t_variables				*g_variables;
char					**g_validate;
int						g_dist;

void					add_nodes_in_queue(t_point **point)
{
	t_point				*coord;
	t_point				*tmp;

	tmp = get_tail(*point);
	g_dist = tmp->dist;
	coord = pop_node(point);
	if (coord->coord->y - 1 > 0 &&
		g_validate[coord->coord->y - 1][coord->coord->x] == '0')
		add_node(point, allocate_coord(coord->coord->x, coord->coord->y - 1),
			g_dist + 1, coord);
	if (coord->coord->x - 1 > 0 &&
		g_validate[coord->coord->y][coord->coord->x - 1] == '0')
		add_node(point, allocate_coord(coord->coord->x - 1, coord->coord->y),
			g_dist + 1, coord);
	if (coord->coord->x + 1 < g_variables->size_x
		&& g_validate[coord->coord->y][coord->coord->x + 1] == '0')
		add_node(point, allocate_coord(coord->coord->x + 1, coord->coord->y),
			g_dist + 1, coord);
	if (coord->coord->y + 1 < g_variables->size_y
		&& g_validate[coord->coord->y + 1][coord->coord->x] == '0')
		add_node(point, allocate_coord(coord->coord->x, coord->coord->y + 1),
			g_dist + 1, coord);
	coord = NULL;
	tmp = NULL;
}

char					**create_map(char **map, t_point *current)
{
	while (current && current->oui_papa)
	{
		map[current->coord->y][current->coord->x] = g_variables->path;
		current = current->oui_papa;
	}
	return (map);
}

char					**make_new_map(char **map)
{
	t_point				*current;
	t_point				*exit;
	t_point				*tail;

	current = get_entrance(map);
	exit = get_exit(map);
	while (current)
	{
		tail = get_tail(current);
		g_validate[tail->coord->y][tail->coord->x] = '1';
		if (compare_coord(exit, tail) == 1)
			break ;
		add_nodes_in_queue(&current);
	}
	if (!current)
	{
		ft_putstr_fd("MAP ERROR\n", 2);
		return (NULL);
	}
	map = create_map(map, tail);
	return (map);
}
