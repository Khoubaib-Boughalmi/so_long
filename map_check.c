/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:47:57 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/04 16:58:36 by kboughal         ###   ########.fr       */
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
	map_info->o_rows = get_num_rows_map(fd1);
	map_info->o_cols = get_num_cols_map(fd2);
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

int check_valid_cols(int o_cols)
{
	int		fd;
	char	buff;
	int		col_count;

	fd = open("maps/map1.txt", O_RDONLY);
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


int main()
{
	t_map map_info;
	populate_map_metadata(&map_info);
	if (!map_info.o_cols || !map_info.o_rows)
	{
		ft_printf_err("ERROR WITH THE MAP.. PLEASE ENTER A VALILD MAP\n");
		return (0);
	}
	printf("%d", check_valid_cols(map_info.o_cols));
	return 0;
}