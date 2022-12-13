# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 17:53:44 by rcarnero          #+#    #+#              #
#    Updated: 2022/12/08 12:33:17 by rcarnero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c \
ft_printf_utils.c \
ft_print_char.c \
ft_print_hexa.c \
ft_print_dec.c \
ft_print_str.c


NAME = ft_printf.a
OBJS = ${SRCS:.c=.o}
FLAGS = -Wall -Wextra -Werror
CC = gcc
AR = ar rcs
RM = rm -f

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	${AR} ${NAME} ${OBJS}

all: $(NAME)
	
clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re