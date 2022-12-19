/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:27:59 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/17 15:34:53 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (vars->frame % 8000 == 0)
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
