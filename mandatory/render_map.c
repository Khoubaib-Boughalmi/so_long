/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:51:03 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/19 16:08:22 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// render map's element based on the map matrix
void	initial_render_map_components(t_vars *vars, char **map, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ground, j
		* 40, i * 40);
	if (map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_tree, j
			* 40, i * 40);
	else if (map[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_key, j
			* 40, i * 40);
	else if (map[i][j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.img_player_right, j * 40, i * 40);
	else if (map[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_tent, j
			* 40, i * 40);
}

void	render_map_components(t_vars *vars, t_map *map_info, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map_info->o_rows)
	{
		j = -1;
		while (++j < map_info->o_cols)
			initial_render_map_components(vars, map, i, j);
		i++;
	}
}

void	initiate_img_vars(t_vars *vars, int *w, int *h)
{
	vars->img.img_ground = mlx_xpm_file_to_image(vars->mlx, \
		"mandatory/img/ground.xpm", w, h);
	vars->img.img_tree = mlx_xpm_file_to_image(vars->mlx, \
	"mandatory/img/tree.xpm", w, h);
	vars->img.img_player_right = mlx_xpm_file_to_image(vars->mlx, \
	"mandatory/img/pright.xpm", w, h);
	vars->img.img_player_left = mlx_xpm_file_to_image(vars->mlx, \
	"mandatory/img/pleft.xpm", w, h);
	vars->img.img_player_back = mlx_xpm_file_to_image(vars->mlx, \
	"mandatory/img/pback.xpm", w, h);
	vars->img.img_player_front = mlx_xpm_file_to_image(vars->mlx, \
	"mandatory/img/pfront.xpm", w, h);
	vars->img.img_key = mlx_xpm_file_to_image(vars->mlx, \
	"mandatory/img/key.xpm", w, h);
	vars->img.img_tent = mlx_xpm_file_to_image(vars->mlx, \
	"mandatory/img/tent.xpm", w, h);
}

//initiate variables and populate structs
void	render_map(t_vars *vars, t_map *map_info, char **map_matrix)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	vars->map = map_matrix;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, map_info->o_cols * 40, \
		map_info->o_rows * 40, "so_long");
	initiate_img_vars(vars, &w, &h);
	render_map_components(vars, map_info, map_matrix);
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, safe_exit, vars);
	mlx_loop(vars->mlx);
}
