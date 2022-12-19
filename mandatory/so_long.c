/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:23:36 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/19 13:36:38 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(char **map, t_map map_info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_map	map_info;
	char	**map;
	char	*map_name;

	(void)argc;
	map_name = ft_strjoin("mandatory/maps/", argv[1]);
	if (!populate_map_metadata(&map_info, map_name))
		return (0);
	if (!check_valid_cols(&map_info, map_name))
		return (0);
	if (!check_is_rectangular(&map_info))
		return (0);
	map = allocate_map_matrix(&map_info);
	populate_map_data(&map_info, map, map_name);
	if (!check_valid_walls(map, &map_info))
		return (0);
	if (!check_components(map, &map_info, &vars))
		return (0);
	get_initial_pos(&vars, &map_info, map);
	if (!check_path(&vars, &map_info, map_name))
		return (0);
	render_map(&vars, &map_info, map);
	return (0);
}
