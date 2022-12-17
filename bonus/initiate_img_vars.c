/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_img_vars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:21:22 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/17 15:21:31 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initiate_img_vars(t_vars *vars, int *w, int *h)
{
	vars->img.img_ground = mlx_xpm_file_to_image(vars->mlx, \
		"img/ground.xpm", w, h);
	vars->img.img_tree = mlx_xpm_file_to_image(vars->mlx, \
	"img/tree.xpm", w, h);
	vars->img.img_key = mlx_xpm_file_to_image(vars->mlx, \
	"img/key.xpm", w, h);
	vars->img.img_tent = mlx_xpm_file_to_image(vars->mlx, \
	"img/tent.xpm", w, h);
	vars->img.img_tnt = mlx_xpm_file_to_image(vars->mlx, \
	"img/ball.xpm", w, h);
	vars->img.img_tnt1 = mlx_xpm_file_to_image(vars->mlx, \
	"img/ball1.xpm", w, h);
	vars->img.img_tnt2 = mlx_xpm_file_to_image(vars->mlx, \
	"img/ball2.xpm", w, h);
	vars->img.img_renemy = mlx_xpm_file_to_image(vars->mlx, \
	"img/renemy.xpm", w, h);
	vars->img.img_lenemy = mlx_xpm_file_to_image(vars->mlx, \
	"img/lenemy.xpm", w, h);
}
