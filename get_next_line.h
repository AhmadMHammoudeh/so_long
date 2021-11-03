/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:48:23 by ahhammou          #+#    #+#             */
/*   Updated: 2021/11/03 07:22:37 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include <fcntl.h>
// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 5

int		ft_strlen(char *s);
char	*ft_check_d(char *d);
char	*ft_strchr(char *src, int c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_beforenew(char *s);
char	*get_next_line(int fd, int z);
char	*ft_w16(char *s, int fd);
char	*ft_strnew(char *s);
char	*ft_future_line(char *src);
char	*ft_speedo(char *src);

// # endif
#endif
