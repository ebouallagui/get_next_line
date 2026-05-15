/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:24:57 by eboualla          #+#    #+#             */
/*   Updated: 2026/05/13 15:35:40 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#define BUFFER_SIZE

char	*get_next_line(int fd)
{
	char	*current_line;
	char	buf[20];
	size_t	line_len;
	int		bytes_read;

	bytes_read = read_to_nl(fd, buf, sizeof(buf));
	if (bytes_read == -1)
		return (NULL);
	if (bytes_read <= sizeof(buf))
	{
		current_line = malloc(bytes_read + 2);
		if (!current_line)
			return (NULL);
		buf[bytes_read] = '\n';
		buf[bytes_read + 1] = '\0';
		current_line = ft_memcpy(current_line, buf, bytes_read);
	}
	else
		return (current_line);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		exit(1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			return (67);
		}
	}
	close(fd);
}
