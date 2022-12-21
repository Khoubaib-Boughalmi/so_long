/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animated_components.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:41:38 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/21 16:07:04 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	animate_player(t_vars *vars)
{
	if (vars->frame % 300 == 0)
	{
		vars->animation = vars->animation % 3;
		if (vars->animation == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_tnt, \
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
		else if (vars->animation == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_tnt1, \
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_tnt2, \
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
		vars->animation++;
	}
	vars->frame++;
}

void	animate_exit(t_vars *vars)
{
	if (vars->frame_exit % 500 == 0)
	{
		vars->animation = vars->animation % 3;
		if (vars->animation == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->img.img_player_back, vars->exit_pos.xpos * 40, \
			vars->exit_pos.ypos * 40);
		else if (vars->animation == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->img.img_player_front, vars->exit_pos.xpos * 40, \
			vars->exit_pos.ypos * 40);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->img.img_player_right, vars->exit_pos.xpos * 40, \
			vars->exit_pos.ypos * 40);
		vars->animation++;
	}
	vars->frame_exit++;
}
