# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 08:21:23 by ahhammou          #+#    #+#              #
#    Updated: 2021/11/02 21:03:20 by ahhammou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c 

NAME = so_long.a
LIBS = ./mlx
LIBSft = ./libft


SOURCES = 	*.c

OBJECTS = $(SOURCES:.c=.o)
OBJECTSB = $(BONUS:.c=.o)

all: $(NAME) 

$(NAME): $(OBJECTS)
	$(MAKE) -C $(LIBS) all
	$(MAKE) -C $(LIBSft) bonus
	ar cr $(NAME) $(OBJECTS) 

	
$(OBJECTS): $(SOURCES)
	gcc -c $(CFLAGS) $^
clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBS) clean
	$(MAKE) -C $(LIBSft) clean


fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re  
