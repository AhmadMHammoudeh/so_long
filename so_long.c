/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 04:28:34 by ahhammou          #+#    #+#             */
/*   Updated: 2021/11/15 15:10:10 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initalize(t_data *flags)
{
	flags->l = 0;
	flags->o = 0;
	flags->col = 0;
	flags->e = 0;
	flags->p = 0;
	flags->x = 0;
	flags->y = 0;
	flags->i = 1;
	flags->p_x = 0;
	flags->p_y = 0;
	flags->enemy_x = 0;
	flags->enemy_y = 0;
	flags->c_counter = 0;
	flags->map_col = 0;
	flags->map_row = 0;
}

void	ft_draw(t_data *flags)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	flags->img = mlx_new_image(flags->mlx, flags->map_row * 64, \
		flags->map_col * 64);
	while (flags->arr[i])
	{
		x = 0;
		x = sub_drawer(flags, i, x, y);
		y += 64;
		i++;
	}
}

int	the_parse(int fd, t_data *flags)
{
	int		i;
	int		z;

	i = 0;
	z = 0;
	ft_initalize(flags);
	flags->arr = malloc(sizeof(char *) * 11);
	while (z == 0)
	{
		flags->arr[i] = get_next_line(fd, z);
		if (!flags->arr[i])
			break ;
		i++;
	}
	z = flag_checker(flags, z);
	if (z == 0)
		exit(1);
	return (1);
}

int	key_hook(int keycode, t_data *flags)
{
	if (flags->c_counter == flags->col)
		ft_draw_exit_open(flags);
	if (keycode == 13)
		ft_check_next(flags, flags->p_x, flags->p_y - 1, keycode);
	else if (keycode == 1)
		ft_check_next(flags, flags->p_x, flags->p_y + 1, keycode);
	else if (keycode == 0)
		ft_check_next(flags, flags->p_x - 1, flags->p_y, keycode);
	else if (keycode == 2)
		ft_check_next(flags, flags->p_x + 1, flags->p_y, keycode);
	if (keycode == 53)
	{
		ft_free_img(flags);
		exit(0);
	}
	return (1);
}

int	main(int argv, char **argc)
{
	t_data	flags;
	int		fd;

	if (argv > 2)
	{
		printf("Inavlid Number of Arguments");
		exit(1);
	}
	if (ft_strncmp(ft_strrchr(argc[1], '.'), ".ber", 4) != 0)
		return (printf("Error\nWrong File Extension."));
	fd = open(argc[1], O_RDONLY);
	if (!fd)
		return (printf("Error\nWrong File Name."));
	the_parse(fd, &flags);
	flags.mlx = mlx_init();
	ft_map_dim(&flags);
	flags.mlx_win = mlx_new_window(flags.mlx, flags.map_col * 64, \
		flags.map_row * 64, "SUMMONER'S HELL!!!!");
	ft_image_init(&flags);
	ft_draw(&flags);
	mlx_key_hook(flags.mlx_win, key_hook, &flags);
	mlx_hook(flags.mlx_win, 17, 1L << 2, ft_free_img, &flags);
	mlx_loop(flags.mlx);
}
