/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:11:05 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/12 10:54:33 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path_core(char **map, t_map *info, int i, int j)
{
	char		c;
	static int	count = 0;

	c = 'X';
	if (map[i][j] == 'C')
		count += 1;
	map[i][j] = c;
	if ((map[i + 1][j] == '0' || map[i + 1][j] == 'C' || map[i + 1][j] == 'E'\
		|| map[i + 1][j] == 'P') && (i < info->o_rows - 1))
		check_path_core(map, info, i + 1, j);
	if ((map[i - 1][j] == '0' || map[i - 1][j] == 'C' || map[i - 1][j] == 'E'\
		|| map[i - 1][j] == 'P') && (i >= 0))
		check_path_core(map, info, i - 1, j);
	if ((map[i][j + 1] == '0' || map[i][j + 1] == 'C' || map[i][j + 1] == 'E'\
		|| map[i][j + 1] == 'P') && (j < info->o_cols - 1))
		check_path_core(map, info, i, j + 1);
	if ((map[i][j - 1] == '0' || map[i][j - 1] == 'C' || map[i][j - 1] == 'E'\
		|| map[i][j - 1] == 'P') && (j >= 0))
		check_path_core(map, info, i, j - 1);
	return (count);
}

int	check_path(t_vars *vars, t_map *map_info, char *map_name)
{
	char	**map;
	int		count;

	map = allocate_map_matrix(map_info);
	populate_map_data(map_info, map, map_name);
	count = check_path_core(map, map_info, vars->player_pos.ypos, \
		vars->player_pos.xpos);
	if (count != vars->component.collectable)
		return (ft_printf_err("MAP IS INVALID NO VALID PATH"));
	free_map_matrix(map, map_info->o_rows - 1);
	return (1);
}
