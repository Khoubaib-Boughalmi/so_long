/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:11:05 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/09 17:53:08 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int check_path_core(char **map, t_map *info,int i, int j, char c, int *count)
{
	//make a copy of the original map and work on it
	if(map[i][j] == 'C')
		*count += 1;
	map[i][j] = c;
	if ((map[i + 1][j] == '0' || map[i + 1][j] == 'C' || map[i + 1][j] == 'E' || map[i + 1][j] == 'P') && (i < info->o_rows - 1))
		check_path_core(map, info, i + 1, j, c, count);
	if ((map[i - 1][j] == '0' || map[i - 1][j] == 'C' || map[i - 1][j] == 'E' || map[i - 1][j] == 'P') && (i >= 0))
		check_path_core(map, info, i - 1, j, c, count);
	if ((map[i][j + 1] == '0' || map[i][j + 1] == 'C' || map[i][j + 1] == 'E' || map[i][j + 1] == 'P') && (j < info->o_cols - 1))
		check_path_core(map, info, i, j + 1, c, count);
	if ((map[i][j - 1] == '0' || map[i][j - 1] == 'C' || map[i][j - 1] == 'E' || map[i][j - 1] == 'P') && (j >= 0))
		check_path_core(map, info, i, j - 1, c, count);
	return(*count);
}

int check_path(t_map *map_info, char *map_name)
{
	char	**map;
	int		count;
	
	count = 0;
	map = allocate_map_matrix(map_info);
	populate_map_data(map_info, map, "maps/map1.txt");
	check_path_core(map, map_info, 1, 1, '2', &count);
	return (count);
}