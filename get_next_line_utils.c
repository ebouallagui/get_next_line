/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:33:05 by eboualla          #+#    #+#             */
/*   Updated: 2026/05/12 17:12:16 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int line_size(char *str)
{
	size_t i = 0;
	if (!str)
		retrurn (0);
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}
