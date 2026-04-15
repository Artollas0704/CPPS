
NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
LIBCREATE = ar rc
RM = rm -rf

SRCS = megaphone.cpp

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