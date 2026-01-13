#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    struct Process *next;
} Process;

void insertProcess(Process** head, int id , int arrival , int burst)
{
    Process *newProcess = (Process*)malloc(sizeof(Process));
    newProcess->pid = id;
    newProcess->arrival_time = arrival;
    newProcess->burst_time = burst;
    newProcess->remaining_time = burst;
    newProcess->completion_time=0;
    newProcess->next = NULL;

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

void freeMemory(Process* head)
{
    Process *free_temp = head;
    while (free_temp != NULL) {
        Process *next_temp = free_temp->next;
        free(free_temp);
        free_temp = next_temp;
    }
}

void sjf_preemptive(Process* head) {
    if (head == NULL) {
        return;
    }
    int current_time = 0;
    Process *completed_head = NULL;
    while (1) {
        Process *shortest = NULL;
        Process *prev_shortest = NULL;
        Process *temp = head;
        Process *prev_temp = NULL;
        while (temp != NULL) {
            if (temp->arrival_time <= current_time && temp->remaining_time > 0) {
                if (shortest == NULL || temp->remaining_time < shortest->remaining_time) {
                    shortest = temp;
                    prev_shortest = prev_temp;
                }
            }
            prev_temp = temp;
            temp = temp->next;
        }

        if (shortest == NULL) { 
            if (head == NULL){
                break;
            }
            current_time++;
            continue;
        }

        shortest->remaining_time--;
        current_time++;

        if (shortest->remaining_time == 0) {
            if (prev_shortest == NULL) {
                head = shortest->next;
            } else {
                prev_shortest->next = shortest->next;
            }

            shortest->completion_time = current_time;
            shortest->turnaround_time = shortest->completion_time - shortest->arrival_time;
            shortest->waiting_time = shortest->turnaround_time - shortest->burst_time;
            shortest->next = NULL;
            if (completed_head == NULL) {
                completed_head = shortest;
            } else {
                Process *temp2 = completed_head;
                while (temp2->next != NULL) {
                    temp2 = temp2->next;
                }
                temp2->next = shortest;
            }
        }
    }
    displayProcesses(completed_head);
    freeMemory(completed_head);      
}
int main() {
    Process* processList = NULL;
    insertProcess(&processList, 1, 0, 6);
    insertProcess(&processList, 2, 1, 2);
    insertProcess(&processList, 3, 2, 5);
    insertProcess(&processList, 4, 3, 4);
    sjf_preemptive(processList);   
    return 0;
}