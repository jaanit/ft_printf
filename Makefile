# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/07 10:47:29 by rjaanit           #+#    #+#              #
#    Updated: 2021/12/11 13:55:29 by rjaanit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = gcc  
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rsc

NAME    = libftprintf.a
SRCS    =  ft_printf.c ft_printf_utils.c ft_imprime_p.c ft_hexadecimal.c \

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
			$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $?

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

