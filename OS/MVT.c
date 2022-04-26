#include <stdio.h>
int main()
{
    int ms, mp[10], i = 0, temp, n = 0;
    char ch = 'y';
    printf("\n Enter the total memory available (in Bytes): ");
    scanf("%d", &ms);
    temp = ms;
    while (ch == 'y')
    {
        printf("\n Enter memory required for process %d (in Bytes): ", i + 1);
        scanf("%d", &mp[i]);
        if (mp[i] <= temp)
        {
            printf("\n Memory is allocated for Process %d ", i + 1);
            temp = temp - mp[i];
        }
        else
        {
            printf("\n Memory is not available for the current request");
        }
        printf("\n Do you want to continue(y/n): ");
        scanf("%d", &temp);
        scanf("%c", &ch);
        i++;
        n++;
    }
    printf("\n\n Total Memory Available: %d", ms);
    printf("\n\n\t PROCESS\t\t MEMORY ALLOCATED ");
    for (i = 0; i < n; i++)
        printf("\n\t%d\t\t%d", i + 1, mp[i]);
    printf("\n\n Total Memory Allocated is %d", ms - temp);
    printf("\n Total External Fragmentation is %d\n", temp);
    return 0;
}