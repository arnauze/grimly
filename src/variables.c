/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:29:59 by amagnan           #+#    #+#             */
/*   Updated: 2018/10/22 10:30:00 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/grimly.h"

t_variables				*g_variables;

t_variables				*set_variables(void)
{
	if (!(g_variables = (t_variables*)malloc(sizeof(t_variables))))
		return (NULL);
	g_variables->size_x = -1;
	g_variables->size_y = -1;
	g_variables->full = '\0';
	g_variables->empty = '\0';
	g_variables->path = '\0';
	g_variables->entrance = '\0';
	g_variables->exit = '\0';
	return (g_variables);
}

void					get_y(char *str, int *i)
{
	char				*tmp;
	int					j;

	tmp = ft_strnew(10);
	j = 0;
	while (str[*i] && ft_isdigit(str[*i]) == 1)
	{
		tmp[j] = str[*i];
		*i += -1;
		j++;
	}
	tmp[j] = '\0';
	tmp = ft_strrevdup(tmp);
	g_variables->size_y = ft_atoi(tmp);
	ft_strdel(&tmp);
}

void					get_x(char *str, int *i)
{
	char				*tmp;
	int					j;

	tmp = ft_strnew(10);
	j = 0;
	while (str[*i] && ft_isdigit(str[*i]) == 1)
	{
		tmp[j] = str[*i];
		*i += -1;
		j++;
	}
	tmp[j] = '\0';
	*i += -1;
	tmp = ft_strrevdup(tmp);
	g_variables->size_x = ft_atoi(tmp);
	ft_strdel(&tmp);
}

void					*get_variables(int fd, int i)
{
	char				c;
	char				*str;

	str = ft_strnew(26);
	g_variables = set_variables();
	while (read(fd, &c, 1) == 1 && c != '\n')
	{
		str[i] = c;
		i++;
	}
	i--;
	g_variables->exit = str[i--];
	g_variables->entrance = str[i--];
	g_variables->path = str[i--];
	g_variables->empty = str[i--];
	g_variables->full = str[i--];
	get_x(str, &i);
	get_y(str, &i);
	if (str[i])
	{
		ft_putstr_fd("MAP ERROR\n", 2);
		return (NULL);
	}
	ft_strdel(&str);
	return (g_variables);
}
