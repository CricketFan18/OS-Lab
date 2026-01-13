#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>  // Required for wait()

int main() {
    int pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process is running, PID: %d\n", getpid());
        sleep(2);  // Simulate some work
        printf("Child process is terminating.\n");
    } else {
        // Parent process
        wait(NULL);  // Parent waits for child to finish
        printf("Parent process detected that child has terminated.\n");
    }

    return 0;
}
