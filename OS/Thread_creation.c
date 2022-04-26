#include <stdio.h>
#include <string.h>
#include <pthread.h>
int i = 3;
void *foo(void *p)
{
    printf(" Value recevied as argument in starting routine: ");
    printf("%i\n", *(int *)p);
    i++;
    pthread_exit(&i);
}
void *hoo(void *p)
{
    printf(" Value recevied as argument in starting routine: %i\n", *(int *)p);
    i--;
    pthread_exit(&i);
}
int main(void)
{
    pthread_t id1 = 1, id2 = 2;
    int j = 1, k = 2, *ptr1, *ptr2;
    pthread_create(&id1, NULL, foo, &j);
    pthread_join(id1, (void **)&ptr1);
    printf(" Value recevied by parent from child: %i\n", *ptr1);
    pthread_create(&id2, NULL, hoo, &k);
    pthread_join(id2, (void **)&ptr2);
    printf(" Value recevied by parent from child: %i\n", *ptr2);
    return 0;
}