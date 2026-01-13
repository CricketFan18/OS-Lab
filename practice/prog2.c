#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main() {
    pid_t pid;
    int i;
    printf("Parent process: %d\n", getpid());
    for (i = 0; i < 2; i++) {
        pid = fork();
        if (pid == 0) {
            printf("Child process %d created by parent %d\n", getpid(), getppid());
            sleep(2);
            printf("Child process %d exiting\n", getpid());
            exit(0);
        } else if (pid < 0) {
            perror("Fork failed");
            exit(1);
        }
    }
    for (i = 0; i < 2; i++) {
        pid_t child_pid = wait(NULL);
        printf("Parent process %d: Child %d has finished\n", getpid(), child_pid);
    }
    printf("Parent process: All child processes have finished\n");
    return 0;
}
