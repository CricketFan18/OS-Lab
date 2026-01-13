#include<stdio.h>
#include<stdbool.h>

int main()
{
    int process,resources;
    printf("Enter the number of process : ");
    scanf("%d",&process);
    printf("Enter the number of resources : ");
    scanf("%d",&resources);
    int ALLOCATION[process][resources];
    int REQUEST[process][resources];
    int available[resources];
    printf("Enter the values for ALLOCATION MATRIX - \n");
    for(int i=0;i<process;i++)
    {
        printf("For process P%d : ",i);
        for(int j=0;j<resources;j++)
        {
            scanf("%d",&ALLOCATION[i][j]);
        }
    }
    printf("Enter the values for REQUEST MATRIX - \n");
    for(int i=0;i<process;i++)
    {
        printf("For process P%d : ",i);
        for(int j=0;j<resources;j++)
        {
            scanf("%d",&REQUEST[i][j]);
        }
    }
    printf("Enter the values for AVAILABLE VECTOR - \n");
    for(int i=0;i<resources;i++)
    {
        scanf("%d",&available[i]);
    }
    int work[resources];
    bool finish[process];
    for(int i=0;i<resources;i++)
    {
        work[i]=available[i];
    }
    for(int i=0;i<process;i++)
    {
        finish[i]=false;
    }

    while(true)
    {
        bool progressMade = false;
        for(int i=0;i<process;i++)
        {
            if(finish[i] == false)
            {
                bool canComplete = true;
                for(int j=0;j<resources;j++)
                {
                    if(REQUEST[i][j] > work[j])
                    {
                        canComplete = false;
                        break;
                    }
                }
                if(canComplete)
                {
                    progressMade = true;
                    finish[i] = true;
                    for(int j=0;j<resources;j++)
                    {
                        work[j]+=ALLOCATION[i][j];
                    }
                }
            }
        }
        if (!progressMade) 
            break;
    }

    bool deadlockExists = false;
    for(int i=0;i<process;i++)
    {
        if(finish[i] == false)
        {
            deadlockExists = true;
        }
    }

    if(deadlockExists)
        printf("DeadLock exists");
    else    
        printf("DeadLock does not exists");
}