/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 08:27:48 by ahhammou          #+#    #+#             */
/*   Updated: 2021/11/15 15:18:06 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	ft_draw_open(t_data *flags, int i, int j)
{
	ft_draw_ground(flags, i * 64, j * 64);
	flags->addr = mlx_get_data_addr(flags->img_open, &flags->bits_per_pixel, \
		&flags->line_length, &flags->endian);
	mlx_put_image_to_window(flags->mlx, flags->mlx_win, flags->img_open, \
		i * 64, j * 64);
	return (1);
}

int	chicking(char **arr, int i, int j)
{
	while (arr[i])
	{
		j = 0;
		while (i == 0)
		{
			if (arr[i][j] != '1')
			{
				if (arr[i][j] == '\n')
					break ;
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_checker_wall(char **arr)
{
	int	i;
	int	j;

	i = 0;
	i = chicking(arr, i, j);
	if (i == 0)
		return (0);
	j = 0;
	i--;
	while (arr[i][j])
	{
		if (arr[i][j] != '1')
		{
			if (arr[i][j] == '\n')
				break ;
			else
				return (0);
		}
		j++;
	}
	j = ft_borderland(arr, j - 1);
	if (!j)
		return (0);
	return (j);
}

void	ft_ground_player(t_data *flags)
{
	ft_enemy(flags);
	ft_draw_ground(flags, flags->x, flags->y);
	ft_champ(flags, flags->x, flags->y);
}

void	ft_ground_key(t_data *flags, int keycode, int x, int y)
{
	ft_draw_ground(flags, flags->x, flags->y);
	ft_key_print(flags, keycode, flags->arr[x][y]);
}
