#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    for (int i = 0; i < 3; i++) {
        if (fork() == 0) {
            printf("Child %d, PID: %d is running.\n", i + 1, getpid());
            sleep(2);
            printf("Child %d terminating.\n", i + 1);
            return 0;
        }
    }

    // Parent waits for all children
    while (wait(NULL) > 0) {
        printf("A child has terminated.\n");
    }

    printf("All child processes have terminated.\n");
    return 0;
}
