# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 12:19:20 by lprado-l          #+#    #+#              #
#    Updated: 2025/10/29 12:44:09 by lprado-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_CFLAGS = -g
SRCS = ft_isalpha.c \
       ft_isdigit.c \
       ft_isalnum.c \
       ft_isascii.c \
       ft_isprint.c \
       ft_strlen.c \
       ft_memset.c \
       ft_bzero.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_strlcpy.c \
       ft_strlcat.c \
       ft_toupper.c \
       ft_tolower.c \
       ft_strchr.c \
       ft_strrchr.c \
       ft_strncmp.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_strnstr.c \
       ft_atoi.c \
       ft_calloc.c \
       ft_strdup.c \
       ft_substr.c \
       ft_strjoin.c
OBJS = $(SRCS:.c=.o)
TEST_SRC = test.c
TEST_EXEC = exec_prog
DEBUG_EXEC = debug_prog
TEST2_SRC = test2.c
TEST2_EXEC = exec_prog2
DEBUG2_EXEC = debug_prog2 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_EXEC): $(NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) $(NAME) -o $@ -lbsd	

test: $(TEST_EXEC)
	./$(TEST_EXEC)

$(DEBUG_EXEC): $(NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) $(DEBUG_CFLAGS) $(TEST_SRC) $(NAME) -o $@ -lbsd

debug: fclean
	$(MAKE) CFLAGS="$(CFLAGS) $(DEBUG_CFLAGS)" $(DEBUG_EXEC)

gdb: debug
	gdb -tui ./$(DEBUG_EXEC)

$(TEST2_EXEC): $(NAME) $(TEST2_SRC)
	$(CC) $(CFLAGS) $(TEST2_SRC) $(NAME) -o $@ -lbsd	

test2: $(TEST2_EXEC)
	./$(TEST2_EXEC)

$(DEBUG2_EXEC): $(NAME) $(TEST2_SRC)
	$(CC) $(CFLAGS) $(DEBUG_CFLAGS) $(TEST2_SRC) $(NAME) -o $@ -lbsd

debug2: fclean
	$(MAKE) CFLAGS="$(CFLAGS) $(DEBUG_CFLAGS)" $(DEBUG2_EXEC)

gdb2: debug2
	gdb -tui ./$(DEBUG2_EXEC)

$(NAME): $(OBJS)
	ar rcs $@ $^

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(TEST_EXEC) $(DEBUG_EXEC) $(TEST2_EXEC) $(DEBUG2_EXEC)

re: fclean all
	
.phony: all clean fclean re test debug gdb test2 debug2 gdb2
