#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n, int t[])
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf(" %d", arr[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("\n Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burstTime[n], waitingTime[n], turnAroundTime[n], temp;
    float completeWaitingTime = 0, completeTurnAroundTime = 0;
    for (int i = 0; i < n; i++)
    {
        processes[i] = i;
        printf(" Enter burst time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }
    heapSort(burstTime, n, processes);
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