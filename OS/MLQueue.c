#include <stdio.h>
void swap(int *a, int *b)
{
    int *t;
    t = a;
    a = b;
    b = t;
}
int main()
{
    int n;
    float avgWaitTime, turnAroundTime;
    printf("\n Enter number of processess: ");
    scanf("%d", &n);
    int processes[n], burstTime[n], UserSystem[n], waitTime[n], completionTime[n];
    for (int i = 0; i < n; i++)
    {
        processes[i] = i;
        printf("\n Is it a system process or user process: (0-system, 1-user) ");
        scanf("%d", &UserSystem[i]);
        printf("\n Enter the burst time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (UserSystem[i] > UserSystem[j])
            {
                swap(&processes[i], &processes[j]);
                swap(&burstTime[i], &burstTime[j]);
                swap(&UserSystem[i], &UserSystem[j]);
            }
        }
    }
    avgWaitTime = waitTime[0] = 0;
    int sy = 0, us = 0;
    for (int i = 0; i < n; i++)
    {
        if (UserSystem[i] == 1)
            us++;
        else
            sy++;
    }
    int stwt = 0, scpt = 0;
    for (int i = 0; i < sy; i++)
    {
        for (int j = 0; j < sy; j++)
        {
            if (burstTime[i] > burstTime[j])
            {
                swap(&processes[i], &processes[j]);
                swap(&burstTime[i], &burstTime[j]);
                swap(&UserSystem[i], &UserSystem[j]);
            }
        }
    }
    for (int i = sy; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (processes[i] > processes[j])
            {
                swap(&processes[i], &processes[j]);
                swap(&burstTime[i], &burstTime[j]);
                swap(&UserSystem[i], &UserSystem[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        waitTime[i] = stwt;
        completionTime[i] = stwt + burstTime[i];
        stwt += burstTime[i];
    }
    printf("\n Process \t Process (system/user) \t\t Burst Time \t Waiting Time \t Completion Time ");
    for (int i = 0; i < n; i++)
    {
        printf("\n %d \t\t %s \t\t\t %d \t\t %d \t\t %d", processes[i], UserSystem[i] == 0 ? "system" : "user  ", burstTime[i], waitTime[i], completionTime[i]);
    }
    printf("\n Average waiting time: %f \n\n", avgWaitTime / n);
    return 0;
}