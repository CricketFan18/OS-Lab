#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Process {
    int pid;
    int burst_time;
    int remaining_time;
    int arrival_time;
    int turnaround_time;
    int waiting_time;
    struct Process* next;
};

struct Process* createProcess(int pid, int burst_time, int arrival_time) {
    struct Process* newProcess = (struct Process*)malloc(sizeof(struct Process));
    newProcess->pid = pid;
    newProcess->burst_time = burst_time;
    newProcess->remaining_time = burst_time;
    newProcess->arrival_time = arrival_time;
    newProcess->turnaround_time = 0;
    newProcess->waiting_time = 0;
    newProcess->next = NULL;
    return newProcess;
}
void insertProcess(struct Process** head, int pid, int burst_time, int arrival_time) {
    struct Process* newProcess = createProcess(pid, burst_time, arrival_time);
    if (*head == NULL) {
        *head = newProcess;
        newProcess->next = *head;
    } else {
        struct Process* temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newProcess;
        newProcess->next = *head;
    }
}
void roundRobin(struct Process* head, int time_quantum, int n) {
    if (head == NULL) return;
    struct Process* queue[n];
    int front = 0, rear = 0;
    int time = 0, completed = 0;
    
    struct Process* temp = head;
    do {
        queue[rear++] = temp;
        temp = temp->next;
    } while (temp != head);

    printf("\nGantt Chart:\n");
    printf("------------------------------------------------\n");

    while (completed < n) {
        bool executed = false;
        for (int i = front; i < rear; i++) {
            struct Process* current = queue[i];
            if (current->remaining_time > 0 && current->arrival_time <= time) {
                executed = true;
                int exec_time = (current->remaining_time > time_quantum) ? time_quantum : current->remaining_time;
                printf("| P%d (%d-%d) ", current->pid, time, time + exec_time);
                time += exec_time;
                current->remaining_time -= exec_time;
                
                if (current->remaining_time == 0) {
                    current->turnaround_time = time - current->arrival_time;
                    current->waiting_time = current->turnaround_time - current->burst_time;
                    completed++;
                }
            }
        }
        if (!executed) time++;
    }
    printf("\nFinal Process Table:\n");
    printf("----------------------------------------------------------\n");
    printf("| PID | Arrival Time | Burst Time | Turnaround Time | Waiting Time |\n");
    printf("----------------------------------------------------------\n");
    temp = head;
    do {
        printf("| %3d | %12d | %10d | %15d | %12d |\n", temp->pid, temp->arrival_time, temp->burst_time, temp->turnaround_time, temp->waiting_time);
        temp = temp->next;
    } while (temp != head);
    printf("----------------------------------------------------------\n");
}

// Main function
int main() {
    struct Process* head = NULL;
    int n, time_quantum, burst_time, arrival_time;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        printf("Enter burst time and arrival time for process %d: ", i);
        scanf("%d %d", &burst_time, &arrival_time);
        insertProcess(&head, i, burst_time, arrival_time);
    }
    
    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);
    
    printf("\nRound Robin Execution:\n");
    roundRobin(head, time_quantum, n);
    
    return 0;
}