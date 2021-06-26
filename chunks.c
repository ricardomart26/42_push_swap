#include "push_swap.h"

int do_chunk1(int *stackA, chunks_t *chunks, int lower_in_stack)
{
    int x;
    int size;
    int bigger;

    chunks->chunk1[0] = lower_in_stack;
    x = 1;
    size = chunks->size/4;
    while (size - 1)
    {
        // printf("size = %d\n", size);
        lower_in_stack = find_lower(stackA, lower_in_stack);
        chunks->chunk1[x] = lower_in_stack;
        x++; 
        size--;
    }
    bigger = chunks->chunk1[x - 1];
    return (bigger);
}



int do_chunk2(int *stackA, chunks_t *chunks, int bigger)
{
    int x;
    int size;
    int lower;

    x = 0;
    size = chunks->size/4;
    lower = bigger;
    while (size)
    {
        // printf("size = %d\n", size);
        lower = find_lower_limit(stackA, lower, bigger);
        chunks->chunk1[x] = lower;
        x++; 
        size--;

    }
    bigger = chunks->chunk1[x - 1];
    return (bigger);
}


int do_chunk3(int *stackA, chunks_t *chunks, int bigger)
{
    int x;
    int size;
    int lower;


    x = 0;
    size = chunks->size/4;
    while (size)
    {
        lower = find_lower_limit(stackA, lower, bigger);
        chunks->chunk1[x] = lower;
        x++; 
        size--;

    }
    bigger = chunks->chunk1[x - 1];
    return (bigger);
}

int do_chunk4(int *stackA, chunks_t *chunks, int bigger)
{
    int x;
    int size;
    int lower;


    x = 0;
    size = chunks->size/4;
    while (size)
    {
        lower = find_lower(stackA, lower);
        chunks->chunk1[x] = lower;
        x++;
        size--;
    }
    bigger = chunks->chunk1[x - 1];
    return (bigger);
}

void    get_attr_chunks(chunks_t *chunks, int sizeA)
{
    chunks->size = sizeA;
    chunks->chunk1 = malloc(chunks->size + 1);
    chunks->chunk2 = malloc(chunks->size + 1);
    chunks->chunk3 = malloc(chunks->size + 1);
    chunks->chunk4 = malloc(chunks->size + 1);
}