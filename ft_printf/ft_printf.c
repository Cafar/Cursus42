/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:49:28 by rcarnero          #+#    #+#             */
/*   Updated: 2022/10/12 11:34:42 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_check(char const str, va_list things)
{
	int	print_total;

	print_total = 0;
	if (str == 'c')
		print_total += ft_format_char(va_arg(things, int));
	else if (str == 's')
		print_total += ft_format_str(va_arg(things, char *));
	else if (str == 'p')
		print_total += ft_format_ptr(va_arg(things, unsigned long long));
	else if (str == 'd' || str == 'i')
		print_total += ft_format_dec(va_arg(things, int));
	else if (str == 'u')
		print_total += ft_format_undec(va_arg(things, unsigned int));
	else if (str == 'x')
		print_total += ft_hexabase(va_arg(things, unsigned int), 0);
	else if (str == 'X')
		print_total += ft_hexabase(va_arg(things, unsigned int), 1);
	else if (str == '%')
		print_total += ft_format_char('%');
	return (print_total);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		print_total;

	print_total = 0;
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			print_total += ft_format_check(str[i], args);
		}
		else
		{
			ft_putchar(str[i]);
			print_total++;
		}
		i++;
	}
	va_end(args);
	return (print_total);
}

// int	main(void)
// {
// 	printf("%d\n",printf("\x01\x02\x07\v\x08\f\r\n"));
// 	printf("%d\n",ft_printf("\x01\x02\x07\v\x08\f\r\n"));	
// 	return (0);
// }
