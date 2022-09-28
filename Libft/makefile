# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 17:53:44 by rcarnero          #+#    #+#              #
#    Updated: 2022/09/28 20:00:40 by rcarnero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PATH_SRC = ./
HEADER = ./includes/
FLAG = -Wall -Wextra -Werror
OPTION = -c -I $(HEADER)
SRC = $(PATH_SRC)ft_bzero.c $(PATH_SRC)ft_isalnum.c $(PATH_SRC)ft_isalpha.c \
		$(PATH_SRC)ft_isdigit.c $(PATH_SRC)ft_isascii.c \
		$(PATH_SRC)ft_strlen.c $(PATH_SRC)ft_isprint.c $(PATH_SRC)ft_memset.c \
		$(PATH_SRC)ft_memcpy.c $(PATH_SRC)ft_memmove.c $(PATH_SRC)ft_strlcpy.c \
		$(PATH_SRC)ft_strlcat.c $(PATH_SRC)ft_toupper.c $(PATH_SRC)ft_tolower.c \
		$(PATH_SRC)ft_strchr.c $(PATH_SRC)ft_strrchr.c $(PATH_SRC)ft_strncmp.c \
		$(PATH_SRC)ft_memchr.c $(PATH_SRC)ft_memcmp.c $(PATH_SRC)ft_strnstr.c \
		$(PATH_SRC)ft_atoi.c $(PATH_SRC)ft_calloc.c $(PATH_SRC)ft_strdup.c \
		$(PATH_SRC)ft_substr.c $(PATH_SRC)ft_strjoin.c $(PATH_SRC)ft_itoa.c \
		$(PATH_SRC)ft_strmapi.c
OBJ = ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isdigit.o ft_isascii.o ft_strlen.o \
		ft_isprint.o ft_memset.o ft_memcpy.o ft_memmove.o ft_strlcpy.o ft_strlcat.o \
		ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o ft_memchr.o \
		ft_memcmp.o ft_strnstr.o ft_atoi.o ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o \
		ft_itoa.o ft_strmapi.o
all: $(NAME)

$(NAME):
	gcc $(FLAG) $(OPTION) $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all