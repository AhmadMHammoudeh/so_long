/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 04:15:59 by ahhammou          #+#    #+#             */
/*   Updated: 2021/11/15 12:50:49 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_draw_ground(t_data *flags, int x, int y)
{
	flags->addr = mlx_get_data_addr(flags->img_ground, &flags->bits_per_pixel, \
		&flags->line_length, &flags->endian);
	mlx_put_image_to_window(flags->mlx, flags->mlx_win, \
		flags->img_ground, x, y);
	return (1);
}

int	ft_draw_walls(t_data *flags, int x, int y)
{
	flags->addr = mlx_get_data_addr(flags->img_wall, &flags->bits_per_pixel, \
		&flags->line_length, &flags->endian);
	mlx_put_image_to_window(flags->mlx, flags->mlx_win, flags->img_wall, x, y);
	return (1);
}

int	ft_draw_player(t_data *flags, int x, int y)
{
	flags->addr = mlx_get_data_addr(flags->img_player, &flags->bits_per_pixel, \
		&flags->line_length, &flags->endian);
	mlx_put_image_to_window(flags->mlx, flags->mlx_win, \
		flags->img_player, x, y);
	flags->x = x;
	flags->y = y;
	flags->p_x = x / 64;
	flags->p_y = y / 64;
	return (1);
}

int	ft_draw_exit(t_data *flags, int x, int y)
{
	ft_draw_ground(flags, x, y);
	flags->addr = mlx_get_data_addr(flags->img_exit, &flags->bits_per_pixel, \
		&flags->line_length, &flags->endian);
	mlx_put_image_to_window(flags->mlx, flags->mlx_win, flags->img_exit, x, y);
	return (1);
}

int	ft_draw_collect(t_data *flags, int x, int y)
{
	ft_draw_ground(flags, x, y);
	flags->addr = mlx_get_data_addr(flags->img_col, &flags->bits_per_pixel, \
		&flags->line_length, &flags->endian);
	mlx_put_image_to_window(flags->mlx, flags->mlx_win, flags->img_col, \
		x + 15, y + 15);
	return (1);
}
