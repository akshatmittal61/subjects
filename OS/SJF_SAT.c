#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main()
{
    int n;
    printf("\n Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burstTime[n], waitingTime[n], turnAroundTime[n];
    float completeWaitingTime = 0, completeTurnAroundTime = 0;

    for (int i = 0; i < n; i++)
    {
        processes[i] = i;
        printf("\n Enter burst time of process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            if (burstTime[i] > burstTime[k])
            {
                swap(&burstTime[i], &burstTime[k]);
                swap(&processes[i], &processes[k]);
            }
        }
    }

    waitingTime[0] = 0;
    turnAroundTime[0] = burstTime[0];

    for (int i = 1; i < n; i++)
    {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
        turnAroundTime[i] = turnAroundTime[i - 1] + burstTime[i];
        completeWaitingTime += waitingTime[i];
        completeTurnAroundTime += turnAroundTime[i];
    }

    printf("\n Process \t Burst Time \t Waiting Time \t Turnaround time\n");
    for (int i = 0; i < n; i++)
        printf(" P%d \t\t %d \t\t %d \t\t %d\n", processes[i], burstTime[i], waitingTime[i], turnAroundTime[i]);

    printf("\n Average Waiting time: %f\n", completeWaitingTime / n);
    printf("\n Average Turnaround time: %f\n", completeTurnAroundTime / n);
}