/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:23:36 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/09 17:57:40 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(void)
{
}

void display_map(char **map, t_map map_info)
{
	int i = 0;
	int j = 0;
	while (i < map_info.o_rows)
	{
		j = 0;
		while (j < map_info.o_cols)
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int	main(void)
{
	t_vars	vars;
	t_map	map_info;
	char	**map;

	populate_map_metadata(&map_info, "maps/map1.txt");
	if (!check_valid_cols(&map_info, "maps/map1.txt"))
		return (0);
	if (!check_is_rectangular(&map_info))
		return (0);
	map = allocate_map_matrix(&map_info);
	populate_map_data(&map_info, map, "maps/map1.txt");
	if (!check_valid_walls(map, &map_info))
		return (0);
	if (!check_components(map, &map_info, &vars))
		return (0);
	get_initial_pos(&vars, &map_info, map);
	////////////////////////////////////
	t_cord cord;
	cord.i = 1;
	cord.j = 1;
	int count = 0;
	display_map(map, map_info);
	ft_printf("\n");
	count = check_path(&map_info,"maps/map1.txt");
	ft_printf("col : %d\n", vars.component.collectable);
	if(count != vars.component.collectable)
		return ft_printf_err("MAP IS INVALID NO VALID PATH");
	////////////////////////////////////
	render_map(&vars, &map_info, map);
	return (0);
}
