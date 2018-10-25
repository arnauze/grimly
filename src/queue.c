/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 08:57:09 by amagnan           #+#    #+#             */
/*   Updated: 2018/10/22 08:57:09 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/grimly.h"

t_point			*make_node(t_coord *coord, int dist,
	t_point *next, t_point *papa)
{
	t_point		*point;

	if (!(point = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	point->coord = coord;
	point->dist = dist;
	point->oui_papa = papa;
	point->next = next;
	return (point);
}

void			add_node(t_point **head, t_coord *coord,
	int dist, t_point *papa)
{
	g_validate[coord->y][coord->x] = '1';
	if (!*head)
		*head = make_node(coord, dist, NULL, papa);
	else
		*head = make_node(coord, dist, *head, papa);
}

t_point			*pop_node(t_point **head)
{
	t_point		*current;
	t_point		*prev;
	t_point		*point;

	current = *head;
	if (!(*head)->next)
	{
		point = make_node(allocate_coord((*head)->coord->x,
			(*head)->coord->y), (*head)->dist, NULL, (*head)->oui_papa);
		free(*head);
		*head = NULL;
	}
	else
	{
		while (current->next)
		{
			prev = current;
			current = current->next;
		}
		point = make_node(allocate_coord(current->coord->x,
			current->coord->y), current->dist, NULL, current->oui_papa);
		free(prev->next);
		prev->next = NULL;
	}
	return (point);
}

t_point			*get_tail(t_point *head)
{
	t_point		*current;

	current = head;
	while (current->next)
		current = current->next;
	return (current);
}
