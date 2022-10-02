/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:00:04 by rcarnero          #+#    #+#             */
/*   Updated: 2022/10/01 20:25:40 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{	
	if (lst)
	{
		if (*lst)
		{
			ft_lstlast(*lst)->next = new;
		}
		else
			*lst = new;
	}
}
