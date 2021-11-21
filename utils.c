/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 04:22:52 by ahhammou          #+#    #+#             */
/*   Updated: 2021/11/15 15:22:54 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_dim(t_data *flags)
{
	while (flags->arr[flags->map_row])
	{
		while (flags->arr[flags->map_row][flags->map_col] != '\n')
			flags->map_col++;
		flags->map_row++;
	}
}

int	ft_draw_enemy(t_data *flags, int x, int y)
{
	ft_draw_ground(flags, x, y);
	flags->addr = mlx_get_data_addr(flags->img_enemy, &flags->bits_per_pixel, \
		 &flags->line_length, &flags->endian);
	mlx_put_image_to_window(flags->mlx, flags->mlx_win, flags->img_enemy, x, y);
	flags->enemy_x = x ;
	flags->enemy_y = y ;
	return (1);
}

int	flag_checker(t_data *flags, int z)
{
	z = ft_checker_len(flags->arr);
	if (z == 0)
	{
		printf("Error\n Size Of Map Invalid.");
		return (0);
	}
	z = ft_checker_wall(flags->arr);
	if (z == 0)
	{
		printf("Error\nWalls Not Complete.");
		return (0);
	}
	z = ft_checker_flag(flags->arr, flags);
	if (z == 0)
	{
		printf("Error\nExit, Collectable,or Player missing or \
			Invalid Character.\n");
		return (0);
	}
	return (z);
}

int	ft_draw_exit_open(t_data *flags)
{
	int	i;
	int	j;

	i = 0;
	while (flags->arr[i])
	{
		j = 0;
		while (flags->arr[i][j])
		{
			if (flags->arr[i][j] == 'E')
				ft_draw_open(flags, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	sub_drawer(t_data *flags, int i, int x, int y)
{
	int	j;

	j = 0;
	while (flags->arr[i][j] != '\n')
	{
		if (flags->arr[i][j] == '1')
			ft_draw_walls(flags, x, y);
		else if (flags->arr[i][j] == 'E')
			ft_draw_exit(flags, x, y);
		else if (flags->arr[i][j] == 'C')
			ft_draw_collect(flags, x, y);
		else if (flags->arr[i][j] == 'P')
		{
			ft_draw_ground(flags, x, y);
			ft_draw_player(flags, x, y);
		}
		else if (flags->arr[i][j] == '0')
			ft_draw_ground(flags, x, y);
		else if (flags->arr[i][j] == 'D')
			ft_draw_enemy(flags, x, y);
		x += 64;
		j++;
	}
	return (x);
}
