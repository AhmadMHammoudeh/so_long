/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 04:11:26 by ahhammou          #+#    #+#             */
/*   Updated: 2021/11/15 15:36:55 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_img(t_data *flags)
{
	mlx_destroy_window(flags->mlx, flags->mlx_win);
	free(flags->arr);
	free(flags->img);
	free(flags->img_wall);
	free(flags->img_col);
	free(flags->img_exit);
	free(flags->img_open);
	free(flags->img_ground);
	free(flags->img_player);
	free(flags->img_enemy);
	free(flags->img_player_rev);
	free(flags->addr);
	exit(0);
}

int	ft_draw_player_rev(t_data *flags, int x, int y)
{
	flags->addr = mlx_get_data_addr(flags->img_player_rev, \
		&flags->bits_per_pixel, &flags->line_length, &flags->endian);
	mlx_put_image_to_window(flags->mlx, flags->mlx_win, flags->img_player_rev \
		, x, y);
	flags->x = x;
	flags->y = y;
	flags->p_x = x / 64;
	flags->p_y = y / 64;
	return (1);
}

void	ft_key_print(t_data *flags, int keycode, char c)
{
	if (keycode == 13)
	{
		flags->y -= 64;
		ft_ground_player(flags);
	}
	if (keycode == 1)
	{
		flags->y += 64;
		ft_ground_player(flags);
	}
	if (keycode == 0)
	{
		flags->x -= 64;
		ft_draw_ground(flags, flags->x, flags->y);
		ft_enemy(flags);
		ft_champ(flags, flags->x, flags->y);
	}
	if (keycode == 2)
	{
		flags->x += 64;
		ft_ground_player(flags);
	}
	if (c == 'C')
		flags->c_counter++;
}

void	ft_print_move(t_data *flags)
{
	char	*collectables;
	char	*collected;

	flags->moves = ft_itoa(flags->i);
	collectables = ft_itoa(flags->col);
	collected = ft_itoa(flags->c_counter);
	ft_draw_walls(flags, flags->map_col / 2 * 64, 0);
	ft_draw_walls(flags, flags->map_col / 2 * 64 - 64, 0);
	ft_draw_walls(flags, flags->map_col / 2 * 64 + 64, 0);
	ft_draw_walls(flags, flags->map_col / 2 * 64 + 128, 0);
	ft_draw_walls(flags, flags->map_col / 2 * 64 - 128, 0);
	mlx_string_put(flags->mlx, flags->mlx_win, flags->map_col / 2 * 64 + 20, \
		15, 808080, flags->moves);
	mlx_string_put(flags->mlx, flags->mlx_win, flags->map_col / 2 * 64 - 32, \
		15, 808080, "MOVES");
	mlx_string_put(flags->mlx, flags->mlx_win, flags->map_col / 2 * 64 + 92, \
		40, 808080, collectables);
	mlx_string_put(flags->mlx, flags->mlx_win, flags->map_col / 2 * 64 - 80, \
		40, 808080, "Collected Out Of");
	mlx_string_put(flags->mlx, flags->mlx_win, flags->map_col / 2 * 64 - 94, \
		40, 808080, collected);
	printf("Number of Moves %d\n", flags->i++);
}

void	ft_check_next(t_data *flags, int y, int x, int keycode)
{
	if (flags->arr[x][y] == 'D')
		ft_free_img(flags);
	else if (flags->arr[x][y] == 'C')
	{
		ft_ground_key(flags, keycode, x, y);
		flags->arr[x][y] = '0';
		ft_print_move(flags);
	}
	else if (flags->arr[x][y] == 'E')
	{
		if (flags->c_counter == flags->col)
			ft_free_img(flags);
	}
	else if (flags->arr[x][y] == '0')
	{
		ft_ground_key(flags, keycode, x, y);
		ft_print_move(flags);
		flags->arr[x][y] = 'P';
	}
	else if (flags->arr[x][y] == 'P')
	{
		ft_ground_key(flags, keycode, x, y);
		ft_print_move(flags);
	}
}
