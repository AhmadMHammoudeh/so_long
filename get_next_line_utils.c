/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:31:05 by ahhammou          #+#    #+#             */
/*   Updated: 2021/10/29 19:16:15 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(char *src, int c)
{
	int	i;

	i = 0;
	if (src == NULL)
		return (0);
	while (src[i] != '\0')
	{
		if (src[i] == (char)c)
			return ((char *)&src[i]);
		i++;
	}
	if (c == '\0')
		return (&src[i]);
	return (0);
}

char	*ft_speedo(char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		if (s[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_future_line(char *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
	{
		free (s);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (s[i] != '\0')
		str[j++] = s[i++];
	str[j] = '\0';
	free (s);
	return (str);
}
