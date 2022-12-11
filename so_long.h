/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:55:55 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/11 16:22:42 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <fcntl.h>
# include <mlx.h>

# include "./ft_printf/ft_printf.h"

typedef struct s_map{
	int	o_cols;
	int	o_rows;
}	t_map;

typedef struct s_cord{
	int	i;
	int	j;
}	t_cord;

typedef struct s_component{
	int	player;
	int	collectable;
	int	exit;
	int	other;
}	t_component;

typedef struct s_player {
	int	xpos;
	int	ypos;
	int	steps;
	int	collected;
}				t_player;

typedef struct s_exit_pos {
	int	xpos;
	int	ypos;
}				t_exit_pos;

typedef struct s_img {
	void			*img_ground;
	void			*img_tree;
	void			*img_player_right;
	void			*img_player_left;
	void			*img_player_back;
	void			*img_player_front;
	void			*img_key;
	void			*img_tent;
}				t_img;

typedef struct s_vars {
	void			*mlx;
	void			*win;
	char			**map;
	t_img			img;
	t_player		player_pos;
	t_exit_pos		exit_pos;
	t_component		component;
	t_map			map_info;
}				t_vars;

typedef struct s_new_pos {
	int	new_xpos;
	int	new_ypos;
}				t_new_pos;

//map_to_matrix file
char	**free_map_matrix(char **map_matrix, int pos);
char	**allocate_map_matrix(t_map *map_info);
void	populate_map_data(t_map *map_info, char **map_matrix, char *map_name);

//map_check file
int		get_num_rows_map(int fd);
int		get_num_cols_map(int fd);
int		populate_map_metadata(t_map *map_info, char *map_name);
int		check_valid_walls(char **map, t_map *map_info);
int		check_components(char **map, t_map *map_info, t_vars *vars);
int		check_is_rectangular(t_map *map_info);
int		check_valid_cols(t_map *map_info, char *map_name);

//utils.c
int		ft_printf_err(char *str);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *c);
char	*ft_strjoin(char const *s1, char const *s2);

//render_map.c
void	render_map(t_vars *vars, t_map *map_info, char **map);
void	render_map_components(t_vars *vars, t_map *map_info, char **map);
//key_hook.c
int		key_hook_core(t_vars *vars, int key, t_new_pos *new_pos, void *image);
int		key_hook(int button, t_vars *vars);

//positions.c
void	get_initial_pos(t_vars *vars, t_map *map_info, char **map_matrix);
int		is_wall(char **map, t_player player_pos, int c);
int		is_collectable(char **map, t_player player_pos, int c);
int		is_exit(char **map, t_vars *vars, int c);
//check_path.c
int		check_path_core(char **map, t_map *info, int i, int j);
int		check_path(t_vars *vars, t_map *map_info, char *map_name);
//exit.c
int		safe_exit(t_vars *vars);

#endif