#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void linearprocess(int depth)
{
    if(depth<=0) return;
    pid_t pid = fork();
    if(pid == 0)
    {
        printf("Child id =%d, parent id=%d \n",getpid(),getppid());
        linearprocess(depth-1);
    }
    else if(pid > 0)
    {
        wait(NULL);
    }
}

int main()
{
    printf("Parent process id = %d\n",getpid());
    linearprocess(2);    
}