/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_metadata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:20:36 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/10 12:54:28 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// return us the #of rows in map
int	get_num_rows_map(int fd)
{
	int		count;
	char	buff;

	if (fd <= 0 || fd == 1 || fd == 2)
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
int	get_num_cols_map(int fd)
{
	int		count;
	char	buff;

	if (fd <= 0 || fd == 1 || fd == 2)
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

// populate the t_map struct so that we can use it later (#of rows && #of cols)
int	populate_map_metadata(t_map *map_info, char *map_name)
{
	int	fd1;
	int	fd2;

	fd1 = open(map_name, O_RDONLY);
	fd2 = open(map_name, O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
		return (ft_printf_err("MAPE NAME IS INVALID"));
	map_info->o_rows = get_num_rows_map(fd1);
	map_info->o_cols = get_num_cols_map(fd2);
	close(fd1);
	close(fd2);
	return (1);
}
