#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
void fork_binary_tree(int depth) {
    if (depth == 0) return;
    if (fork() == 0) {
        printf("Process %d created by %d (Left Child)\n", getpid(), getppid());
        fork_binary_tree(depth - 1);
    } else if (fork() == 0) {
        printf("Process %d created by %d (Right Child)\n", getpid(), getppid());
        fork_binary_tree(depth - 1);
    } else {
        wait(NULL);
        wait(NULL);
    }
}
int main() {
    printf("Root process: %d\n", getpid());
    fork_binary_tree(2);
    return 0;
}
