/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:55:55 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/04 16:57:53 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
#include <fcntl.h>
////////////// to remove ///////////////
#include <stdio.h>
////////////// to remove ///////////////

# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"


//map_to_matrix file
int get_num_rows_map(int fd);
int get_num_cols_map(int fd);

//utils.c
void ft_printf_err(char * str);

#endif