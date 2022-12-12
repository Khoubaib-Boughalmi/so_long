/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:05:20 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/11 17:27:01 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_enemy_core(char **map, t_new_pos *new_pos)
{
	if (map[new_pos->new_ypos][new_pos->new_xpos] == 'T')
	{
		ft_printf("U'VE BEEN SLAYED BY ENEMY");
		return (1);
	}
	return (0);
}

int	is_enemy(char **map, t_player player_pos, int c)
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
	return (is_enemy_core(map, &new_pos));
}
