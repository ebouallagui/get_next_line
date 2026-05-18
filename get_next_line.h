/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:37:25 by eboualla          #+#    #+#             */
/*   Updated: 2026/05/18 14:00:15 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*read_to_stash(int fd, char *stash);
char	*extract_line(char *stash);
char	*get_next_line(int fd);

size_t	ft_strlen(char *str);
char	*ft_memcpy(char *dest, char *src, size_t n);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1,char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
