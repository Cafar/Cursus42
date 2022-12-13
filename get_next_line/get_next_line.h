/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:06:21 by rcarnero          #+#    #+#             */
/*   Updated: 2022/11/28 16:47:58 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_read_buffer(int fd, char *text_asked);
char	*ft_next_text_read(char *text_asked);
char	*ft_get_line(char *all_txt);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
void	*ft_free_all(char *buffer_text, char *text_asked);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif