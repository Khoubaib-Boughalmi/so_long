/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:42:02 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/19 15:19:40 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	safe_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img.img_ground);
	mlx_destroy_image(vars->mlx, vars->img.img_key);
	mlx_destroy_image(vars->mlx, vars->img.img_tent);
	mlx_destroy_image(vars->mlx, vars->img.img_tree);
	mlx_destroy_image(vars->mlx, vars->img.img_tnt);
	mlx_destroy_image(vars->mlx, vars->img.img_tnt1);
	mlx_destroy_image(vars->mlx, vars->img.img_tnt2);
	mlx_destroy_image(vars->mlx, vars->img.img_renemy);
	mlx_destroy_image(vars->mlx, vars->img.img_lenemy);
	free_map_matrix(vars->map, vars->map_info.o_rows - 1);
	free(vars->mlx);
	ft_printf("\nGAME ENDED\n");
	exit(EXIT_SUCCESS);
	return (0);
}
