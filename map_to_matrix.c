/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:39:06 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/04 16:28:08 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_map{
	int o_cols;
	int o_rows;
}	t_map;

int populate_map_metadata(t_map *map_info)
{
	int	fd1;
	int	fd2;

	fd1 = open("maps/map1.txt", O_RDONLY);
	fd2 = open("maps/map1.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
		return 0;
	map_info->o_rows = get_num_cols_map(fd1);
	map_info->o_cols = get_num_rows_map(fd2);
	close(fd1);
	close(fd2);
	return (1);
}

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

int main()
{
	// define t_map struct
	t_map map_info;

	populate_map_metadata(&map_info);
	printf("%d", )
	return 0;
}