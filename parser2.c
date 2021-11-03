/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 04:28:34 by ahhammou          #+#    #+#             */
/*   Updated: 2021/11/03 09:45:50 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.c"

int ft_checker_len(char **arr)
{
	int i;
	int j;

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

int ft_borderland(char **arr, int j)
{
	int i;

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

int ft_checker_wall(char **arr)
{
	int i;
	int j;
	int p;

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
					break;
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
				break;
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
	char **arr;
	int i;
	int z;

	i = 0;
	z = 0;
	arr = malloc(sizeof(char *)*11);
	while (z == 0)
	{
		arr[i] = get_next_line(fd, z);
		if (!arr[i])
			break;
		i++;
	}
	z = ft_checker_len(arr);
	if (z == 0)
		return (0);
	z = ft_checker_wall(arr);
	if (z == 0)
		return (0);
	return (1);
}

int main ()
{
	int fd;

	fd = open("/Users/ahhammou/Cursus/So_Long/test.ber", O_RDONLY);
	printf("%d", the_parse(fd));
}
