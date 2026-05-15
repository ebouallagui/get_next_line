/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:24:57 by eboualla          #+#    #+#             */
/*   Updated: 2026/05/15 12:20:51 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#define BUFFER_SIZE

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	static char	*stash;
	char		*new_stash;
	int			bytes_read;

	while (!ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
		if (bytes_read != BUFFER_SIZE || bytes_read == -1)
			return (NULL);
		new_stash = malloc(sizeof(buf) + sizeof(stash) + 2);
		if (!new_stash)
			return (NULL);
		new_stash = ft_memcpy(new_stash, stash, sizeof(stash));
		new_stash = ft_strlcat(new_stash, buf, bytes_read);
		free(stash);
		stash = new_stash;
		free new_stash;
	}
	line = ft_cutline(line, stash, '\n');
	stash = stash[ft_strlen(line)];
	return (line);
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
