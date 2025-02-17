# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/25 17:53:15 by ashishae          #+#    #+#              #
#    Updated: 2020/01/28 16:23:51 by ashishae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBASM_SRCS = srcs/ft_read.s srcs/ft_strcmp.s srcs/ft_strcpy.s srcs/ft_strdup.s\
srcs/ft_strlen.s srcs/ft_write.s
LIBASM_OBJS = $(LIBASM_SRCS:.s=.o)
OBJS = $(SRCS:.c=.o)
# NAME = miniRT

TEST_SRCS = test/main.c test/test_ft_read.c test/test_ft_strcmp.c\
test/test_ft_strcpy.c test/test_ft_strlen.c test/test_ft_strdup.c\
test/test_ft_write.c
TEST_OBJS = $(TEST_SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

.PHONY: 	clean fclean all re bonus

all:		libasm.a

.s.o:
			nasm -fmacho64 $< -o $@

.c.o:
			gcc $(CFLAGS) -c $< -o $@

libasm.a:	$(LIBASM_OBJS)
			ar -rcs libasm.a $(LIBASM_OBJS)

run_test:	libasm.a $(TEST_OBJS)
			gcc libasm.a $(TEST_OBJS) -o run_test && ./run_test

clean:
			rm -f $(LIBASM_OBJS) $(TEST_OBJS) run_test

fclean: 	clean
			rm -f libasm.a

re:			fclean all
