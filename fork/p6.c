#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main() {
    int fd[2];
    int n;
    char buffer[100];
    pid_t p;
    pipe(fd); //creates a unidirectional pipe with two end fd[O] and fd[l]
    p=fork();
    if(p>0)
    {
        printf("Parent Passing value to child\n");
        write(fd[1],"hello\n",6); //fd[ll is the write  end of the pipe
        wait(NULL);
    } else {
        printf("Child printing received value\n");
        n=read(fd[0],buffer,100);
        write(1,buffer,n);
    }   
}
