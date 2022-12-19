/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:51:00 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/19 15:11:21 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_file_name(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 3)
		return (0);
	close(fd);
	return (1);
}
