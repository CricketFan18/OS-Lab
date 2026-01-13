#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>

void modify_message(char *msg, int level) {
    if (level == 1) {
        strcat(msg, " Vivek");
    } else if (level == 2) {
        strcat(msg, " 23053260");
    }
}

int main() {
    int pipe1[2], pipe2[2];
    pipe(pipe1);

    char buffer[100];
    pid_t pid1 = fork();

    if (pid1 == 0) {
        close(pipe1[1]);
        read(pipe1[0], buffer, sizeof(buffer));
        close(pipe1[0]);
        printf("%s\n", buffer);

        modify_message(buffer, 1);

        pipe(pipe2);
        pid_t pid2 = fork();

        if (pid2 == 0) {
            close(pipe2[1]);
            read(pipe2[0], buffer, sizeof(buffer));
            close(pipe2[0]);
            printf("%s\n", buffer);
            
            modify_message(buffer, 2);
            printf("%s\n", buffer);

            exit(0);
        } else {
            close(pipe2[0]);
            write(pipe2[1], buffer, strlen(buffer) + 1);
            close(pipe2[1]);
            wait(NULL);
            exit(0);
        }

    } else if (pid1 > 0) {
        close(pipe1[0]);
        write(pipe1[1], "Hello", strlen("Hello") + 1);
        close(pipe1[1]);
        wait(NULL);
    }

    return 0;
}
