/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_render_map_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:23:03 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/18 16:12:21 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initial_render_map_components(t_vars *vars, char **map, int i, int j)
{
	t_player	*enemy;

	enemy = NULL;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ground, j
		* 40, i * 40);
	if (map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_tree, j
			* 40, i * 40);
	else if (map[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_key, j
			* 40, i * 40);
	else if (map[i][j] == 'P')
	{
		vars->player_pos.xpos = j;
		vars->player_pos.ypos = i;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.img_player_right, j * 40, i * 40);
	}
	if (map[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_tent, j
			* 40, i * 40);
	else if (map[i][j] == 'T')
		render_enemy(vars, enemy, i, j);
}

void	render_enemy(t_vars *vars, t_player *enemy, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_renemy, \
	j * 40, i * 40);
	enemy = malloc(sizeof(t_player));
	enemy->xpos = j;
	enemy->ypos = i;
	ft_lstadd_back(&vars->enemies, ft_lstnew(enemy));
}

void	render_map_components(t_vars *vars, t_map *map_info, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(void)vars;
	(void)map;
	while (i < map_info->o_rows)
	{
		j = -1;
		while (++j < map_info->o_cols)
			initial_render_map_components(vars, map, i, j);
		i++;
	}
}
