#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid, wpid;
    int status;

    printf("%d:%d, program is starting\n", getpid(), gettid());

    pid = fork();
    if (pid == 0) {
        printf("%d:%d, child process after fork\n", getpid(), gettid());
        usleep(5 * 1000000);
        printf("%d:%d, child process is ready to _exit(2)\n", getpid(), gettid());
        _exit(2);
    }

    printf("%d:%d, parent process after fork\n", getpid(), gettid());
    printf("%d:%d, parent process waits for child process to terminate\n", getpid(), gettid());

    wpid  = waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
        printf("%d:%d, child pid %d exited with status %d\n", getpid(), gettid(), wpid, WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("%d:%d, child pid %d killed by signal %d\n", getpid(), gettid(), wpid, WTERMSIG(status));
    } else if (WIFSTOPPED(status)) {
        printf("%d:%d, child pid %d stopped by signal %d\n", getpid(), gettid(), wpid, WSTOPSIG(status));
    } else {
        printf("%d:%d, child pid %d state changed\n", getpid(), gettid(), wpid);
    }

    printf("%d:%d, parent process is ready to exit\n", getpid(), gettid());

    return 0;
}
