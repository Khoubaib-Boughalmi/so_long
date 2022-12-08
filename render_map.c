/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:51:03 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/08 16:57:58 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// render map's element based on the map matrix
void	initial_render_map_components(t_vars *vars, char **map, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_ground, j
		* 40, i * 40);
	if (map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_tree, j
			* 40, i * 40);
	else if (map[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_key, j
			* 40, i * 40);
	else if (map[i][j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img_player_right, j * 40, i * 40);
	else if (map[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_tent, j
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

void	player_mlx_put_image_to_window(t_vars *vars, int key)
{
	if (key == 2)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_player_right,
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
	if (key == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_player_left,
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
	if (key == 13)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_player_back,
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
	if (key == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_player_front,
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
}

int	key_hook_core(t_vars *vars, int key, t_new_pos *new_pos, void *image)
{
	if (!is_wall(vars->map, vars->player_pos, key))
	{
		vars->player_pos.steps++;
		if (is_collectable(vars->map, vars->player_pos, key))
			vars->player_pos.collected++;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_ground,
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
		if (is_exit(vars->map, vars, key))
			exit(EXIT_SUCCESS);
		vars->player_pos.xpos = new_pos->new_xpos;
		vars->player_pos.ypos = new_pos->new_ypos;
		player_mlx_put_image_to_window(vars, key);
		ft_printf("Collected :%d Steps :%d\n",
			vars->player_pos.collected, vars->player_pos.steps);
	}
	return (0);
}

//add key handlers to key events
int	key_hook(int button, t_vars *vars)
{
	t_new_pos	new_pos;

	new_pos.new_xpos = vars->player_pos.xpos;
	new_pos.new_ypos = vars->player_pos.ypos;
	if (button == 2)
		new_pos.new_xpos += 1;
	else if (button == 0)
		new_pos.new_xpos -= 1;
	else if (button == 1)
		new_pos.new_ypos += 1;
	else if (button == 13)
		new_pos.new_ypos -= 1;
	else
		return (0);
	return (key_hook_core(vars, button, &new_pos, vars->img_player_right));
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
	vars->win = mlx_new_window(vars->mlx, map_info->o_cols * 40,
			map_info->o_rows * 40, "lainie JR");
	vars->img_ground = mlx_xpm_file_to_image(vars->mlx, "img/ground.xpm", &w,
			&h);
	vars->img_tree = mlx_xpm_file_to_image(vars->mlx, "img/tree.xpm", &w, &h);
	vars->img_player_right = mlx_xpm_file_to_image(vars->mlx, "img/pright.xpm",
			&w, &h);
	vars->img_player_left = mlx_xpm_file_to_image(vars->mlx, "img/pleft.xpm",
			&w, &h);
	vars->img_player_back = mlx_xpm_file_to_image(vars->mlx, "img/pback.xpm",
			&w, &h);
	vars->img_player_front = mlx_xpm_file_to_image(vars->mlx, "img/pfront.xpm",
			&w, &h);
	vars->img_key = mlx_xpm_file_to_image(vars->mlx, "img/key.xpm", &w, &h);
	vars->img_tent = mlx_xpm_file_to_image(vars->mlx, "img/tent.xpm", &w, &h);
	render_map_components(vars, map_info, map_matrix);
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_loop(vars->mlx);
}
