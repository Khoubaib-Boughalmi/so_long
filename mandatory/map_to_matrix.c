/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:39:06 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/07 13:27:22 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**free_map_matrix(char **map_matrix, int pos)
{
	int	i;

	i = 0;
	while (i <= pos)
	{
		free(map_matrix[i]);
		i++;
	}
	free(map_matrix);
	return (0);
}

// Allocate a matrix of size rows X cols
char	**allocate_map_matrix(t_map *map_info)
{
	char	**map_matrix;
	int		i;

	i = 0;
	map_matrix = (char **)malloc(map_info->o_rows * sizeof(char *));
	if (!map_matrix)
		return (free_map_matrix(map_matrix, -1));
	while (i < map_info->o_rows)
	{
		map_matrix[i] = (char *)malloc(map_info->o_cols * sizeof(char));
		if (!map_matrix[i])
			return (free_map_matrix(map_matrix, i));
		i++;
	}
	return (map_matrix);
}

//Fill the map matrix with data from the map file
void	populate_map_data(t_map *map_info, char **map_matrix, char *map_name)
{
	char	c;
	int		fd;
	int		i;

	i = 0;
	fd = open(map_name, O_RDONLY);
	while (i < map_info->o_rows)
	{
		read(fd, map_matrix[i], map_info->o_cols);
		read(fd, &c, 1);
		i++;
	}
	close(fd);
}
