/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:37:25 by eboualla          #+#    #+#             */
/*   Updated: 2026/05/17 22:42:12 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE = 42

# include <stdlib.h>
# include <unistd.h>

char	*read_to_stash(int fd, char *stash);
char	*extract_line(char *stash);
char	*get_next_line(int fd);

size_t	ft_strlen(char *str);
char	*ft_memcpy(char *dest, char *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif
