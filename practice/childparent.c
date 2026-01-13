#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int pid = fork();
	if(pid == 0){
	  	printf("I am child process of id: %d and my parent id : %d\n",getpid(),getppid());
	} else if(pid > 0){
	    printf("I am parent process of id: %d\n",getpid());
	} else{
	  	printf("Child process not created\n");
	}
}

