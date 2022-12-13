/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:33:59 by rcarnero          #+#    #+#             */
/*   Updated: 2022/11/26 13:42:19 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

void functionA(void)
{
   system("leaks a.out");
}

int	main(void)
{
	int		fd;
	int	fd1;
	char	*line;

	fd = 1;
	fd = open("read_error.txt", O_RDONLY);
	fd1 = open("hola.txt", O_RDONLY);
	if (fd == -1)
	{
		write(1, "No existe archivo\n", 18);
		return (-1);
	}
	line = get_next_line(fd);
	while (line)
	{
		write(1, line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
	}
	line = get_next_line(fd1);
	while (line)
	{
		write(1, line, ft_strlen(line));
		free(line);
		line = get_next_line(fd1);
	}
	//atexit(functionA);
}
