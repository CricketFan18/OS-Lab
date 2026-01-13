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

void scheduleSJF(Process** head) {
    if (*head == NULL) return;

    Process* sortedList = NULL;
    Process* temp = *head;
    int current_time = 0;

    while (temp != NULL) {
        Process* minBurstProcess = NULL;
        Process* prev = NULL;
        Process* minPrev = NULL;
        Process* iter = *head;
        while (iter != NULL) {
            if (iter->arrival_time <= current_time) {
                if (minBurstProcess == NULL || iter->burst_time < minBurstProcess->burst_time) {
                    minBurstProcess = iter;
                    minPrev = prev;
                }
            }
            prev = iter;
            iter = iter->next;
        }
        if (minBurstProcess == NULL) {
            current_time = temp->arrival_time;
            continue;
        }
        if (minPrev != NULL) {
            minPrev->next = minBurstProcess->next;
        } else {
            *head = minBurstProcess->next;
        }
        minBurstProcess->next = NULL;
        if (sortedList == NULL) {
            sortedList = minBurstProcess;
        } else {
            Process* last = sortedList;
            while (last->next != NULL) last = last->next;
            last->next = minBurstProcess;
        }
        current_time += minBurstProcess->burst_time;
        temp = *head;
    }

    *head = sortedList;
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
    insertProcess(&processList, 1, 0, 6);
    insertProcess(&processList, 2, 1, 2);
    insertProcess(&processList, 3, 2, 5);
    insertProcess(&processList, 4, 3, 4);

    scheduleSJF(&processList);
    calculateTimes(processList);
    displayProcesses(processList);

    return 0;
}
