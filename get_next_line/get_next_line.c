/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:08:27 by rcarnero          #+#    #+#             */
/*   Updated: 2022/11/28 16:47:12 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_buffer(int fd, char *text_readed)
{
	char	*buffer_text;
	int		rd_byte;

	buffer_text = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer_text)
		return (NULL);
	rd_byte = 1;
	while (!ft_strchr(text_readed, '\n') && rd_byte != 0)
	{
		rd_byte = read(fd, buffer_text, BUFFER_SIZE);
		if (rd_byte < '\0')
		{
			return (ft_free_all(buffer_text, text_readed));
		}
		buffer_text[rd_byte] = '\0';
		if (!text_readed)
		{
			text_readed = (char *)malloc(1 * sizeof(char));
			text_readed[0] = '\0';
		}
		text_readed = ft_strjoin(text_readed, buffer_text);
	}
	free(buffer_text);
	return (text_readed);
}

char	*ft_get_line(char *text_readed)
{
	char	*mem_line;
	int		i;

	i = 0;
	if (!text_readed[i])
		return (NULL);
	while (text_readed[i] && text_readed[i] != '\n')
		i++;
	mem_line = malloc(sizeof(char) * (i + 2));
	if (!mem_line)
		return (NULL);
	i = 0;
	while (text_readed[i] != '\n' && text_readed[i])
	{
		mem_line[i] = text_readed[i];
		i++;
	}
	if (text_readed[i] == '\n')
	{
		mem_line[i] = '\n';
		i++;
	}
	mem_line[i] = '\0';
	return (mem_line);
}

char	*ft_next_text_readed(char *text_readed)
{
	char	*next_text;
	int		i;
	int		j;

	i = 0;
	while (text_readed[i] && text_readed[i] != '\n')
		i++;
	if (!text_readed[i])
	{
		free(text_readed);
		return (NULL);
	}
	next_text = malloc(ft_strlen(text_readed) - i + 1);
	if (!next_text)
		return (NULL);
	i++;
	j = 0;
	while (text_readed[i] != '\0')
	{
		next_text[j++] = text_readed[i++];
	}
	next_text[j] = '\0';
	free(text_readed);
	return (next_text);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*text_readed[42];

	if (fd < 0)
		return (NULL);
	text_readed[fd] = ft_read_buffer(fd, text_readed[fd]);
	if (!text_readed[fd])
		return (NULL);
	line = ft_get_line(text_readed[fd]);
	text_readed[fd] = ft_next_text_readed(text_readed[fd]);
	return (line);
}
