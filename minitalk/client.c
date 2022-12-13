/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:08:40 by rcarnero          #+#    #+#             */
/*   Updated: 2022/12/12 18:49:53 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_signal_received = 1;

void	ft_send_signal(pid_t pid, char c)
{
	int				i;
	unsigned char	bit;

	i = 7;
	ft_printf("pepe |%c|\n", c);
	while (i >= 0)
	{
		bit = c >> i;
		bit = bit & 1;
		ft_printf("bit %d\n", bit);
		g_signal_received = 0;
		if (bit)
		{
			if (kill(pid, SIGUSR1) == -1)
				write(2, "!!!", 3);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				write(2, "!!!", 3);
		}
		i--;
		while (g_signal_received == 0)
			usleep(1);
	}
}

void	sig_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf(". ");
		g_signal_received = 1;
	}
}

void	ft_send_my_pid(char *my_pid_string, pid_t server_pid)
{
	int				i;
	int				j;
	unsigned char	bit;
	unsigned char	c;

	i = 0;
	while (i <= ft_strlen(my_pid_string))
	{
		j = 7;
		if (i == ft_strlen(my_pid_string))
			c = '_';
		else
			c = my_pid_string[i];
		while (j >= 0)
		{
			bit = c >> j & 1;
			if (bit)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			j--;
			usleep(2000);
		}
		
		i++;
	}
}

void ft_void(void)
{
	system("leaks -q client");
}

int	main(int argc, char *argv[])
{
	//atexit(ft_void);
	pid_t	server_pid;
	char	*my_pid_string;
	int		i;

	i = 0;
	if (argc != 3)
		write(1, "WTF... I'm not executing that.\n", 31);
	else
	{
		signal(SIGUSR1, sig_handler);
		my_pid_string = ft_itoa(getpid());
		server_pid = ft_atoi(argv[1]);
		ft_printf("mi pid: %s\n", my_pid_string);
		ft_printf("SIGNAL RESPONSE: ");
		ft_send_my_pid(my_pid_string, server_pid);
		i = 0;
		g_signal_received = 1;
		while (argv[2][i])
		{			
			ft_send_signal(server_pid, argv[2][i]);
			i++;
		}
		ft_send_signal(server_pid, '\0');
		//free(server_pid);
	}
	return (0);
}
