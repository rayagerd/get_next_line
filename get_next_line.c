/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerdzhi <rgerdzhi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:28:40 by rgerdzhi          #+#    #+#             */
/*   Updated: 2024/09/18 20:16:17 by rgerdzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*ft_append_line(char *line, char *buf, int *pos, int len)
{
	int		i;
	char	*new_line;

	i = 0;
	while (*pos + i < len && buf[*pos + i] != '\n')
		i++;
	new_line = malloc(ft_strlen(line) + i + 1);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	ft_strcpy(new_line, line);
	ft_strncat(new_line, buf + *pos, i);
	free(line);
	line = NULL;
	*pos += i;
	if (*pos < len && buf[*pos] == '\n')
	{
		(*pos)++;
		return (new_line);
	}
	*pos = 0;
	return (new_line);
}

static int	ft_read_buffer(int fd, char *buf, int *len)
{
	*len = read(fd, buf, BUFFER_SIZE);
	if (*len <= 0)
		return (0);
	buf[*len] = '\0';
	return (1);
}

static char	*ft_get_line(int fd, char *buf, int *pos, int *len)
{
	char	*line;

	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	if (*pos == 0 && ft_read_buffer(fd, buf, len) == 0)
	{
		free(line);
		return (NULL);
	}
	while (line && *pos < *len)
	{
		line = ft_append_line(line, buf, pos, *len);
		if (*pos == 0)
		{
			if (!ft_read_buffer(fd, buf, len))
				return (line);
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	int			pos;
	int			len;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pos = 0;
	if (!buf)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return (NULL);
		ft_memset(buf, '\0', BUFFER_SIZE + 1);
	}
	line = ft_get_line(fd, buf, &pos, &len);
	if (!line)
	{
		if (buf != NULL)
		{
			free(buf);
			buf = NULL;
		}
	}
	return (line);
}
/*
int main(void)
{
	char	*line = NULL;
	int		i;
	int		fd1;

	fd1 = open("test.txt", O_RDONLY);
	i = 1;
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("%s\n", line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}
*/
