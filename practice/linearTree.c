#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
void fork_linear_tree(int n) {
    if (n == 0) return;
    if (fork() == 0) {
        printf("Process %d created by %d\n", getpid(), getppid());
        fork_linear_tree(n - 1); 
    } else {
        wait(NULL);
    }
}
int main() {
    printf("Root process: %d\n", getpid());
    fork_linear_tree(3);
    return 0;
}
