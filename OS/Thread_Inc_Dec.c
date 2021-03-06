#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
sem_t semaphore1;
sem_t semaphore2;
void *inc(void *a)
{
    sem_init(&semaphore1, 0, 1);
    sem_wait(&semaphore1);
    printf("\n Thread 1 sleeps for 3 micro-seconds\n");
    sleep(3);
    int temp = (int *)a;
    temp++;
    printf("\n Value after incrementing is : %d\n", temp);
    sem_post(&semaphore1);
}
void *dec(void *a)
{
    sem_init(&semaphore2, 0, 1);
    sem_wait(&semaphore2);
    printf("\n Thread 2 sleeps for 4 micro-seconds\n");
    sleep(4);
    int temp = (int *)a;
    temp--;
    printf("\n Value after decrementing is : %d\n", temp);
    sem_post(&semaphore2);
}
int main()
{
    int a;
    printf(" Enter value of a: ");
    scanf("%d", &a);
    pthread_t increase;
    pthread_create(&increase, NULL, &inc, &a);
    pthread_t decrease;
    pthread_create(&decrease, NULL, &dec, &a);
    pthread_exit(NULL);
    return 0;
}