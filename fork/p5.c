#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main() {
    for(int i=0;i<2;i++)
    {
        fork();
        printf("hello inside loop%d\n",i);
    }
    printf("Hello\n");

}