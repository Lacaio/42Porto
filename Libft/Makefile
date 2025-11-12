# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 12:19:20 by lprado-l          #+#    #+#              #
#    Updated: 2025/11/12 21:00:36 by lprado-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
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
       ft_strjoin.c \
       ft_strtrim.c \
       ft_split.c \
       ft_itoa.c \
       ft_strmapi.c \
       ft_striteri.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = ft_lstnew.c \
	     ft_lstadd_front.c \
	     ft_lstsize.c \
	     ft_lstlast.c \
	     ft_lstadd_back.c \
	     ft_lstdelone.c \
	     ft_lstclear.c \
	     ft_lstiter.c \
	     ft_lstmap.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

TEST_SRC = test.c
TEST_EXEC = exec_prog
DEBUG_EXEC = debug_prog
TEST2_SRC = test2.c
TEST2_EXEC = exec_prog2
DEBUG2_EXEC = debug_prog2 
TEST3_SRC = test3.c
TEST3_EXEC = exec_prog3
DEBUG3_EXEC = debug_prog3
TEST4_SRC = test4.c
TEST4_EXEC = exec_prog4
DEBUG4_EXEC = debug_prog4

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

$(TEST3_EXEC): $(NAME) $(TEST3_SRC)
	$(CC) $(CFLAGS) $(TEST3_SRC) $(NAME) -o $@ -lbsd

test3: $(TEST3_EXEC)
	./$(TEST3_EXEC)

$(DEBUG3_EXEC): $(NAME) $(TEST3_SRC)
	$(CC) $(CFLAGS) $(DEBUG_CFLAGS) $(TEST3_SRC) $(NAME) -o $@ -lbsd

debug3: fclean
	$(MAKE) CFLAGS="$(CFLAGS) $(DEBUG_CFLAGS)" $(DEBUG3_EXEC)

gdb3: debug3
	gdb -tui ./$(DEBUG3_EXEC)

$(TEST4_EXEC): bonus $(TEST4_SRC)
	$(CC) $(CFLAGS) $(TEST4_SRC) $(NAME) -o $@ -lbsd

test4: $(TEST4_EXEC)
	./$(TEST4_EXEC)

$(DEBUG4_EXEC): $(NAME) $(TEST4_SRC)
	$(CC) $(CFLAGS) $(DEBUG_CFLAGS) $(TEST4_SRC) $(NAME) -o $@ -lbsd

debug4: fclean
	$(MAKE) CFLAGS="$(CFLAGS) $(DEBUG_CFLAGS)" $(DEBUG4_EXEC)

gdb4: debug4
	gdb -tui ./$(DEBUG4_EXEC)

$(NAME): $(OBJS)
	ar rcs $@ $^

all: $(NAME)

bonus:	$(OBJS) $(BONUS_OBJS)
		ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(TEST_EXEC) $(DEBUG_EXEC) $(TEST2_EXEC) $(DEBUG2_EXEC) $(TEST3_EXEC) $(DEBUG3_EXEC) $(TEST4_EXEC) $(DEBUG4_EXEC)

re: fclean all
	
.phony: all clean fclean re test debug gdb test2 debug2 gdb2 test3 debug3 gdb3 test4 debug4 gdb4
