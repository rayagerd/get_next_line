/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerdzhi <rgerdzhi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:28:40 by rgerdzhi          #+#    #+#             */
/*   Updated: 2024/09/12 18:46:57 by rgerdzhi         ###   ########.fr       */
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
    new_line = malloc(strlen(line) + i + 1);
    if (!new_line)
        return NULL;
    strcpy(new_line, line);
    strncat(new_line, buf + *pos, i);
    free(line);
    *pos += i;
    if (*pos < len)
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
            *len = read(fd, buf, BUFFER_SIZE);
            if (*len <= 0)
                return (line);
        }
    }
    return (line);
}

char	*get_next_line(int fd)
{
    static char	buf[BUFFER_SIZE];
    static int	pos;
    static int	len;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    return (ft_get_line(fd, buf, &pos, &len));
}

/*
int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}*/
