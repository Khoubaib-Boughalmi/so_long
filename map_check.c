/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:47:57 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/06 15:45:01 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// populate the t_map struct so that we can use it later (#of rows && #of cols)
int populate_map_metadata(t_map *map_info, char *map_name)
{
	int	fd1;
	int	fd2;

	fd1 = open(map_name, O_RDONLY);
	fd2 = open(map_name, O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
		return 0;
	map_info->o_rows = get_num_rows_map(fd1);
	map_info->o_cols = get_num_cols_map(fd2);
	close(fd1);
	close(fd2);
	return (1);
}
// return us the #of rows in map
int get_num_rows_map(int fd)
{
	int count;
	char buff;
	if(fd <= 0 || fd == 1 || fd == 2)
		return (0);
	count = 0;
	while (read(fd, &buff, 1))
	{
		if (buff == '\n')
			count++;		
	}
	if (!count)
		return (0);
	count++;
	return (count);
}

// return us the #of cols in map
int get_num_cols_map(int fd)
{
	int count;
	char buff;

	if(fd <= 0 || fd == 1 || fd == 2)
		return (0);
	count = 0;
	while (read(fd, &buff, 1))
	{
		if (buff == '\n')
			return (count);
		count++;		
	}
	return (count);
}

//check if the map has a valid equal #of cols per row 
int check_valid_cols(int o_cols, char *map_name)
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
			if (col_count != o_cols)
				return (0);
			col_count = -1;
		}
	}
	if (col_count == o_cols - 1)
		return (1);
	return (0);
}

// verify that the map is rectangular 
int check_is_rectangular(t_map map_info)
{
	if (map_info.o_rows != map_info.o_cols)
		return (1);
	return (0);
}
// now that i have checked the validity of the maps cols and rows 
// we can convert the map file into a matrix and work on it
int	check_valid_walls(char **map, t_map map_info)
{
	int			i;
	int			j;

	i = 0;
	while (i < map_info.o_rows)
	{
		j = 0;
		while (j < map_info.o_cols)
		{
			if ((i == 0 || j == 0 || i == map_info.o_rows  - 1 || j == map_info.o_cols  - 1 ) \
					 && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//check if the map has more than one Player or more than one exit
//check if the map has element diffrent than those specified (0, 1, P, C, E)
//populate the component struct collectable so that it can be used later
int check_components(char **map, t_map map_info, t_vars *vars)
{
	int			i;
	int			j;

	ft_bzero(&vars->component, sizeof(vars->component));
	i = 0;
	while (i < map_info.o_rows)
	{
		j = 0;
		while (j < map_info.o_cols)
		{
			if(map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'E' \
				&& map[i][j] != '0' && map[i][j] != '1' )
				return (0);
			if (map[i][j] == 'P')
				vars->component.player++;
			else if (map[i][j] == 'E')
				vars->component.exit++;
			else if (map[i][j] == 'C')
				vars->component.collectable++;
			if (vars->component.player > 1 || vars->component.exit > 1)
				return (0);
			j++;
		}
		i++;
	}
	if (!vars->component.collectable)
		return (0);
	return (1);
}

// int main()
// {
// 	t_map map_info;
// 	populate_map_metadata(&map_info, "maps/map1.txt");
// 	if (!map_info.o_cols || !map_info.o_rows || !check_is_rectangular(map_info) \
// 		|| !check_valid_cols(map_info.o_cols, "maps/map1.txt")) // add check_valid_walls() check_components() to this function
// 	{
// 		ft_printf_err("ERROR WITH THE MAP.. PLEASE ENTER A VALILD MAP\n");
// 		return (0);
// 	}
// 	printf("THE MAP IS VALID");
// 	return 0;
// }