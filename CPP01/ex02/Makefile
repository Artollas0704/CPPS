# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 15:23:43 by aralves-          #+#    #+#              #
#    Updated: 2026/02/17 22:23:16 by aralves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = reference
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
LIBCREATE = ar rc
RM = rm -rf

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

bonus: all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re