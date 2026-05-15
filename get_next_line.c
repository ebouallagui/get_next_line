/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:24:57 by eboualla          #+#    #+#             */
/*   Updated: 2026/05/14 17:04:45 by eboualla         ###   ########.fr       */
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
		if (bytes_read == -1)
			return (NULL);
		new_stash = malloc(sizeof(buf) + sizeof(stash) + 1);
		if (!new_stash)
			return (NULL);
		new_stash = ft_memcpy(new_stash, buf);
		new_stash = ft_strlcat(new_stash, buf);// add '\0'!!
		free(stash);
		stash = new_stash;
	}
	line = ft_cutword(line, stash, i);
	line[ft_strlen(line)] = '\n';
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
	printf("next line:\n%s\n", get_next_line(fd));
	close(fd);
}
