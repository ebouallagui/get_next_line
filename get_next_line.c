/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:24:57 by eboualla          #+#    #+#             */
/*   Updated: 2026/05/12 20:57:01 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*current_line;
	char	buf[20];
	size_t	line_len;
	int		bytes_read;

	bytes_read = read(fd, buf, sizeof(buf));
	if (bytes_read == -1)
		return (NULL);
	buf[bytes_read] = '\0';
	line_len = line_size(buf);
	current_line = malloc(line_len + 1);
	if (!current_line)
		return (NULL);
	current_line = ft_memcpy(current_line, buf, line_len);
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
	printf("next line:\n%s\n", get_next_line(fd));
	close(fd);
}
