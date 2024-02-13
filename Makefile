# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 08:30:37 by alicifer          #+#    #+#              #
#    Updated: 2023/12/11 12:28:40 by alicifer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC =  gcc
CFLAGS = -Wall -Wextra -Werror
SOURCE = ft_printf.c \
		ft_putchar.c \
		ft_putnumber.c \
		ft_pointer.c \
		ft_itoa.c \

OBJECTS = $(SOURCE:.c=.o)

$(NAME) : $(OBJECTS) 
	ar crs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 