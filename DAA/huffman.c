#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct minHeapNode
{
    char data;
    unsigned freq;
    struct minHeapNode *left, *right;
};
struct minHeap
{
    unsigned size, capacity;
    struct minHeapNode **array;
};
struct minHeapNode *newNode(char data, unsigned freq)
{
    struct minHeapNode *temp = (struct minheapNode *)malloc(sizeof(struct minHeapNode));
    temp->left = temp->right = NULL;
};
int main()
{
    return 0;
}