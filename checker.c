/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 04:15:01 by ahhammou          #+#    #+#             */
/*   Updated: 2021/11/15 08:38:23 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_wall_enemy_food(char c, t_data *flags)
{
	if (c == 'C')
		flags->col += 1;
	else if (c == 'E')
		flags->e += 1;
	else if (c == 'P')
		flags->p += 1;
	else if (c == '1')
		flags->l += 1;
	else if (c == '0')
		flags->o += 1;
	else if (c == 'D')
		return (1);
	else if (c != '\n')
		return (0);
	return (1);
}

int	ft_checker_flag(char **arr, t_data *flags)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			x = ft_check_wall_enemy_food(arr[i][j], flags);
			if (x == 0)
				return (0);
			j++;
		}
		i++;
	}
	if (flags->col < 1 || flags->p != 1 || flags->e < 1)
		return (0);
	return (1);
}

int	ft_checker_len(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = ft_strlen(arr[0]);
		if (ft_strlen(arr[i]) != j)
			return (0);
		i++;
	}
	return (10);
}

int	ft_borderland(char **arr, int j)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i][j] != '1')
		{
			if (arr[i][j] != '\n')
				return (0);
		}
		i++;
	}
	i = 0;
	while (arr[i])
	{
		if (arr[i][0] != '1')
		{
			if (arr[i][0] != '\n')
				return (0);
		}
		i++;
	}
	return (1);
}
