#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>


static  char *append_line(char *line, char *buf, int *pos, int len)
{
    int i = 0;

    while (*pos + i < len && buf[*pos + i] != '\n')
        i++;
    char *new_line = malloc(strlen(line) + i + 1);
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

char    *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    static int  pos;
    static int  len;
    char        *line;


    line = malloc(1);
    if (!line)
        return NULL;
    line[0] = '\0';
    if (pos == 0)
    {
        len = read(fd, buf, BUFFER_SIZE);
        if (len <= 0)
        {
            free(line);
            return NULL;
        }
    }
    while (line && pos < len)
    {
        line = append_line(line, buf, &pos, len);
        if (pos == 0)
        {
            len = read(fd, buf, BUFFER_SIZE);
            if (len <= 0)
                return (line);
        }
    }
    return line;
}
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
}