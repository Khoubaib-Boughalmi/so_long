/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:16:32 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/19 15:11:21 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//get initale position of the player and set it to vars struct
void	get_initial_pos(t_vars *vars, t_map *map_info, char **map_matrix)
{
	int	i;
	int	j;

	i = 0;
	ft_bzero(&vars->player_pos, sizeof(vars->player_pos));
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
