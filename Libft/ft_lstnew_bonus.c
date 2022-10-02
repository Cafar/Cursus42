/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:40:03 by rcarnero          #+#    #+#             */
/*   Updated: 2022/10/01 16:55:31 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l_content;

	l_content = (t_list *)malloc(sizeof(t_list));
	if (!l_content)
		return (NULL);
	l_content->content = content;
	l_content->next = NULL;
	return (l_content);
}
