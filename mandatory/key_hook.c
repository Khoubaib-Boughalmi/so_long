/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:04:24 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/11 16:06:45 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_mlx_put_image_to_window(t_vars *vars, int key)
{
	if (key == 2)
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->img.img_player_right,
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
	if (key == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_player_left,
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
	if (key == 13)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_player_back,
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
	if (key == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->img.img_player_front,
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
}

int	key_hook_core(t_vars *vars, int key, t_new_pos *new_pos, void *image)
{
	if (!is_wall(vars->map, vars->player_pos, key))
	{
		vars->player_pos.steps++;
		if (is_collectable(vars->map, vars->player_pos, key))
			vars->player_pos.collected++;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ground,
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
		if (is_exit(vars->map, vars, key))
			exit(EXIT_SUCCESS);
		vars->player_pos.xpos = new_pos->new_xpos;
		vars->player_pos.ypos = new_pos->new_ypos;
		player_mlx_put_image_to_window(vars, key);
		ft_printf("Collected :%d Steps :%d\n",
			vars->player_pos.collected, vars->player_pos.steps);
	}
	return (0);
}

//add key handlers to key events
int	key_hook(int button, t_vars *vars)
{
	t_new_pos	new_pos;

	new_pos.new_xpos = vars->player_pos.xpos;
	new_pos.new_ypos = vars->player_pos.ypos;
	if (button == 2)
		new_pos.new_xpos += 1;
	else if (button == 0)
		new_pos.new_xpos -= 1;
	else if (button == 1)
		new_pos.new_ypos += 1;
	else if (button == 13)
		new_pos.new_ypos -= 1;
	else if (button == 53)
		safe_exit(vars);
	else
		return (0);
	return (key_hook_core(vars, button, &new_pos, vars->img.img_player_right));
}
