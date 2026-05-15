/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:24:57 by eboualla          #+#    #+#             */
/*   Updated: 2026/05/15 13:01:31 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#define BUFFER_SIZE

char *make_new_stash(char *stash, char *buf, int len, int option)
{
	char *new_stash;
	if(option == 1)
	{
		new_stash = malloc(len + sizeof(stash) + 2);
			if (!new_stash)
				return (NULL);
		new_stash = ft_memcpy(new_stash, stash, sizeof(stash));
		new_stash = ft_strlcat(new_stash, buf, len);
	}
	else
	{
		new_stash = stash + len + 1;
	}
	free(stash);
	stash = new_stash;
	free(new_stash);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	static char	*stash;
	int			bytes_read;

	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buf[bytes_read] = '\0';
		stash = make_new_stash(stash, buf, bytes_read, 1)
	}
	line = ft_cutline(line, stash, '\n');
	stash = make_new_stash(stash, line, ft_strlen(line), 2);
	return (line);
}

//missing: if bytes_read == 0 (EOF) -> line = without '\n'

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
