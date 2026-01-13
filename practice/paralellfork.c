#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before fork()\n");
    int pid = fork();

    if (pid == 0) {
        printf("Child process, PID: %d\n", getpid());
    } else if (pid > 0) {
        printf("Parent process, PID: %d\n", getpid());
    }

    printf("This will be printed by both parent and child!\n");

    return 0;
}
