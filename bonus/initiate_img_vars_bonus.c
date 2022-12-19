/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_img_vars_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:21:22 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/18 16:11:33 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initiate_img_vars(t_vars *vars, int *w, int *h)
{
	vars->img.img_ground = mlx_xpm_file_to_image(vars->mlx, \
		"bonus/img/ground.xpm", w, h);
	vars->img.img_tree = mlx_xpm_file_to_image(vars->mlx, \
	"bonus/img/tree.xpm", w, h);
	vars->img.img_key = mlx_xpm_file_to_image(vars->mlx, \
	"bonus/img/key.xpm", w, h);
	vars->img.img_tent = mlx_xpm_file_to_image(vars->mlx, \
	"bonus/img/tent.xpm", w, h);
	vars->img.img_tnt = mlx_xpm_file_to_image(vars->mlx, \
	"bonus/img/ball.xpm", w, h);
	vars->img.img_tnt1 = mlx_xpm_file_to_image(vars->mlx, \
	"bonus/img/ball1.xpm", w, h);
	vars->img.img_tnt2 = mlx_xpm_file_to_image(vars->mlx, \
	"bonus/img/ball2.xpm", w, h);
	vars->img.img_renemy = mlx_xpm_file_to_image(vars->mlx, \
	"bonus/img/renemy.xpm", w, h);
	vars->img.img_lenemy = mlx_xpm_file_to_image(vars->mlx, \
	"bonus/img/lenemy.xpm", w, h);
}
