/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:51:03 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/21 16:03:10 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//initiate variables and populate structs
void	move_enemy(t_vars *vars, t_player *enemy, int key, t_new_pos *n_pos)
{
	if (!is_wall(vars->map, *enemy, key) && \
		!is_collectable_enemy(vars->map, *enemy, key))
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ground, \
			(enemy->xpos) * 40, enemy->ypos * 40);
		vars->map[enemy->ypos][enemy->xpos] = '0';
		vars->map[n_pos->new_ypos][n_pos->new_xpos] = 'T';
		if (key == 0 || key == 13)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_renemy, \
			n_pos->new_xpos * 40, n_pos->new_ypos * 40);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_lenemy, \
			n_pos->new_xpos * 40, n_pos->new_ypos * 40);
		if (vars->player_pos.xpos == n_pos->new_xpos && \
			vars->player_pos.ypos == n_pos->new_ypos)
		{
			ft_printf("SLAYED BIT*H");
			exit(EXIT_SUCCESS);
		}
		enemy->xpos = n_pos->new_xpos;
		enemy->ypos = n_pos->new_ypos;
	}
}

void	render_player_core(t_vars *vars, t_player *enemy, int pos, t_new_pos np)
{
	if (pos == 0)
	{
		np.new_xpos = enemy->xpos + 1;
		move_enemy(vars, enemy, 2, &np);
	}
	if (pos == 1)
	{
		np.new_xpos = enemy->xpos - 1;
		move_enemy(vars, enemy, 0, &np);
	}
	else if (pos == 2)
	{
		np.new_ypos = enemy->ypos - 1;
		move_enemy(vars, enemy, 13, &np);
	}
	else if (pos == 3)
	{
		np.new_ypos = enemy->ypos + 1;
		move_enemy(vars, enemy, 1, &np);
	}
}

int	render_player(t_vars *vars)
{
	int			pos;
	t_list		*head;
	t_player	*enemy;
	t_new_pos	new_pos;

	animate_player(vars);
	animate_exit(vars);
	if (vars->frame % 3000 == 0)
	{
		head = vars->enemies;
		while (head)
		{
			enemy = head->content;
			pos = rand() % 4;
			new_pos.new_xpos = enemy->xpos;
			new_pos.new_ypos = enemy->ypos;
			render_player_core(vars, enemy, pos, new_pos);
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
