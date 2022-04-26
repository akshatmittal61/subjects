#include <stdio.h>
#include <stdlib.h>
int semaphore = 1;
int full = 0;
int empty = 10, x = 0;
void producer()
{
    --semaphore;
    ++full;
    --empty;
    x++;
    printf("\n Producer produces item %d", x);
    ++semaphore;
}
void consumer()
{
    --semaphore;
    --full;
    ++empty;
    printf("\n Consumer consumes item %d", x);
    x--;
    ++semaphore;
}
int main()
{
    int n, i;
    printf("\n 1. Press 1 for Producer");
    printf("\n 2. Press 2 for Consumer");
    printf("\n 3. Press 3 for Exit");
#pragma omp critical
    for (i = 1; i > 0; i++)
    {
        printf("\n Enter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if ((semaphore == 1) && (empty != 0))
                producer();
            else
                printf(" Buffer is full!");
            break;
        case 2:
            if ((semaphore == 1) && (full != 0))
                consumer();
            else
                printf(" Buffer is empty!");
            break;
        case 3:
            exit(0);
            break;
        }
    }
}