#include <stdio.h>
void main()
{
    int n;
    printf("\n Enter the number of processes: ");
    scanf("%d", &n);

    int burstTimes[n], waitingTime[n], turnAroundTimes[n];
    float completeWaitingTime = 0, completeTurnAroundTime = 0;

    for (int i = 0; i < n; i++)
    {
        printf(" Burst Time for process %d: ", i + 1);
        scanf("%d", &burstTimes[i]);
    }

    waitingTime[0] = 0;
    turnAroundTimes[0] = 0;

    for (int i = 0; i < n; i++)
    {
        waitingTime[i] = waitingTime[i - 1] + burstTimes[i - 1];
        turnAroundTimes[i] = turnAroundTimes[i - 1] + burstTimes[i - 1];
        completeWaitingTime += waitingTime[i];
        completeTurnAroundTime += turnAroundTimes[i];
    }

    printf("\n Process \t Burst Time \t Waiting Time \t Turnaround time\n");
    for (int i = 0; i < n; i++)
        printf(" P%d \t\t %d \t\t %d \t\t %d\n", i + 1, burstTimes[i], waitingTime[i], turnAroundTimes[i]);

    printf("\n Average Waiting time: %f\n", completeWaitingTime / n);
    printf("\n Average Turnaround time: %f\n", completeTurnAroundTime / n);
}