/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:51:03 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/17 15:10:31 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// render map's element based on the map matrix

void render_enemy(t_vars *vars, t_player *enemy, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_renemy, \
	j * 40, i * 40);
	enemy = malloc(sizeof(t_player));
	enemy->xpos = j;
	enemy->ypos = i;
	ft_lstadd_back(&vars->enemies, ft_lstnew(enemy));
}

void	initial_render_map_components(t_vars *vars, char **map, int i, int j)
{
	t_player	*enemy;

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
	else if (map[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_tent, j
			* 40, i * 40);
	else if (map[i][j] == 'T')
		render_enemy(vars, enemy, i, j);
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
		"img/ground.xpm", w, h);
	vars->img.img_tree = mlx_xpm_file_to_image(vars->mlx, \
	"img/tree.xpm", w, h);
	vars->img.img_key = mlx_xpm_file_to_image(vars->mlx, \
	"img/key.xpm", w, h);
	vars->img.img_tent = mlx_xpm_file_to_image(vars->mlx, \
	"img/tent.xpm", w, h);
	vars->img.img_tnt = mlx_xpm_file_to_image(vars->mlx, \
	"img/ball.xpm", w, h);
	vars->img.img_tnt1 = mlx_xpm_file_to_image(vars->mlx, \
	"img/ball1.xpm", w, h);
	vars->img.img_tnt2 = mlx_xpm_file_to_image(vars->mlx, \
	"img/ball2.xpm", w, h);
	vars->img.img_renemy = mlx_xpm_file_to_image(vars->mlx, \
	"img/renemy.xpm", w, h);
	vars->img.img_lenemy = mlx_xpm_file_to_image(vars->mlx, \
	"img/lenemy.xpm", w, h);
}

int	is_collectable_enemy_core(char **map, t_new_pos *new_pos)
{
	if (map[new_pos->new_ypos][new_pos->new_xpos] == 'C' || \
	map[new_pos->new_ypos][new_pos->new_xpos] == 'T' || \
	map[new_pos->new_ypos][new_pos->new_xpos] == 'E')
		return (1);
	return (0);
}

int	is_collectable_enemy(char **map, t_player player_pos, int c)
{
	t_new_pos	new_pos;

	new_pos.new_xpos = player_pos.xpos;
	new_pos.new_ypos = player_pos.ypos;
	if (c == 2)
		new_pos.new_xpos = player_pos.xpos + 1;
	else if (c == 0)
		new_pos.new_xpos = player_pos.xpos - 1;
	else if (c == 13)
		new_pos.new_ypos = player_pos.ypos - 1;
	else if (c == 1)
		new_pos.new_ypos = player_pos.ypos + 1;
	return (is_collectable_enemy_core(map, &new_pos));
}

//initiate variables and populate structs

void	animate_player(t_vars *vars)
{
	if (vars->frame % 300 == 0)
	{
		vars->animation = (vars->animation + 1) % 3;
		if (vars->animation == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_tnt, \
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
		else if (vars->animation == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_tnt1, \
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_tnt2, \
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
	}
	vars->frame++;
}

void move_enemy(t_vars *vars, t_player *enemy, int key, t_new_pos *n_pos)
{
	if (!is_wall(vars->map, *enemy, key) && !is_collectable_enemy(vars->map, *enemy, key))
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ground, (enemy->xpos) * 40, enemy->ypos * 40);
		vars->map[enemy->ypos][enemy->xpos] = '0';
		vars->map[n_pos->new_ypos][n_pos->new_xpos] = 'T';
		if(key == 0 || key == 13)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_renemy, n_pos->new_xpos * 40, n_pos->new_ypos * 40);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_lenemy, n_pos->new_xpos * 40, n_pos->new_ypos * 40);
		if (vars->player_pos.xpos == n_pos->new_xpos && vars->player_pos.ypos == n_pos->new_ypos)
		{
			ft_printf("SLAYED BITCH");
			exit(EXIT_SUCCESS);
		}
		enemy->xpos = n_pos->new_xpos;
		enemy->ypos = n_pos->new_ypos;
	}
}

int	render_player(t_vars *vars)
{
	int			pos;
	t_list		*head;
	t_player	*enemy;
	t_new_pos 	new_pos;

	animate_player(vars);
	if (vars->frame % 8000 == 0)
	{
		head = vars->enemies;
		while (head)
		{
			enemy = head->content;
			pos = rand() % 4;
			new_pos.new_xpos = enemy->xpos;
			new_pos.new_ypos = enemy->ypos;
			if (pos == 0)
			{
				new_pos.new_xpos = enemy->xpos + 1;
				move_enemy(vars, enemy, 2, &new_pos);
			}
			if (pos == 1)
			{
				new_pos.new_xpos = enemy->xpos - 1;
				move_enemy(vars, enemy, 0, &new_pos);
			}
			else if (pos == 2)
			{
				new_pos.new_ypos = enemy->ypos - 1;
				move_enemy(vars, enemy, 13, &new_pos);
			}
			else if (pos == 3)
			{
				new_pos.new_ypos = enemy->ypos + 1;
				move_enemy(vars, enemy, 1, &new_pos);
			}
			head = head->next;
		}
	}
	return (0);
}
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
	vars->map_info.o_cols = map_info->o_cols;
	vars->map_info.o_rows = map_info->o_rows;
	render_map_components(vars, map_info, map_matrix);
	mlx_loop_hook(vars->mlx, render_player, vars);
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, safe_exit, vars);
	vars->frame = 0;
	mlx_loop(vars->mlx);
}
