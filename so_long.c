/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboughal <kboughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:55:33 by kboughal          #+#    #+#             */
/*   Updated: 2022/12/04 16:19:17 by kboughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img_ground;
	void	*img_tree;
	void	*img_player_right;
	void	*img_player_left;
	void	*img_player_back;
	void	*img_player_front;
	void	*img_key;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * data->bits_per_pixel / 8);
	*(unsigned int*)dst = color;
}

void draw_square(t_data *img, int color)
{
	int c = 250;
	int i = c - 100;
	int j = c - 100;
	while (i < c + 100)
	{
		j = c - 100;
		while (j < c + 100)
		{
			my_mlx_pixel_put(img, i, j, color);
			j++;
		}
		i++;
	}
}

void draw_circle(t_data *img, int color, int radius)
{
	int c = 250;
	int i = c - 200;
	int j = c - 200;
	int x0 = 250;
	int y0 = 250;
	while (i < c + 200)
	{
 		j = c - 200;
		while (j < c + 200)
		{
			if ((i-x0)*(i-x0) + (j-y0)*(j-y0) < radius)
			{
				my_mlx_pixel_put(img, i, j, color);
			}			
			j++;
		}
		i++;
	}
}

int key_hook(int button, t_vars *param)
{
    // Whenever the event is triggered, print the value of button to console.
	static int xpos = 80;
	static int ypos = 120;
	
   if (button == 2) // D
   {
	   	mlx_put_image_to_window(param->mlx, param->win, param->img_ground, xpos, ypos);
		xpos += 40;
	   	mlx_put_image_to_window(param->mlx, param->win, param->img_player_right, xpos, ypos);
   }
   else if (button == 0) // A
   {
	   	mlx_put_image_to_window(param->mlx, param->win, param->img_ground, xpos, ypos);
		xpos -= 40;
	   	mlx_put_image_to_window(param->mlx, param->win, param->img_player_left, xpos, ypos);
   }
   else if (button == 1) // S
   {
	   	mlx_put_image_to_window(param->mlx, param->win, param->img_ground, xpos, ypos);
		ypos += 40;
	   	mlx_put_image_to_window(param->mlx, param->win, param->img_player_front, xpos, ypos);
   }
   else if (button == 13) // W
   {
	   	mlx_put_image_to_window(param->mlx, param->win, param->img_ground, xpos, ypos);
		ypos -= 40;
	   	mlx_put_image_to_window(param->mlx, param->win, param->img_player_back, xpos, ypos);
   }
   
	
	return 0; 	 
}

int	main(void)
{
	t_vars vars;
	int width;
	int height;

	width = 0;
	height = 0;
	// Create a new window with the specified width and height
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 800, 800, "lainie JR");
	
    // Load the image file and get a pointer to the image data
    void *img_ground = mlx_xpm_file_to_image(mlx, "img/ground.xpm", &width, &height);
    void *img_tree = mlx_xpm_file_to_image(mlx, "img/tree.xpm", &width, &height);
    void *img_player_right = mlx_xpm_file_to_image(mlx, "img/link_right.xpm", &width, &height);
    void *img_player_left = mlx_xpm_file_to_image(mlx, "img/link_left.xpm", &width, &height);
    void *img_player_back = mlx_xpm_file_to_image(mlx, "img/link_up.xpm", &width, &height);
    void *img_player_front = mlx_xpm_file_to_image(mlx, "img/link.xpm", &width, &height);
    void *img_key = mlx_xpm_file_to_image(mlx, "img/key.xpm", &width, &height);
	vars.mlx = mlx;
	vars.win = win;
	vars.img_ground = img_ground;
	vars.img_tree = img_tree;
	vars.img_player_right = img_player_right;
	vars.img_player_left = img_player_left;
	vars.img_player_back = img_player_back;
	vars.img_player_front = img_player_front;
	vars.img_key = img_key;
	int i = 0;
	int j = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			if (i == 0 || i == 19 || j == 0 || j == 19)
    			mlx_put_image_to_window(mlx, win, img_tree, 40 * i, 40 * j);			
    		else
				mlx_put_image_to_window(mlx, win, img_ground, 40 * i, 40 * j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, win, img_player_right, 80, 120);
	mlx_put_image_to_window(mlx, win, img_key, 80, 200);
	mlx_put_image_to_window(mlx, win, img_key, 280, 120);
	mlx_put_image_to_window(mlx, win, img_key, 400, 320);
	mlx_put_image_to_window(mlx, win, img_key, 320, 40);
	mlx_put_image_to_window(mlx, win, img_key, 680, 640);
	mlx_key_hook(win, key_hook, &vars);
    // Start the event loop and display the window
    mlx_loop(mlx);

    return 0;
}