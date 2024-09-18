/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerdzhi <rgerdzhi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:28:40 by rgerdzhi          #+#    #+#             */
/*   Updated: 2024/09/18 22:15:33 by rgerdzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static void	ft_check_buf(char *buf)
{
	int	pos_n;

	pos_n = 0;
	while (buf[pos_n] && buf[pos_n] != '\n')
		pos_n++;
	if (buf[pos_n] == '\n')
		ft_memmove(buf, buf + pos_n + 1, ft_strlen(buf + pos_n + 1) + 1);
	else
		buf[0] = '\0';
}

static char	*ft_append_line(char *line, char *buf)
{
	int		pos_n;
	char	*new_line;

	if (!*buf)
		return (line);
	pos_n = 0;
	while (buf[pos_n] && buf[pos_n] != '\n')
		pos_n++;
	if (buf[pos_n] && buf[pos_n] == '\n')
		pos_n++;
	new_line = malloc(ft_strlen(line) + pos_n + 1);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	ft_strcpy(new_line, line);
	ft_strncat(new_line, buf, pos_n);
	free(line);
	line = NULL;
	return (new_line);
}

static int	ft_read_buffer(int fd, char *buf)
{
	int	bytes_read;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read < 0)
		return (-1);
	buf[bytes_read] = '\0';
	return (bytes_read);
}

static char	*ft_get_line(int fd, char *buf)
{
	char	*line;
	int		len;

	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (buf && buf[0])
	{
		ft_check_buf(buf);
		line = ft_append_line(line, buf);
	}
	while (line && (!buf[0] || !ft_strchr(buf, '\n')))
	{
		len = ft_read_buffer(fd, buf);
		if (len == 0)
			break ;
		if (len < 0)
		{
			free(line);
			return (0);
		}
		line = ft_append_line(line, buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf[fd])
	{
		buf[fd] = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf[fd])
			return (NULL);
		buf[fd][0] = '\0';
	}
	line = ft_get_line(fd, buf[fd]);
	if (!line || (line[0] == '\0' && !ft_strlen(buf[fd])))
	{
		free(buf[fd]);
		buf[fd] = NULL;
		free(line);
		return (NULL);
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
