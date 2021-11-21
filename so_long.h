/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 04:28:18 by ahhammou          #+#    #+#             */
/*   Updated: 2021/11/15 15:19:22 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "./mlx/mlx.h"
# include "get_next_line.h"
# include "./libft/libft.h"

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	int		l;
	int		o;
	int		col;
	int		e;
	int		p;
	char	**arr;
	void	*img;
	void	*img_wall;
	void	*img_exit;
	void	*img_open;
	void	*img_ground;
	void	*img_player;
	void	*img_player_rev;
	void	*img_col;
	void	*img_enemy;
	void	*img_enemy_rev;
	char	*addr;
	char	*moves;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	int		i;
	int		p_x;
	int		p_y;
	int		enemy_x;
	int		enemy_y;
	int		c_counter;
	int		map_col;
	int		map_row;
}		t_data;

int		ft_draw_collect(t_data *flags, int x, int y);
int		ft_draw_exit(t_data *flags, int x, int y);
int		ft_draw_player(t_data *flags, int x, int y);
int		ft_draw_walls(t_data *flags, int x, int y);
int		ft_draw_ground(t_data *flags, int x, int y);
int		ft_check_wall_enemy_food(char c, t_data *flags);
int		ft_checker_flag(char **arr, t_data *flags);
int		ft_checker_len(char **arr);
int		ft_borderland(char **arr, int j);
int		ft_checker_wall(char **arr);
void	ft_key_print(t_data *flags, int keycode, char c);
void	ft_check_next(t_data *flags, int y, int x, int keycode);
void	ft_map_dim(t_data *flags);
int		ft_draw_enemy(t_data *flags, int x, int y);
int		ft_free_img(t_data *flags);
int		flag_checker(t_data *flags, int z);
int		sub_drawer(t_data *flags, int i, int x, int y);
int		ft_draw_exit_open(t_data *flags);
int		ft_draw_open(t_data *flags, int i, int j);
void	ft_ground_player(t_data *flags);
void	ft_ground_key(t_data *flags, int keycode, int x, int y);
void	ft_image_init(t_data *flags);
void	ft_check_next_enemy(t_data *flags);
void	ft_enemy(t_data *flags);
int		ft_draw_player_rev(t_data *flags, int x, int y);
void	ft_champ(t_data *flags, int x, int y);

#endif
