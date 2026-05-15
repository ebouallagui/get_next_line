/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:33:05 by eboualla          #+#    #+#             */
/*   Updated: 2026/05/15 13:01:34 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_memcpy(char *dest, char *src, unsigned int n)
{
	char	*d;
	char	*s;

	if (!src)
		return (dest);
	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	*d = '\0';
	return (dest);
}

char	*ft_strlcat(char *dest, char *src, int bytes_read)
{
	int	i;
	int	destlen;

	i = 0;
	destlen = 0;
	while (dest[destlen])
		destlen++;
	while (src[i] && i < bytes_read)
	{
		dest[i + destlen] = src[i];
		i++;
	}
	dest[i + destlen] = '\0';
	return (dest);
}

int ft_strchr(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_cutline(char *line, char *stash, char c)
{
	size_t	len;
	int i;

	i = 0;
	len = 0;
	while (stash[len] && stash[len] != c)
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\n';
	return (line);
}
