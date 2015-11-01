#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    printf("%d:%d, program is starting\n", getpid(), gettid());

    pid = fork();
    if (pid == 0) {
        printf("%d:%d, child process after fork\n", getpid(), gettid());
        printf("%d:%d, child process is ready to _exit(2)\n", getpid(), gettid());
        _exit(2);
    }

    printf("%d:%d, parent process after fork\n", getpid(), gettid());
    while (1) {
        //printf("%d:%d, parent process is looping\n", getpid(), gettid());
        usleep(1000000);
    }

    return 0;
}
