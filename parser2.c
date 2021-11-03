/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 04:28:34 by ahhammou          #+#    #+#             */
/*   Updated: 2021/11/03 13:02:54 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "get_next_line.c"

typedef struct s_data {
	int	l;
	int	o;
	int	col;
	int	e;
	int	p;
	char **arr;
} t_data;

void	ft_initalize(t_data *flags)
{
	flags->l = 0;
	flags->o = 0;
	flags->col = 0;
	flags->e = 0;
	flags->p = 0;
}

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
	else if(c != '\n')
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
			if (x != 1)
				return (0);
			j++;
		}
		i++;
	}
	if (flags->col < 1 || flags->p < 1 || flags->e < 1)
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

int	ft_checker_wall(char **arr)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
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
	p = ft_borderland(arr, j - 1);
	if (!p)
		return (0);
	return (j);
}

int	the_parse(int fd)
{
	int		i;
	int		z;
	t_data	flags;

	i = 0;
	z = 0;
	ft_initalize(&flags);
	flags.arr = malloc(sizeof(char *) * 11);
	while (z == 0)
	{
		flags.arr[i] = get_next_line(fd, z);
		if (!flags.arr[i])
			break ;
		i++;
	}
	z = ft_checker_len(flags.arr);
	if (z == 0)
	{
		strerror(errno);
		// perror("Error\n");
		return (0);
	}
	z = ft_checker_wall(flags.arr);
	if (z == 0)
	{
		strerror(errno);
		// perror("Error\n");
		return (0);
	}
	z = ft_checker_flag(flags.arr, &flags);
	if (z == 0)
	{
		strerror(2);
		perror("Error\n");
		return (0);
	}
	return (1);
}

int main ()
{
	int fd;

	fd = open("test.ber", O_RDONLY);
	the_parse(fd);
}
