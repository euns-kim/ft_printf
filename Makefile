# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 22:12:05 by eunskim           #+#    #+#              #
#    Updated: 2022/11/18 19:19:45 by eunskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs

SRCS = $(addprefix $(SRC_DIR)/, \
ft_printf.c \
parser.c \
print_conversions.c \
print_c.c \
print_di.c \
print_p.c \
print_s.c \
print_u.c \
print_x.c \
nbr_printer.c \
char_printer.c \
prc_wdt_helper.c \
sign_prefix_helper.c)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	mv libft/libft.a libftprintf.a
	ar rcs $(NAME) $(OBJS)
	
$(addprefix $(SRC_DIR), $(OBJS)) : $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

bonus : all
	
clean :
	make -C libft fclean
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
