#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
void fork_star_tree(int num_children) {
    for (int i = 0; i < num_children; i++) {
        if (fork() == 0) {
            printf("Child process %d created by %d\n", getpid(), getppid());
            return;
        }
    }
    for (int i = 0; i < num_children; i++) {
        wait(NULL);
    }
}

int main() {
    printf("Root process: %d\n", getpid());
    fork_star_tree(4);
    return 0;
}
