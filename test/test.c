#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
main()
{
    if(fork() == 0)
    {
        printf("child process exit");
        exit(0);
    }

    printf("ok");
    wait(0);
}
