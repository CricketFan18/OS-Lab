#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();  // Create a child process

    if (pid == 0) {
        printf("Child process is exiting, PID: %d\n", getpid());
    } else {
        sleep(10);  // Parent is sleeping for 10 seconds
        printf("Parent process with PID: %d\n", getpid());
    }

    return 0;
}
