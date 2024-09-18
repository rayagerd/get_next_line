/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerdzhi <rgerdzhi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:33:18 by rgerdzhi          #+#    #+#             */
/*   Updated: 2024/09/18 21:50:39 by rgerdzhi         ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (s < d && s + n > d)
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = s[i -1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
