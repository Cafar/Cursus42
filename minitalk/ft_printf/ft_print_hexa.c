/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:40:48 by rcarnero          #+#    #+#             */
/*   Updated: 2022/12/08 12:27:36 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_ptr(unsigned long long ptr)
{
	int	count;

	count = 2;
	write(1, "0x", 2);
	if (!ptr)
	{
		write(1, "0", 1);
		count++;
	}	
	else
		count += ft_hexabase(ptr, 0);
	return (count);
}

int	ft_hexabase(unsigned long long num, int flag)
{
	static int	count;

	count = 0;
	if (num >= 16)
		ft_hexabase(num / 16, flag);
	if (flag == 0)
		ft_putchar_printf("0123456789abcdef"[num % 16]);
	else
		ft_putchar_printf("0123456789ABCDEF"[num % 16]);
	count++;
	return (count);
}
