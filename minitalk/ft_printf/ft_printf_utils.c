/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:24:58 by rcarnero          #+#    #+#             */
/*   Updated: 2022/12/08 12:27:50 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_printf(char *ptr)
{
	int	i;

	if (!ptr)
		return (6);
	i = 0;
	while (ptr[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar_printf(int c)
{
	write(1, &c, 1);
}

void	ft_putstr_printf(char *s)
{	
	if (!s)
	{
		ft_putstr_printf("(null)");
		return ;
	}
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
}
