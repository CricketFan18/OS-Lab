#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void createChild(int num)
{
   for(int i=0;i<num;i++)
   {
    if(fork() == 0)
    {
        printf("Child id =%d of process id=%d\n",getpid(),getppid());
        return;
    }
   }

   for (int i = 0; i < num; i++) {
        wait(NULL);
    }

}

int main()
{
    printf("Parent process id = %d\n",getpid());
    createChild(5);    
}