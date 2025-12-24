#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd;
    fd = open("board.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
    if (fd < 0)
    {
        perror(argv[2]);
        exit(1);
    }
    char *c = malloc(7 * sizeof(char));
    if (c == NULL)
    {
        perror("memory not allocated");
        exit(1);
    }
    strcpy(c, "123123");
    strcat(c, "9");
    write(fd, c, 7 * sizeof(char));
    close(fd);
    free(c);
    // test
    return 0;
}
