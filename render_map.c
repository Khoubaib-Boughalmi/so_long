/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:51:03 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/07 15:30:15 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// render map's element based on the map matrix
void render_map_components(t_vars *vars, t_map *map_info, char **map)
{
	int i = 0;
	int j = 0;
	while (i < map_info->o_rows)
	{
		j = 0;
		while (j < map_info->o_cols)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img_ground, j * 40, i * 40);
			if(map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_tree, j * 40, i * 40);
			else if(map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_key, j * 40, i * 40);
			else if(map[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_player_right, j * 40, i * 40);
			else if(map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img_tent, j * 40, i * 40);
			j++;
		}
		i++;
	}
}

void key_hook_core(t_vars *param, char key, t_new_pos *new_pos, void *image)
{
	if (is_wall(param->map, param->player_pos, key))
	   {
			param->player_pos.steps++;
	   		if(is_collectable(param->map, param->player_pos, key))
		   		param->player_pos.collected++;
			mlx_put_image_to_window(param->mlx, param->win, param->img_ground, \
					param->player_pos.xpos * 40, param->player_pos.ypos * 40);
			param->player_pos.xpos = new_pos->new_xpos;
			param->player_pos.ypos = new_pos->new_ypos;
			mlx_put_image_to_window(param->mlx, param->win, image, \
					param->player_pos.xpos * 40, param->player_pos.ypos * 40);

	   }
}

// void norminette_dzb()

//add key handlers to key events
int key_hook(int button, t_vars *param)
{	
	t_new_pos new_pos;
	
	new_pos.new_xpos = param->player_pos.xpos;
	new_pos.new_ypos = param->player_pos.ypos;
	if (button == 2)
	{
		new_pos.new_xpos += 1;
		key_hook_core(param, 'D', &new_pos, param->img_player_right);
	}
		
    if (button == 0) // A
	{
		new_pos.new_xpos -= 1;
		key_hook_core(param, 'A', &new_pos, param->img_player_left);
	}
   
   if (button == 1) // S
   {
		new_pos.new_ypos += 1;
		key_hook_core(param, 'S', &new_pos, param->img_player_front);
	}
	if (button == 13) // W
	{
		new_pos.new_ypos -= 1;
		key_hook_core(param, 'W', &new_pos, param->img_player_back);
	}
	return 0; 	 
}

//initiate variables and populate structs
void render_map(t_vars *vars, t_map *map_info, char **map_matrix)
{
	int w;
	int h;

	w = 0;
	h = 0;
    vars->map = map_matrix;
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, map_info->o_cols * 40,\
	 map_info->o_rows * 40, "lainie JR");
	vars->img_ground = mlx_xpm_file_to_image(vars->mlx, "img/ground.xpm", &w, &h);
    vars->img_tree = mlx_xpm_file_to_image(vars->mlx, "img/tree.xpm", &w, &h);
    vars->img_player_right = mlx_xpm_file_to_image(vars->mlx, "img/pright.xpm", &w, &h);
    vars->img_player_left = mlx_xpm_file_to_image(vars->mlx, "img/pleft.xpm", &w, &h);
    vars->img_player_back = mlx_xpm_file_to_image(vars->mlx, "img/pback.xpm", &w, &h);
    vars->img_player_front = mlx_xpm_file_to_image(vars->mlx, "img/pfront.xpm", &w, &h);
    vars->img_key = mlx_xpm_file_to_image(vars->mlx, "img/key.xpm", &w, &h);
    vars->img_tent = mlx_xpm_file_to_image(vars->mlx, "img/tent.xpm", &w, &h);
	render_map_components(vars, map_info, map_matrix);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop(vars->mlx);
}
