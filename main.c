/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:43:35 by ahhammou          #+#    #+#             */
/*   Updated: 2021/11/03 04:27:56 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include <stdio.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

// int	mouse_hook(int button, int x, int y, t_vars *vars)
// {
// 	printf("Hello from key_hook! %d %d %d\n", button, x, y);
// 	return (1);
// }

// int	close(int keycode, t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (1);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 1024, "Hello world!");
// 	mlx_mouse_hook(vars.win, mouse_hook, &vars);
// 	// mlx_hook(vars.win, 6, 1L << 4, close, &vars);
// 	mlx_loop_hook(mlx, render_next_frame, YourStruct);
// 	mlx_loop(vars.mlx);
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	char	*relative_path = "/Users/ahhammou/Cursus/So_Long/sample_640×426.xpm";
// 	int		img_width;
// 	int		img_height;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }
// gcc -I./mlx -g -L./mlx -lmlx -framework OpenGL -framework AppKit main.c
