/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:51:03 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/12 16:07:34 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// render map's element based on the map matrix
void	initial_render_map_components(t_vars *vars, char **map, int i, int j)
{
	t_player *enemy;
	
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
	{
	
		// mlx_loop_hook(vars->mlx, render_player, vars);
		// render_player(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_enemy, j* 40, i * 40);
		enemy = malloc(sizeof(t_player));
		enemy->xpos = j;
		enemy->ypos = i;
		ft_lstadd_back(&vars->enemies, ft_lstnew(enemy));
	}
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
	vars->img.img_player_right = mlx_xpm_file_to_image(vars->mlx, \
	"img/pright.xpm", w, h);
	vars->img.img_player_left = mlx_xpm_file_to_image(vars->mlx, \
	"img/pleft.xpm", w, h);
	vars->img.img_player_back = mlx_xpm_file_to_image(vars->mlx, \
	"img/pback.xpm", w, h);
	vars->img.img_player_front = mlx_xpm_file_to_image(vars->mlx, \
	"img/pfront.xpm", w, h);
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
	vars->img.img_enemy = mlx_xpm_file_to_image(vars->mlx, \
	"img/enemy.xpm", w, h);
}

//initiate variables and populate structs

int render_player(t_vars *vars)
{
	int	s;

	s = 0;
	if (vars->frame % 500 == 0)
	{
		vars->animation = (vars->animation + 1) % 3;
		if (vars->animation == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_tnt, vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
		else if (vars->animation == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_tnt1, vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_tnt2, vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
	}
	if (vars->frame % 10000 == 0)
	{
		t_list *head;
		t_player *enemy;

		head = vars->enemies;
		while (head)
		{
			enemy = head->content;
			if (!is_wall(vars->map, *enemy, 2))
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ground, (enemy->xpos) * 40, enemy->ypos * 40);
				ft_printf("%d %d\n", enemy->xpos, enemy->ypos);
				vars->map[enemy->ypos][enemy->xpos] = '0';
				vars->map[enemy->ypos][enemy->xpos + 1] = 'T';
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_enemy, (enemy->xpos + 1) * 40, enemy->ypos * 40);
				if (vars->player_pos.xpos == enemy->xpos + 1 && vars->player_pos.ypos == enemy->ypos)
				{
					ft_printf("SLAYED BITCH");
					exit(EXIT_SUCCESS);
				}
				enemy->xpos++;
			}
			head = head->next;
		}
	}
	vars->frame++;
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
