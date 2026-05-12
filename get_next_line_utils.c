/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:33:05 by eboualla          #+#    #+#             */
/*   Updated: 2026/05/12 20:59:10 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	line_size(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i])
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
