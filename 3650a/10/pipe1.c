#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void
check_rv(int rv)
{
    if (rv < 0) {
        perror("fail");
        exit(1);
    }
}

int
main(int _ac, char* _av[])
{
    int rv;
    char msg[] = "Hello, pipe.";

    int pipe_fds[2];
    rv = pipe(pipe_fds);
    printf("%d\n", rv);
    check_rv(rv);

    int p_read  = pipe_fds[0];
    int p_write = pipe_fds[1];

    rv = write(p_write, msg, strlen(msg));
    check_rv(rv);

    char temp[100];
    rv = read(p_read, temp, 99);
    printf("%d\n", rv);
    check_rv(rv);
    temp[rv] = 0;

    printf("%lu\n", strlen(temp));    
    printf("%s\n", temp);
    return 0;
}
