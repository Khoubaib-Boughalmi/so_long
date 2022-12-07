/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:54:42 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/06 14:37:03 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_printf_err(char * str)
{
	int	i;

	i = -1;
	while (str[++i] != 0)
		write(2, &str[i], 1);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return ;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}