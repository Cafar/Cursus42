/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:35:24 by rcarnero          #+#    #+#             */
/*   Updated: 2022/09/21 18:03:44 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	flag;

	flag = 0;
	if (ft_isdigit(c) || ft_isalpha(c))
	{
		flag = 1;
	}
	return (flag);
}
//return (ft_isdigit(c) || ft_isalpha(c))