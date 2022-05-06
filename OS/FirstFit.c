#include <stdio.h>
#define MAX 25
int main()
{
    printf("\n\n");
    int frag[MAX], b[MAX], f[MAX], i, j, nb, nf, temp, highest = 0;
    static int bf[MAX], ff[MAX];
    printf("\n \tMemory Management Scheme - Worst Fit");
    printf("\n Enter the number of blocks:");
    scanf("%d", &nb);
    printf("Enter the number of files:");
    scanf("%d", &nf);
    printf("\n Enter the size of the blocks:-\n");
    for (i = 1; i <= nb; i++)
    {
        printf(" Block %d:", i);
        scanf("%d", &b[i]);
    }
    printf(" Enter the size of the files :-\n");
    for (i = 1; i <= nf; i++)
    {
        printf(" File %d:", i);
        scanf("%d", &f[i]);
    }
    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                    if (highest < temp)
                    {
                        ff[i] = j;
                        highest = temp;
                    }
            }
        }
        frag[i] = highest;
        bf[ff[i]] = 1;
        highest = 0;
    }
    printf("\n File_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
    for (i = 1; i <= nf; i++)
        printf("\n %d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
    printf("\n\n");
    return 0;
}