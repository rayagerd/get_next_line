/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerdzhi <rgerdzhi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:33:18 by rgerdzhi          #+#    #+#             */
/*   Updated: 2024/09/18 20:15:33 by rgerdzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, const char *src)
{
	char	*dst_start;

	if (!src || !dst)
		return (NULL);
	dst_start = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (dst_start);
}

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	dst_len;

	if (!src || !dst)
		return (NULL);
	dst_len = ft_strlen(dst);
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	if (!s)
		return (NULL);
	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
