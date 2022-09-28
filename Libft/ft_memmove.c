/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:05:56 by rcarnero          #+#    #+#             */
/*   Updated: 2022/09/28 15:56:52 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	int		i;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		while (len--)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
