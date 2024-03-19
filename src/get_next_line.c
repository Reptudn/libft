/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 08:33:01 by jkauker           #+#    #+#             */
/*   Updated: 2024/03/19 11:35:19 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

char	*read_file(int fd, char **str)
{
	char	buffer[BUFFER_SIZE + 1];
	long	read_amount;
	char	*line;
	char	*temp;

	read_amount = 0;
	while (!ft_strchr(buffer, '\n'))
	{
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
		read_amount = read(fd, buffer, BUFFER_SIZE);
		if (read_amount == -1)
			return (0);
		if (read_amount == 0)
			break ;
		if (!*str)
			*str = ft_strdup(buffer);
		else
			*str = strjoin(*str, buffer);
		if (!*str)
			return (0);
	}
	if (*str == 0)
		return (0);
	line = substr(*str, 0, ft_strchr(*str, '\n') - *str + 1);
	temp = substr(*str, ft_strchr(*str, '\n') - *str + 1, BUFFER_SIZE);
	//free(str);
	*str = temp;
	if (!*str && read_amount <= 0)
	{
		free(line);
		return (0);
	}
	buffer[0] = 0;
	if (line && *line == 0)
		return (0);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str = 0;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		free (str);
		str = 0;
		return (0);
	}
	// str = malloc(sizeof(char) * BUFFER_SIZE);
	line = read_file(fd, &str);
	if (!line)
	{
		free(str);
		str = 0;
		return (0);
	}
	if (!str)
		return (0);
	return (line);
}
