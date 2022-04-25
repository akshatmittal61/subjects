#include <stdio.h>

void findWaitingTime(int processes[], int n, int burstTime[], int waitingTime[], int arrivalTime[])
{
    int serviceTime[n];
    serviceTime[0] = arrivalTime[0];
    waitingTime[0] = 0;

    for (int i = 0; i < n; i++)
    {
        serviceTime[i] = serviceTime[i - 1] + burstTime[i - 1];
        waitingTime[i] = serviceTime[i] + arrivalTime[i];
        if (waitingTime[i] < 0)
            waitingTime[i] = 0;
    }
}

void findTurnAroundTime(int processes[], int n, int burstTime[], int waitingTime[], int turnAroundTime[])
{
    for (int i = 0; i < n; i++)
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
}

void findAvgTime(int processes[], int n, int burstTime[], int arrivalTime[])
{
    int waitingTime[n], turnAroundTime[n];
    findWaitingTime(processes, n, burstTime, waitingTime, arrivalTime);
    findTurnAroundTime(processes, n, burstTime, waitingTime, turnAroundTime);

    printf("\n Process \t Burst Time \t Arrival Time \t Waiting Time \t Turn Around Time \t Completion Time\n");
    float totalWaitingTime = 0, totalTurnAroundTime = 0;
    for (int i = 0; i < n; i++)
    {
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
        int completionTime = turnAroundTime[i] + arrivalTime[i];
        printf("\n %d \t\t %d \t\t %d \t\t %d \t\t %d \t\t\t %d", i + 1, burstTime[i], arrivalTime[i], waitingTime[i], turnAroundTime[i], completionTime);
    }
    printf("\n Average waiting time: %f\n", totalWaitingTime / n);
    printf("\n Average turn around time: %f\n", totalTurnAroundTime / n);
}

void main()
{
    int n;
    printf("\n Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burstTime[n], arrivalTime[n], waitingTime[n], turnAroundTime[n];
    float completeWaitingTime = 0, completeTurnAroundTime = 0;
    for (int i = 0; i < n; i++)
        processes[i] = i;

    for (int i = 0; i < n; i++)
    {
        printf(" Burst Time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        printf(" Arrival Time for process %d: ", i + 1);
        scanf("%d", &arrivalTime[i]);
    }
    findAvgTime(processes, n, burstTime, arrivalTime);
}