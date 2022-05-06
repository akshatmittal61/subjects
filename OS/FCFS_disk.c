#include <stdio.h>
int main()
{
    int t[20], n, i, j, tohm[20], tot = 0;
    float avhm;
    printf("\n enter the no.of tracks");
    scanf("%d", &n);
    printf("\n enter initial head position");
    scanf("%d", &t[1]);
    printf("\n enter the tracks to be traversed");
    for (i = 2; i < n + 2; i++)
        scanf("%d", &t[i]);
    for (i = 1; i < n + 1; i++)
    {
        tohm[i] = t[i + 1] - t[i];
        if (tohm[i] < 0)
            tohm[i] = tohm[i] * (-1);
    }
    for (i = 1; i < n + 1; i++)
        tot += tohm[i];
    avhm = (float)tot / n;
    printf("\n Tracks traversed\tDifference between tracks\n");
    for (i = 1; i < n + 1; i++)
        printf("%d\t\t\t %d\n", t[i], tohm[i]);
    printf("\n Average header movements: %f ", avhm);
    return 0;
}