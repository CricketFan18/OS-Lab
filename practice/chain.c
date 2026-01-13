#include <stdio.h>
#include <unistd.h>

int main() {
    fork();  // Creates 1 child
    fork();  // Each process forks again, creating 4 processes total

    printf("Process PID: %d , PARENT ID = %d\n", getpid(),getppid());
    return 0;
}
