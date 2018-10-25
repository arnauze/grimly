/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagnan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 08:49:15 by amagnan           #+#    #+#             */
/*   Updated: 2018/10/24 19:41:37 by amagnan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_point
{
	t_coord				*coord;
	long int			dist;
	struct s_point		*oui_papa;
	struct s_point		*next;
}						t_point;

typedef struct			s_variables
{
	int					size_x;
	int					size_y;
	char				full;
	char				empty;
	char				path;
	char				entrance;
	char				exit;
}						t_variables;

t_variables				*g_variables;
char					**g_validate;
int						g_dist;

void					add_nodes_in_queue(t_point **point);
char					**create_map(char **map, t_point *current);
char					**make_new_map(char **map);
void					ft_error();
int						is_empty(char c);
char					**allocate_map(int x, int y);
t_coord					*allocate_coord(int x, int y);
int						is_exit(int	x, int y, t_point *exit);
t_point					*get_entrance();
t_point					*get_exit();
int						compare_coord(t_point *exit, t_point *current);
int						is_valid(char c);
int						syntax_error(char **map, int i, int j);
char					**get_map(int fd, int size_x, int size_y, int i);
t_point					*make_node(t_coord *coord, int dist, t_point *next,
	t_point *papa);
void					add_node(t_point **head, t_coord *coord, int dist,
	t_point *papa);
t_point					*pop_node(t_point **head);
t_variables				*set_variables();
void					get_y(char *str, int *i);
void					get_x(char *str, int *i);
void					get_variables(int fd, int i);
int						check_if_exit(t_point *coord, t_point **point,
	t_point *exit, int dist);
t_point					*get_tail(t_point *head);
void					print_map(char **map);

#endif
