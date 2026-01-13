#include<stdio.h>
#include<stdlib.h>

typedef struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    struct process* next;
}Process;

void insertProcess(Process** head, int id , int arrival , int burst)
{
    Process *newProcess = (Process*)malloc(sizeof(Process));
    newProcess->pid = id;
    newProcess->arrival_time = arrival;
    newProcess->burst_time = burst;

    if(*head == NULL || (*head)->arrival_time > arrival)
    {
        newProcess->next = (*head);
        *head = newProcess;
        return;
    }

    Process* temp = *head;
    while(temp->next != NULL && temp->next->arrival_time <= arrival )   temp = temp->next;

    newProcess->next = temp->next;
    temp->next = newProcess;
}
 
void calculateTimes(Process* head) {
    if (head == NULL) return;

    int current_time = 0;
    Process* temp = head;

    while (temp != NULL) {
        if (current_time < temp->arrival_time)
            current_time = temp->arrival_time;

        temp->waiting_time = current_time - temp->arrival_time;
        temp->turnaround_time = temp->waiting_time + temp->burst_time;
        current_time += temp->burst_time;
        
        temp = temp->next;
    }
}

void displayProcesses(Process* head) {
    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    Process* temp = head;
    while (temp != NULL) {
        printf("%d\t%d\t%d\t%d\t%d\n", 
               temp->pid, temp->arrival_time, 
               temp->burst_time, temp->waiting_time, 
               temp->turnaround_time);
        temp = temp->next;
    }
}

int main() {
    Process* processList = NULL;
    insertProcess(&processList, 1, 0, 3);
    insertProcess(&processList, 2, 1, 2);
    insertProcess(&processList, 3, 2, 6);
    insertProcess(&processList, 4, 3, 4);

    calculateTimes(processList);
    displayProcesses(processList);

    return 0;
}
