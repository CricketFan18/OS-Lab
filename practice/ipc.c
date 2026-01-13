#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
#include<string.h>

int main()
{
    int pipefd[2];
    char buffer[20];
    pipe(pipefd);

    pid_t pid = fork();
    if(pid==0)
    {
        close(pipefd[1]);
        read(pipefd[0],buffer,sizeof(buffer));
        printf("Child recieved message: %s\n",buffer);
    } 
    else if (pid > 0)
    {
        close(pipefd[0]);
        write(pipefd[1],"Hello",strlen("Hello"));
    }
    else {
        printf("Creation of child process failed\n");
    }
    printf("Execution done\n");
}