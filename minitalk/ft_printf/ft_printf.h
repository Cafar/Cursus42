/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:49:47 by rcarnero          #+#    #+#             */
/*   Updated: 2022/12/08 12:27:08 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(char const *str, ...);
int		ft_format_check(char const str, va_list things);
int		ft_format_char(int c);
int		ft_format_str(char *s);
int		ft_format_dec(long num);
int		ft_format_ptr(unsigned long long ptr);
int		ft_hexabase(unsigned long long num, int flag);
int		ft_format_dec(long num);
int		ft_count_dec(long num);
int		ft_format_undec(long num);
int		ft_strlen_printf(char *ptr);
void	ft_putchar_printf(int c);
void	ft_putstr_printf(char *s);
#endif