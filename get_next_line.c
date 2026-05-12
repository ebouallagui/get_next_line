/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:24:57 by eboualla          #+#    #+#             */
/*   Updated: 2026/05/12 17:17:05 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*current_line;
	char		buf[10];
	static char	*rest;
	size_t		line_len;

	read(fd, buf, sizeof(buf));
	if (bytes_read == -1)
		return (NULL);
	line_len = line_size(rest);
	current_line = malloc(line_len + 1);
	if (!current_line)
		return (NULL);
	while (line_len)
	{
		*current_line++ = *rest++;
		len--;
	}
	*current_line = '\0';
	return (current_line);
}

int	main(void)
{
	int	fd;

	fd = open(test.txt);
	if (fd == -1)
		exit(1);
	while ()
		printf(get_next_line(fd));
	close(fd);
}
