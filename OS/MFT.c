#include <stdio.h>
int main()
{
    int ms, bs, nob, ef, n, mp[10], tif = 0, oop;
    int i, p = 0;
    printf("\n Enter the total memory available (in Bytes): ");
    scanf("%d", &ms);
    printf("\n Enter the block size (in Bytes): ");
    scanf("%d", &bs);
    nob = ms / bs;
    oop = ms - nob * bs;
    printf("\n Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf(" Enter memory required for process %d (in Bytes): ", i + 1);
        scanf("%d", &mp[i]);
    }
    printf("\n No. of Blocks available in memory: %d", nob);
    printf("\n\n PROCESS\tMEMORY REQUIRED\t ALLOCATED\tINTERNAL FRAGMENTATION");
    for (i = 0; i < n && p < nob; i++)
    {
        printf("\n  %d\t\t%d", i + 1, mp[i]);
        if (mp[i] > bs)
            printf("\t\t NO\t\t\t: ");
        else
        {
            printf("\t\t YES\t\t%d", bs - mp[i]);
            tif = tif + bs - mp[i];
            p++;
        }
    }
    ef = oop + tif;
    if (i < n)
        printf("\n Memory is Full, Remaining Processes cannot be accomodated");
    printf("\n\n Total Internal Fragmentation is %d", tif);
    printf("\n Total External Fragmentation is %d", ef);
    return 0;
}