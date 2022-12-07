/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:04:35 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/06 15:04:23 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_initial_pos(t_vars *vars, t_map *map_info, char **map_matrix)
{
	int	i;
	int	j;

	i = 0;
	ft_bzero(&vars->player_pos, sizeof(vars->player_pos)); //initialize player pos to 0 (x, y, #steps)
	while (i < map_info->o_rows)
	{
		j = 0;
		while (j < map_info->o_cols)
		{
			if (map_matrix[i][j] == 'P')
			{
				vars->player_pos.xpos = j;
				vars->player_pos.ypos = i;
			}
			else if (map_matrix[i][j] == 'E')
			{
				vars->exit_pos.xpos = j;
				vars->exit_pos.ypos = i;
			}
			j++;
		}
		i++;
	}	
}
int is_wall(char **map, t_player player_pos, char c)
{
	if (c == 'D')
	{
		if (map[player_pos.ypos][player_pos.xpos + 1] == '1')
			return (0);
	}
	else if (c == 'A')
	{
		if (map[player_pos.ypos][player_pos.xpos - 1] == '1')
			return (0);
	}
	else if (c == 'W')
	{
		if (map[player_pos.ypos - 1][player_pos.xpos] == '1')
			return (0);
	}
	else if (c == 'S')
	{
		if (map[player_pos.ypos + 1][player_pos.xpos] == '1')
			return (0);
	}
	return (1);
}

int is_collectable(char **map, t_player player_pos, char c)
{
	if (c == 'D')
	{
		if (map[player_pos.ypos][player_pos.xpos + 1] == 'C')
		{
			map[player_pos.ypos][player_pos.xpos + 1] = '0';
			return (1);
		}
	}
	else if (c == 'A')
	{
		if (map[player_pos.ypos][player_pos.xpos - 1] == 'C')
		{
			map[player_pos.ypos][player_pos.xpos - 1] = '0';
			return (1);
		}
	}
	else if (c == 'W')
	{
		if (map[player_pos.ypos - 1][player_pos.xpos] == 'C')
		{
			map[player_pos.ypos - 1][player_pos.xpos] = '0';
			return (1);
		}
	}
	else if (c == 'S')
	{
		if (map[player_pos.ypos + 1][player_pos.xpos] == 'C')
		{
			map[player_pos.ypos + 1][player_pos.xpos] = '0';
			return (1);
		}
	}
	return (0);
	
}