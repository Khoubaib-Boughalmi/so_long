/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:04:24 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/19 15:19:40 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_mlx_put_image_to_window(t_vars *vars, int key)
{
	if (key == 2)
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->img.img_tnt,
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
	if (key == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_tnt,
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
	if (key == 13)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_tnt,
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
	if (key == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->img.img_tnt,
			vars->player_pos.xpos * 40, vars->player_pos.ypos * 40);
}

int	key_hook_core(t_vars *vars, int key, t_new_pos *new_pos)
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
		if (is_enemy(vars->map, vars->player_pos, key))
			exit(EXIT_SUCCESS);
		vars->player_pos.xpos = new_pos->new_xpos;
		vars->player_pos.ypos = new_pos->new_ypos;
		player_mlx_put_image_to_window(vars, key);
		put_collectable_to_window(vars);
	}
	return (0);
}

void	put_collectable_to_window(t_vars *vars)
{
	char	*str1;
	char	*str2;

	mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->img.img_tree, 3 * 40, 0);
	str1 = ft_itoa(vars->player_pos.collected);
	str2 = ft_strjoin("COLLECTED ==>", str1);
	mlx_string_put(vars->mlx, vars->win, 0, 0, 0xFFFFFF, str2);
	free(str1);
	free(str2);
	ft_printf("\rCollected :%d Steps :%d",
		vars->player_pos.collected, vars->player_pos.steps);
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
	return (key_hook_core(vars, button, &new_pos));
}
