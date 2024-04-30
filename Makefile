# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 11:03:31 by mhummel           #+#    #+#              #
#    Updated: 2024/03/26 12:40:26 by mhummel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar

CFILES =	ft_printf.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putnbr_fd.c \
			ft_putnbr_base_p.c \
			ft_putnbr_base_u.c \
			ft_putnbr_base_x.c \
			ft_strlen.c \
			ft_error.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	$(AR) rcs $(NAME) $(OFILES)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME) $(OBFILES)

re: fclean all

.PHONY: all clean fclean re
