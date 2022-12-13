/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:40:36 by rcarnero          #+#    #+#             */
/*   Updated: 2022/12/12 18:46:43 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_client_pid = 0;

void	save_client_pid(int char_converted)
{
	static int	client_pid;

	if (char_converted != '_')
		client_pid = (client_pid * 10) + (char_converted - 48);
	if (char_converted == '_' && g_client_pid == 0)
	{
		g_client_pid = client_pid;
		client_pid = 0;
	}
}

char	check_signal(int signal)
{
	char	c;

	c = 0;
	if (signal == SIGUSR1)
		c = '1';
	else
		c = '0';
	//ft_printf("%d\n", signal);
	return (c);
}

int	ft_binary_to_decimal(char *n)
{
	char		*num;
	int			dec_value;
	int			base;
	int			i;

	num = n;
	dec_value = 0;
	base = 1;
	i = ft_strlen(n) - 1;
	//ft_printf("bit cargado %s\n", n);
	while (i >= 0)
	{
		if (num[i] == '1')
			dec_value += base;
		base = base * 2;
		i--;
	}
	return (dec_value);
}

void	sig_handler(int signal)
{
	static char	*binary = NULL;
	static int	i = 0;
	int			char_converted;	

	if (binary == NULL)
		binary = (char *) ft_calloc (8, 1);
	binary[i++] = check_signal(signal);
	if (i == 8)
	{
		char_converted = ft_binary_to_decimal(binary);
		if (g_client_pid != 0)
			write (1, &char_converted, 1);
		free(binary);
		binary = NULL;
		i = 0;
		if (g_client_pid == 0)
			save_client_pid(char_converted);
		if (char_converted == '\0')
		{
			kill(g_client_pid, SIGUSR1);
			g_client_pid = 0;
		}
	}
	if (g_client_pid != 0)
		kill(g_client_pid, SIGUSR1);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("pid : %d\n", pid);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
