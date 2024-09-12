/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerdzhi <rgerdzhi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:33:18 by rgerdzhi          #+#    #+#             */
/*   Updated: 2024/09/12 18:37:30 by rgerdzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read_buffer(int fd, char *buf, int *len)
{
	*len = read(fd, buf, BUFFER_SIZE);
	if (*len <= 0)
		return (0);
	return (1);
}

