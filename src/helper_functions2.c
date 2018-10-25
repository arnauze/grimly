/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:26:26 by amagnan           #+#    #+#             */
/*   Updated: 2018/10/22 15:26:26 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/grimly.h"

t_variables				*g_variables;

t_point					*get_exit(char **map)
{
	t_point				*exit;
	int					i;
	int					j;
	int					count;

	count = 0;
	i = 0;
	exit = NULL;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == g_variables->exit)
				add_node(&exit, allocate_coord(j, i), -1, NULL);
			j++;
		}
		i++;
	}
	return (exit);
}

int						compare_coord(t_point *exit, t_point *current)
{
	t_point				*tmp;

	tmp = exit;
	while (tmp)
	{
		if ((tmp->coord->y == current->coord->y - 1 &&
			tmp->coord->x == current->coord->x) ||
			(tmp->coord->y == current->coord->y + 1
				&& tmp->coord->x == current->coord->x) ||
			(tmp->coord->y == current->coord->y
				&& tmp->coord->x == current->coord->x + 1) ||
			(tmp->coord->y == current->coord->y
				&& tmp->coord->x == current->coord->x - 1))
		{
			tmp = NULL;
			return (1);
		}
		tmp = tmp->next;
	}
	tmp = NULL;
	return (-1);
}
