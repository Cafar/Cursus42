/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:24:58 by rcarnero          #+#    #+#             */
/*   Updated: 2022/10/12 10:51:37 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *ptr)
{
	int	i;

	if (!ptr)
		return (6);
	i = 0;
	while (ptr[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{	
	if (!s)
	{
		ft_putstr("(null)");
		return ;
	}
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
}
