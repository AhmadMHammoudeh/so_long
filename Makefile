# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 08:21:23 by ahhammou          #+#    #+#              #
#    Updated: 2021/11/15 12:56:20 by ahhammou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c 

NAME = so_long.a
LIBS = ./mlx
LIBSft = ./libft


SOURCES = 	*.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME) 

$(NAME): $(OBJECTS)
	$(MAKE) -C $(LIBS) all
	$(MAKE) -C $(LIBSft) 
	# ar cr $(NAME) $(OBJECTS)

	
$(OBJECTS): $(SOURCES)
	gcc -I./mlx -g -L./mlx -lmlx -framework OpenGL -framework AppKit *.c  ./libft/*.c -o so_long
clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBS) clean
	$(MAKE) -C $(LIBSft) clean


fclean: clean
	rm -f $(NAME)
	rm -f so_long

re: fclean all

.PHONY: all clean fclean re  
