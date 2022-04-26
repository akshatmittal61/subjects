#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n;
    float wtavg, tatavg;
    printf(" Enter the number of processes: ");
    scanf("%d", &n);
    int p[n], bt[n], su[n], wt[n], ct[n], i, k, temp;
    for (i = 0; i < n; i++)
    {
        p[i] = i;
        printf(" Enter the Burst Time of Process %d: ", i);
        scanf("%d", &bt[i]);
        printf(" System/User Process (0/1) ? ");
        scanf("%d", &su[i]);
    }
    for (i = 0; i < n; i++)
        for (k = i + 1; k < n; k++)
            if (su[i] > su[k])
            {
                swap(&p[i], &p[k]);
                swap(&bt[i], &bt[k]);
                swap(&su[i], &su[k]);
            }
    wtavg = wt[0] = 0;
    int sy = 0, us = 0;
    for (i = 0; i < n; i++)
    {
        if (su[i] == 1)
            us++;
        else
            sy++;
    }
    int stwt = 0, scpt = 0;
    for (i = 0; i < sy; i++)
        for (k = i + 1; k < sy; k++)
            if (bt[i] > bt[k])
            {
                swap(&p[i], &p[k]);
                swap(&bt[i], &bt[k]);
                swap(&su[i], &su[k]);
            }
    for (i = sy; i < n; i++)
        for (k = i + 1; k < n; k++)
            if (p[i] > p[k])
            {
                swap(&p[i], &p[k]);
                swap(&bt[i], &bt[k]);
                swap(&su[i], &su[k]);
            }
    for (i = 0; i < n; i++)
    {
        wt[i] = stwt;
        ct[i] = stwt + bt[i];
        stwt += bt[i];
    }
    printf(" \n PROCESS\t\t SYSTEM/USER PROCESS \tBURST TIME\tWAITING TIME\tCOMPLETION TIME");
    for (i = 0; i < n; i++)
        printf(" \n %d \t\t %d \t\t\t %d \t\t %d \t\t %d", p[i], su[i], bt[i], wt[i], ct[i]);
    return 0;
}