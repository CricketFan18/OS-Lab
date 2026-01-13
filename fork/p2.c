#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    int num=10;
    int pid = fork();
    if(pid==0) {
        printf("I am the Child Process\n");
        printf("Values in the child proces num=%d,pid=%d\n",num,pid);
        printf("Adresses in the Child Process num=%p , pid=%p\n",&num,&pid);
    } else if (pid>0) {
        printf("I am the Parent Process\n");
        printf("Values in the parent proces num=%d,pid=%d\n",num,pid);
        printf("Adresses in the parent Process num=%p , pid=%p\n",&num,&pid);
    } else {
        printf("Child creation unsuccesfull\n");
    }
    return 0;
}