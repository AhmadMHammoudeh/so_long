/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:31:05 by ahhammou          #+#    #+#             */
/*   Updated: 2021/11/15 09:00:54 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_w16(char *s, int fd)
{
	char	*temp;
	int		size;

	temp = malloc(sizeof(char) * (10 + 1));
	if (!temp)
	{
		free (temp);
		return (NULL);
	}
	size = 1337;
	while (!ft_strchr_new(s, '\n') && size != 0)
	{
		size = read(fd, temp, 10);
		if (size == -1)
		{
			free (temp);
			return (NULL);
		}
		temp[size] = '\0';
		s = ft_strjoin_new(s, temp);
	}
	free (temp);
	return (s);
}

char	*get_next_line(int fd, int z)
{
	char		*d;
	static char	*s;

	d = NULL;
	if (fd < 0)
		return (0);
	s = ft_w16(s, fd);
	if (!s)
		return (NULL);
	d = ft_speedo(s);
	s = ft_future_line(s);
	if (d[0] == '\0')
	{
		z = 1;
		free(s);
		free(d);
		return (NULL);
	}
	return (d);
}

// int main ()
// {
// 	char *s;
// 	int fd;

// 	fd = open("/Users/ahhammou/Desktop/sam/test.txt", OR_ONLY);
// 	s = get_next_line(fd);
// 	printf("%s", "s");
// }
