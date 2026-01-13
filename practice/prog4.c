#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void process_chain(int level, int max_level, char *message) {
    if (level > max_level) {
        printf("Level %d: Final Message: %s (PID: %d)\n", level - 1, message, getpid());
        return;
    }
    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (pid == 0) {
        char modified_message[256];
        sprintf(modified_message, "Level %d: %s (PID: %d)", level, message, getpid());
        process_chain(level + 1, max_level, modified_message);
        exit(0);
    } else {
        int status;
        wait(&status);
        printf("Level %d Parent: Child (PID: %d) finished. (Parent PID: %d)\n", level - 1, pid, getpid());
    }
}
int main() {
    int levels;
    printf("Enter number of levels( > 0 ): ");
    scanf("%d",&levels);
    char initial_message[256] = "Initial Message";
    process_chain(1, levels, initial_message);
    return 0;
}