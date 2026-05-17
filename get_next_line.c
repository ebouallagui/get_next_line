/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:24:57 by eboualla          #+#    #+#             */
/*   Updated: 2026/05/17 22:42:55 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_to_stash(int fd, char *stash)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes_read;

	while (!ft_strchr(stash, '\n'))
	{
		stash = malloc(ft_strlen(stash) + BUFFER_SIZE + 1);
		if (!stash)
			return (NULL);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			return (stash);
		buf[bytes_read] = '\0';
		ft_strjoin(stash, buf, bytes_read);
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (ft_strchr(stash, '\n'))
		line = malloc(ft_strlen(stash) + 2);
	else
		line = malloc(ft_strlen(stash) + 1);
	if (!line)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;
	char		*new_stash;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	line = extract_line(stash);
	new_stash = ft_substr(stash, ft_strlen(line), ft_strlen(stash));
	free(stash);
	stash = malloc(ft_strlen(new_stash));
	if (!stash)
		return (NULL);
	stash = new_stash;
	free(new_stash);
	return (line);
}
/*
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
*/
