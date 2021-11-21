/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subdrawer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:41:57 by ahhammou          #+#    #+#             */
/*   Updated: 2021/11/15 15:36:18 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_last_init(t_data *flags)
{
	flags->relative_path = "./AnyConv.com__3_atk_5 (1).xpm";
	flags->img_enemy_rev = mlx_xpm_file_to_image(flags->mlx, \
		flags->relative_path, &flags->img_width, &flags->img_height);
}

void	ft_image_init(t_data *flags)
{
	flags->relative_path = "./AnyConv.com__char flip-3.xpm";
	flags->img_player_rev = mlx_xpm_file_to_image(flags->mlx, \
		flags->relative_path, &flags->img_width, &flags->img_height);
	flags->relative_path = "./AnyConv.com__3_atk_5.xpm";
	flags->img_enemy = mlx_xpm_file_to_image(flags->mlx, flags->relative_path, \
		 &flags->img_width, &flags->img_height);
	flags->relative_path = "./AnyConv.com__Door3_pipo (1).xpm";
	flags->img_open = mlx_xpm_file_to_image(flags->mlx, \
		flags->relative_path, &flags->img_width, &flags->img_height);
	flags->relative_path = "./AnyConv.com__[A]Dirt1_pipo.xpm";
	flags->img_ground = mlx_xpm_file_to_image(flags->mlx, flags->relative_path, \
		&flags->img_width, &flags->img_height);
	flags->relative_path = "./AnyConv.com__[A]Flower_pipo.xpm";
	flags->img_wall = mlx_xpm_file_to_image(flags->mlx, flags->relative_path, \
		&flags->img_width, &flags->img_height);
	flags->relative_path = "./AnyConv.com__char1.xpm";
	flags->img_player = mlx_xpm_file_to_image(flags->mlx, flags->relative_path, \
		&flags->img_width, &flags->img_height);
	flags->relative_path = "./AnyConv.com__Door3_pipo.xpm";
	flags->img_exit = mlx_xpm_file_to_image(flags->mlx, flags->relative_path, \
		&flags->img_width, &flags->img_height);
	flags->relative_path = "./AnyConv.com__ItemsInsectA-2.xpm";
	flags->img_col = mlx_xpm_file_to_image(flags->mlx, flags->relative_path, \
		&flags->img_width, &flags->img_height);
	ft_last_init(flags);
}

int	ft_draw_enemy_rev(t_data *flags, int x, int y)
{
	ft_draw_ground(flags, x, y);
	flags->addr = mlx_get_data_addr(flags->img_enemy_rev, \
		&flags->bits_per_pixel, &flags->line_length, &flags->endian);
	mlx_put_image_to_window(flags->mlx, flags->mlx_win, \
		flags->img_enemy_rev, x, y);
	flags->enemy_x = x ;
	flags->enemy_y = y ;
	return (1);
}

void	ft_enemy(t_data *flags)
{
	if (flags->i % 2 == 0)
	{
		ft_draw_ground(flags, flags->x, flags->y);
		ft_draw_enemy(flags, flags->enemy_x, flags->enemy_y);
	}
	if (flags->i % 2 == 1)
	{
		ft_draw_ground(flags, flags->x, flags->y);
		ft_draw_enemy_rev(flags, flags->enemy_x, flags->enemy_y);
	}
}

void	ft_champ(t_data *flags, int x, int y)
{
	if (flags->i % 2 == 0)
	{
		ft_draw_player(flags, flags->x, flags->y);
	}
	else if (flags->i % 2 == 1)
	{
		ft_draw_player_rev(flags, flags->x, flags->y);
	}
}
