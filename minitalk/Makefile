SERVER   = server
CLIENT   = client
CC	     = gcc
FLAGS    = -Wall -Werror -Wextra
LIBFT	 = libft/libft.a
FTPRINTF = ft_printf/ft_printf.a

all : $(LIBFT) $(FTPRINTF) $(SERVER) $(CLIENT)

$(LIBFT) :
	@make -C libft

$(FTPRINTF) : 
	@make -C ft_printf

$(SERVER) : server.c minitalk.h
	@$(CC) $(FLAGS) server.c $(LIBFT) $(FTPRINTF) -o $@
	@printf "\e[38;5;226m./$@ successfully build🥑\e[0m\n"

$(CLIENT) : client.c minitalk.h
	@$(CC) $(FLAGS) client.c $(LIBFT) $(FTPRINTF) -o $@
	@printf "\e[38;5;46m./$@ successfully build🥝\e[0m\n"

%.o : %.c
	@$(CC) $(FLAGS) $< -c

clean :
	@make clean -C ft_printf
	@make clean -C libft
	@rm -f *.o
	@printf "\e[38;5;206m.o files deleted🚽\e[0m\n"

fclean: clean
	@make fclean -C ft_printf
	@make clean -C libft
	@rm -f $(SERVER) $(CLIENT)
	@printf "\e[38;5;200mBinaries deleted🗑\e[0m\n"

re: fclean all

.PHONY: all re fclean clean 