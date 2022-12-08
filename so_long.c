/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:23:36 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/08 16:33:28 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(void)
{
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
	// if(!check_path(&map_info, map))
	// 	return(0);
	get_initial_pos(&vars, &map_info, map);
	render_map(&vars, &map_info, map);
	return (0);
}
