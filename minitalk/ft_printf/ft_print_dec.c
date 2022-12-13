/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:27:25 by rcarnero          #+#    #+#             */
/*   Updated: 2022/12/08 12:28:27 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_dec(long num)
{
	int	count;

	count = 0;
	if (num == 0)
		count++;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	ft_format_dec(long num)
{
	int	count;

	count = ft_count_dec(num);
	if (num < 0)
	{
		write(1, "-", 1);
		count++;
		num *= -1;
	}
	if (num > 9)
	{
		ft_format_dec(num / 10);
		ft_format_dec(num % 10);
	}
	else
		ft_putchar_printf(num + '0');
	return (count);
}

int	ft_format_undec(long num)
{
	if (num <= 4294967295 && num >= 0)
	{
		if (num > 9)
		{
			ft_format_dec(num / 10);
			ft_format_dec(num % 10);
		}
		else
			ft_putchar_printf(num + '0');
	}
	return (ft_count_dec(num));
}
