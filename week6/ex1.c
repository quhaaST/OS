#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct Task {
    int arrivalTime;
    int burstTime;
    int processId;
    bool isFinished;
} typedef Task;

Task* create_task(int arrivalTime, int burstTime, int id) {
    Task* task = malloc(sizeof (Task*));
    task->arrivalTime = arrivalTime;
    task->burstTime = burstTime;
    task->processId = id;
    task->isFinished = false;
    return task;
}

void swap(Task* a, Task* b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_arrival_time(Task* list[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (list[i]->arrivalTime > list[j]->arrivalTime) {
                swap(list[i], list[j]);
            }
        }
    }
}

double get_average(int list[], int n) {
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        total += list[i];
    }
    return total / (n * 1.0);
}

int main() {
    int n, currentTime = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Task* list[n];
    int ct[n], tat[n], wt[n];
    for (int i = 0; i < n; i++) { // read the information about the processes
        int arrivalTime, burstTime;
        printf("Enter arrival time of process #%d: ", (i + 1));
        scanf("%d", &arrivalTime);
        printf("Enter burst time of process #%d: ", (i + 1));
        scanf("%d", &burstTime);
        list[i] = create_task(arrivalTime, burstTime, (i + 1));
    }
    sort_by_arrival_time(list, n); // to get the order of the execution

    for (int i = 0; i < n; i++) {
        if (currentTime < list[i]->arrivalTime) {
            currentTime = list[i]->arrivalTime;
        }
        wt[i] = currentTime - list[i]->arrivalTime;
        currentTime += list[i]->burstTime;
        ct[i] = currentTime;
        tat[i] = wt[i] + list[i]->burstTime;
        list[i]->isFinished = true;
    }

    for (int i = 0; i < n; i++) {
        printf("#%d: AT = %d, BT = %d, CT = %d, TAT = %d, WT = %d\n", list[i]->processId, list[i]->arrivalTime,
               list[i]->burstTime, ct[i], tat[i], wt[i]);
    }

    double avgTurnaround, avgWait;
    avgTurnaround = get_average(tat, n);
    avgWait = get_average(wt, n);

    printf("The average turnaround time is: %.3lf\n", avgTurnaround);
    printf("The average waiting time is: %.3lf\n", avgWait);

}
