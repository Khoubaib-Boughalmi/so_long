/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:04:35 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/19 17:45:52 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_wall(char **map, t_player player_pos, int c)
{
	if (c == 2)
	{
		if (map[player_pos.ypos][player_pos.xpos + 1] == '1')
			return (1);
	}
	else if (c == 0)
	{
		if (map[player_pos.ypos][player_pos.xpos - 1] == '1')
			return (1);
	}
	else if (c == 13)
	{
		if (map[player_pos.ypos - 1][player_pos.xpos] == '1')
			return (1);
	}
	else if (c == 1)
	{
		if (map[player_pos.ypos + 1][player_pos.xpos] == '1')
			return (1);
	}
	return (0);
}

int	is_collectable_core(char **map, t_new_pos *new_pos)
{
	if (map[new_pos->new_ypos][new_pos->new_xpos] == 'C')
	{
		map[new_pos->new_ypos][new_pos->new_xpos] = '0';
		return (1);
	}
	return (0);
}

int	is_collectable(char **map, t_player player_pos, int c)
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
	return (is_collectable_core(map, &new_pos));
}

int	is_exit_core(char **map, t_new_pos *new_pos, t_vars *vars)
{
	if (map[new_pos->new_ypos][new_pos->new_xpos] == 'E' \
		&& vars->player_pos.collected == vars->component.collectable)
	{
		ft_printf("\n~~~~~~~ CONGRATS YOU WON ~~~~~~~");
		return (1);
	}
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_tent, \
			vars->exit_pos.xpos * 40, vars->exit_pos.ypos * 40);
	return (0);
}

int	is_exit(char **map, t_vars *vars, int c)
{
	t_new_pos	new_pos;

	new_pos.new_xpos = vars->player_pos.xpos;
	new_pos.new_ypos = vars->player_pos.ypos;
	if (c == 2)
		new_pos.new_xpos = vars->player_pos.xpos + 1;
	else if (c == 0)
		new_pos.new_xpos = vars->player_pos.xpos - 1;
	else if (c == 13)
		new_pos.new_ypos = vars->player_pos.ypos - 1;
	else if (c == 1)
		new_pos.new_ypos = vars->player_pos.ypos + 1;
	return (is_exit_core(map, &new_pos, vars));
}
