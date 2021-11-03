/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 04:28:34 by ahhammou          #+#    #+#             */
/*   Updated: 2021/11/03 05:37:29 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int ft_deminsions(int fd, int z)
{
	int	i;
	int	j;
	int	x;
	int	y;
	char	*temp;
	int		size;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	temp = malloc(sizeof(char));
	size = read(fd, temp, 1);
	while (x == 0 && size > 0)
	{
		if (*temp == '\n')
			x = i;
		size = read(fd, temp, 1);
		i++;
	}
	y++;
	while (size > 0 && y != z)
	{
		i = 0;
		while (*temp != '\n' && size)
		{
			size = read(fd, temp, 1);
			i++;
		}
		if (*temp == '\n')
		{
			if (i != x)
				return (0);
		}
		size = read(fd, temp, 1);
		y++;
	}
	while (size > 0)
	{
		i = 0;
		while (*temp == '1' && size)
		{
			size = read(fd, temp, 1);
			i++;
		}
		if (i != x)
			return (0);
		else
			return (1);
	}
	return (1);
}

int	ft_check_wall_enemy_food(fd)
{
	int		i;
	char	*temp;
	int		size;

	temp = malloc(sizeof(char));
	size = read(fd, temp, 1);
	if (temp[0] == '0')
		return (1);
	if (temp[0] == '1')
		return (2);
	if (temp[0] == 'C')
		return (3);
	if (temp[0] == 'E')
		return (4);
	if (temp[0] == 'P')
		return (5);
	if (temp[0] == '\n')
		return (6);
	if (size == 0)
		return (7);
	return (0);
}

int	parsing(int fd)
{
	int i;
	int j;
	int x;
	int arr;
	int temp;

	i = 0;
	j = 0;
	temp = 0;
	while (arr)
	{
		arr = ft_check_wall_enemy_food(fd);
		if (!arr)
			return (0);
		if (arr == 6)
		{
			j++;
			if (temp != 2)
				return (0);
		}
		if (arr == 7)
		{
			if (temp == 6)
				break ;
			else
				return (0);
				
		}
		temp = arr;
		i++;
	}
	close(fd);
	open(fd, O_RDONLY);
	x = ft_deminsions(fd, j);
	return (x);
}

int main ()
{
	int fd;

	fd = open("/Users/ahhammou/Cursus/So_Long/test.ber", O_RDONLY);
	printf("%d", parsing(fd));
}
