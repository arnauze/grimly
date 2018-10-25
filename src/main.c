/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 08:52:21 by amagnan           #+#    #+#             */
/*   Updated: 2018/10/22 08:52:21 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/grimly.h"
#include <stdio.h>

t_variables				*g_variables;
char					**g_validate;

char					**make_binary_map(char **map)
{
	char				**new_map;
	int					i;
	int					j;

	i = 0;
	new_map = (char **)malloc(sizeof(char *) * g_variables->size_y + 1);
	while (map[i])
	{
		new_map[i] = ft_strnew(g_variables->size_x);
		j = 0;
		{
			while (map[i][j])
			{
				if (map[i][j] == g_variables->empty)
					new_map[i][j] = '0';
				else
					new_map[i][j] = '1';
				j++;
			}
		}
		i++;
	}
	new_map[i] = 0;
	return (new_map);
}

void					print_map(char **map)
{
	int					i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		i++;
	}
	b_printf("RESULT IN %d STEPS!\n", g_dist);
}

char					**grimly(int fd)
{
	char				**map;
	int					i;

	i = 0;
	get_variables(fd, 0);
	if (g_variables->size_x * g_variables->size_y > 1000000000)
		return (NULL);
	if ((map = get_map(fd, g_variables->size_x + 1,
		g_variables->size_y, 0)) == NULL)
		return (NULL);
	g_validate = make_binary_map(map);
	if (syntax_error(map, 0, 0) == 1)
	{
		map = make_new_map(map);
		if (map)
			print_map(map);
	}
	else
	{
		ft_putstr_fd("MAP ERROR\n", 2);
		return (NULL);
	}
	return (map);
}

int						main(int argc, char **argv)
{
	int					fd;
	int					i;
	char				**map;

	i = 0;
	if (argc > 1)
	{
		while (argv[++i])
		{
			fd = open(argv[i], O_RDONLY);
			map = grimly(fd);
			close(fd);
			if (map)
				ft_mapdel(map);
			map = NULL;
		}
	}
	else
		map = grimly(0);
	ft_mapdel(g_validate);
	g_validate = NULL;
	return (0);
}
