#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct
{
    char dname[10], fname[10][10];
    int fcnt;
} dir[10];

int main()
{
    int i, ch, dcnt, k;
    char f[30], d[30];
    dcnt = 0;
    while (1)
    {
        printf("\n\t 1.Create Directory");
        printf("\n\t 2.Create File");
        printf("\n\t 3.Delete File");
        printf("\n\t 4.Search File");
        printf("\n\t 5.Display");
        printf("\n\t 6.Exit");
        printf("\n\t Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter name of directory: ");
            scanf("%s", dir[dcnt].dname);
            dir[dcnt].fcnt = 0;
            dcnt++;
            printf(" Directory created ");
            break;
        case 2:
            printf("\n Enter name of the directory: ");
            scanf("%s", d);
            for (i = 0; i < dcnt; i++)
                if (strcmp(d, dir[i].dname) == 0)
                {
                    printf(" Enter name of the file: ");
                    scanf("%s", dir[i].fname[dir[i].fcnt]);
                    dir[i].fcnt++;
                    printf(" File created ");
                    break;
                }
            if (i == dcnt)
                printf(" Directory %s not found ", d);
            break;
        case 3:
            printf("\n Enter name of the directory: ");

            scanf("%s", d);
            for (i = 0; i < dcnt; i++)
            {
                if (strcmp(d, dir[i].dname) == 0)
                {
                    printf(" Enter name of the file: ");
                    scanf("%s", f);
                    for (k = 0; k < dir[i].fcnt; k++)
                    {
                        if (strcmp(f, dir[i].fname[k]) == 0)
                        {
                            printf(" File %s is deleted ", f);
                            dir[i].fcnt--;
                            strcpy(dir[i].fname[k], dir[i].fname[dir[i].fcnt]);
                            goto jmp;
                        }
                    }
                    printf(" File %s not found ", f);
                    goto jmp;
                }
            }
            printf(" Directory %s not found ", d);
        jmp:
            break;
        case 4:
            printf("\n Enter name of the directory: ");
            scanf("%s", d);
            for (i = 0; i < dcnt; i++)
            {
                if (strcmp(d, dir[i].dname) == 0)
                {
                    printf(" Enter the name of the file: ");
                    scanf("%s", f);
                    for (k = 0; k < dir[i].fcnt; k++)
                    {
                        if (strcmp(f, dir[i].fname[k]) == 0)
                        {
                            printf(" File %s is found ", f);
                            goto jmp1;
                        }
                    }
                    printf(" File %s not found ", f);
                    goto jmp1;
                }
            }
            printf(" Directory %s not found ", d);
        jmp1:
            break;
        case 5:
            if (dcnt == 0)
                printf("\n No Directory &#39; s ");
            else
            {
                printf("\n Directory\tFiles ");
                for (i = 0; i < dcnt; i++)
                {
                    printf("\n %s\t\t ", dir[i].dname);
                    for (k = 0; k < dir[i].fcnt; k++)
                        printf("\t %s ", dir[i].fname[k]);
                }
            }
            break;
        default:
            exit(0);
        }
    }
    return 0;
}