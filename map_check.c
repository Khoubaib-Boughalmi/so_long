/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:47:57 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/07 13:30:41 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//check if the map has a valid equal #of cols per row 
int check_valid_cols(t_map *map_info, char *map_name)
{
	int		fd;
	char	buff;
	int		col_count;

	fd = open(map_name, O_RDONLY);
	col_count = -1;
	while (read(fd, &buff, 1))
	{
		col_count++;
		if (buff == '\n')
		{
			if (col_count != map_info->o_cols)
				return	ft_printf_err("MAP COLUMNS HAVE DIFFRENT LENGTHS\n");			
			col_count = -1;
		}
	}
	if (col_count == map_info->o_cols - 1)
		return (1);
	return	ft_printf_err("MAP COLUMNS HAVE DIFFRENT LENGTHS\n");	
}

// verify that the map is rectangular 
int check_is_rectangular(t_map *map_info)
{
	if (map_info->o_rows != map_info->o_cols)
		return (1);
	return	ft_printf_err("MAP IS SQUARE\n");
}
// now that i have checked the validity of the maps cols and rows 
// we can convert the map file into a matrix and work on it
int	check_valid_walls(char **map, t_map *map_info)
{
	int			i;
	int			j;

	i = 0;
	if(!map_info->o_cols)
		return	ft_printf_err("EMPTY MAP\n");

	while (i < map_info->o_rows)
	{
		j = 0;
		while (j < map_info->o_cols)
		{
			if ((i == 0 || j == 0 || i == map_info->o_rows  - 1 || j == map_info->o_cols  - 1 ) \
				 && map[i][j] != '1')
				return	ft_printf_err("MAP IS NOT SURROUNEDED BY WALLS \n");

			j++;
		}
		i++;
	}
	return (1);
}

//check if the map has more than one Player or more than one exit
//check if the map has element diffrent than those specified (0, 1, P, C, E)
//populate the component struct collectable so that it can be used later
int check_components(char **map, t_map *map_info, t_vars *vars)
{
	int			i;
	int			j;
	ft_bzero(&vars->component, sizeof(vars->component));
	i = 0;
	while (i < map_info->o_rows)
	{
		j = 0;
		while (j < map_info->o_cols)
		{
			if(map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'E' \
				&& map[i][j] != '0' && map[i][j] != '1' )
				return ft_printf_err("MAP HAS INVALID COMPONENT");
			if (map[i][j] == 'P')
				vars->component.player++;
			else if (map[i][j] == 'E')
				vars->component.exit++;
			else if (map[i][j] == 'C')
				vars->component.collectable++;
			if (vars->component.player > 1 || vars->component.exit > 1)
				return ft_printf_err("MAP HAS MORE THAT ONE PLAYER || EXIT");
			j++;
		}
		i++;
	}
	if (!vars->component.collectable || !vars->component.player || \
	!vars->component.exit )
		return ft_printf_err("MAP DOESNT HAVE ENOUGH COMPONENTS");
	return (1);
}
