#include <stdio.h>
int matrix[10][6];

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void arrangeArrival(int matrix[][6], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (matrix[j][1] > matrix[j + 1][1])
            {
                for (int k = 0; k < 5; k++)
                    swap(&matrix[j][k], &matrix[j + 1][k]);
            }
        }
    }
}
void completionTime(int matrix[][6], int n)
{
    int temp, value;
    matrix[0][3] = matrix[0][1] + matrix[0][2];
    matrix[0][5] = matrix[0][3] + matrix[0][1];
    matrix[0][4] = matrix[0][5] + matrix[0][2];
    for (int i = 0; i < n; i++)
    {
        temp = matrix[i - 1][3];
        int low = matrix[i][2];
        for (int j = 0; j < n; j++)
        {
            if (temp >= matrix[j][1] && low >= matrix[j][2])
            {
                low = matrix[j][2];
                value = j;
            }
        }
        matrix[value][3] = temp + matrix[value][2];
        matrix[value][5] = matrix[value][3] - matrix[value][1];
        matrix[value][4] = matrix[value][5] - matrix[value][2];
        for (int k = 0; k < 6; k++)
            swap(&matrix[value][k], &matrix[i][k]);
    }
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
        printf("\n Enter process id: ");
        scanf("%d", &matrix[i][0]);
        printf("\n Enter arrival time of process %d: ", i + 1);
        scanf("%d", &matrix[i][1]);
        printf("\n Enter burst time of process %d: ", i + 1);
        scanf("%d", &matrix[i][2]);
    }
 
    arrangeArrival(matrix, n);
    completionTime(matrix, n);
 
    printf("\n Process \t Arrival Time \t Burst Time \t Waiting Time \t Turnaround time\n");
    for (int i = 0; i < n; i++)
        printf(" %d \t\t %d \t\t %d \t\t %d \t\t %d\n", matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][4], matrix[i][5]);
}