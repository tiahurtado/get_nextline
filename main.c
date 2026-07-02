#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    int fd;
    fd = open("42HelloWorld.txt", O_RDONLY);
    char *line;
    int i = 0;
    while (1)
    {
        line = get_next_line(fd);

        if (!line)
            break;

        printf("Loop number[%d] -> Result: %s\n", i, line);
        free(line);
        i++;
    }
}