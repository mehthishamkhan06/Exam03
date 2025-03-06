
#include "get_next_line.h"

char *get_next_line(int fd)
{
    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    char *line = malloc(70000);
    int bytes = read(fd, line, 70000);
    if (bytes == 0)
    {
        free(line);
        return (NULL);
    }
    line[bytes] = 0;
    return (line);
}