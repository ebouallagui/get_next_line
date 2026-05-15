/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:33:05 by eboualla          #+#    #+#             */
/*   Updated: 2026/05/14 17:04:51 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_memcpy(char *dest, char *src, size_t n)
{
	char	*d;
	char	*s;

	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	*d = '\0';
	return (dest);
}

int read_to_nl(int fd, char *buf, int bufsize)
{
	int i = 0;
	int bytes_read = 0;
	int is_eol = 0;
	while (i < bufsize)
	{
		bytes_read += read(fd, buf[i], 1);
		if (buf[i] == '\n')
			return (bytes_read);
		i++;
	}
	return (bytes_read);
}
