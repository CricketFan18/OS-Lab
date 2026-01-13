#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void binary(int depth)
{
    if(depth==0) return;
    if(fork() == 0)
    {
        printf("Left Child id =%d, parent id=%d \n",getpid(),getppid());
        binary(depth-1);
    }
    else if(fork() == 0)
    {
        printf("Right Child id =%d, parent id=%d \n",getpid(),getppid());
        binary(depth-1);
    }
    else {
        wait(NULL);
        wait(NULL);
    }
}

int main()
{
    printf("Parent process id = %d\n",getpid());
    binary(2);    
}