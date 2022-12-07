/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:51:03 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/06 15:43:24 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void render_map_components(t_vars *vars, t_map map_info, char **map)
{
	int i = 0;
	int j = 0;
	while (i < map_info.o_rows)
	{
		j = 0;
		while (j < map_info.o_cols)
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

int key_hook(int button, t_vars *param)
{	
	
	printf("aaaaa %d\n", param->component.collectable);
	if(param->player_pos.collected == param->component.collectable)
	{
		printf("all good\n");
	}
	if (button == 2) // D
	{
	   if (is_wall(param->map, param->player_pos, 'D'))
	   {
		   param->player_pos.steps++;
	   		if(is_collectable(param->map, param->player_pos, 'D'))
		   		param->player_pos.collected++;
			mlx_put_image_to_window(param->mlx, param->win, param->img_ground, \
					param->player_pos.xpos * 40, param->player_pos.ypos * 40);
			param->player_pos.xpos += 1;
			mlx_put_image_to_window(param->mlx, param->win, param->img_player_right, \
					param->player_pos.xpos * 40, param->player_pos.ypos * 40);
	   }
   }
    if (button == 0) // A
   	{   
		if (is_wall(param->map, param->player_pos, 'A'))
	 	{
			param->player_pos.steps++;
			if(is_collectable(param->map, param->player_pos, 'A'))
		   		param->player_pos.collected++;
			mlx_put_image_to_window(param->mlx, param->win, param->img_ground, \
					param->player_pos.xpos * 40, param->player_pos.ypos * 40);
			param->player_pos.xpos -= 1;
			mlx_put_image_to_window(param->mlx, param->win, param->img_player_left, \
					param->player_pos.xpos * 40, param->player_pos.ypos * 40) ;

		}	
   	}
   if (button == 1) // S
   {
	   if (is_wall(param->map, param->player_pos, 'S'))
	 	{
			param->player_pos.steps++;
			if(is_collectable(param->map, param->player_pos, 'S'))
		   		param->player_pos.collected++;
			mlx_put_image_to_window(param->mlx, param->win, param->img_ground, \
					param->player_pos.xpos * 40, param->player_pos.ypos * 40);
			param->player_pos.ypos += 1;
			mlx_put_image_to_window(param->mlx, param->win, param->img_player_front, \
					param->player_pos.xpos * 40, param->player_pos.ypos * 40);
		
		}
   }	
   if (button == 13) // W
   {
	   if (is_wall(param->map, param->player_pos, 'W'))
	 	{
			param->player_pos.steps++;
			if(is_collectable(param->map, param->player_pos, 'W'))
		   		param->player_pos.collected++;
			mlx_put_image_to_window(param->mlx, param->win, param->img_ground, \
					param->player_pos.xpos * 40, param->player_pos.ypos * 40);
			param->player_pos.ypos -= 1;
			mlx_put_image_to_window(param->mlx, param->win, param->img_player_back, \
					param->player_pos.xpos * 40, param->player_pos.ypos * 40);

		}
   }
   printf("steps : %d\n", param->player_pos.steps);	
   printf("collected : %d\n", param->player_pos.collected);	
	return 0; 	 
}

void render_map(t_vars *vars, t_map map_info, char **map_matrix)
{
	int width;
	int height;

	width = 0;
	height = 0;
    vars->map = map_matrix;
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, map_info.o_cols * 40, map_info.o_rows * 40, "lainie JR");
	vars->img_ground = mlx_xpm_file_to_image(vars->mlx, "img/ground.xpm", &width, &height);
    vars->img_tree = mlx_xpm_file_to_image(vars->mlx, "img/tree.xpm", &width, &height);
    vars->img_player_right = mlx_xpm_file_to_image(vars->mlx, "img/link_right.xpm", &width, &height);
    vars->img_player_left = mlx_xpm_file_to_image(vars->mlx, "img/link_left.xpm", &width, &height);
    vars->img_player_back = mlx_xpm_file_to_image(vars->mlx, "img/link_up.xpm", &width, &height);
    vars->img_player_front = mlx_xpm_file_to_image(vars->mlx, "img/link.xpm", &width, &height);
    vars->img_key = mlx_xpm_file_to_image(vars->mlx, "img/key.xpm", &width, &height);
    vars->img_tent = mlx_xpm_file_to_image(vars->mlx, "img/tent.xpm", &width, &height);
	render_map_components(vars, map_info, map_matrix);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop(vars->mlx);
}
int main()
{
	t_vars vars;
	t_map map_info;

	map_info.o_rows = 9;
	map_info.o_cols = 13;
	// vars.player_pos.xpos = 80;
	// vars.player_pos.ypos = 280;
	
	char **map_matrix = allocate_map_matrix(map_info);
	populate_map_data(map_info, map_matrix, "maps/map1.txt");
	check_components(map_matrix, map_info, &vars);
	get_initial_pos(&vars, &map_info, map_matrix);
	render_map(&vars, map_info, map_matrix);
	// for (int i = 0; i < map_info.o_rows; i++)
	// {
	// 	write(1, map_matrix[i], map_info.o_cols);
	// 	write(1, "\n", 1);
	// }
	return 0;
}