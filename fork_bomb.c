#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main ()
{
    pid_t pid = 0;

    while (1)
    {
        pid = fork();
        if (pid == -1)
        {
            puts("Oh no!");
            exit(EXIT_FAILURE);
        }
    }
}
