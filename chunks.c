#include "push_swap.h"

chunk_t *malloc_arrays(int size, int divisor, chunk_t *chunks)
{
    int i;

    i = -1;
    if (divisor < 2)
        perror("\n\t\033[0;31mO divisor tem de ser 2 ou 4 ou 11");
    else if (divisor == 2)
    {
        chunks->chunks = (int **)malloc((divisor * sizeof(int *)) + 1);
        while (i++ < divisor)
            chunks->chunks[i] = (int *)malloc((size/divisor * sizeof(int)) + 1);

    }
    else if (divisor == 4)
    {
        chunks->chunks = malloc((divisor * sizeof(int *)) + 1);
        while (i++ < divisor)
            chunks->chunks[i] = (int *)malloc((size/divisor * sizeof(int)) + 1);
    }
    else if (divisor == 11)
    {
        chunks->chunks = malloc((divisor * sizeof(int *)) + 1);
        while (i++ < divisor)
           chunks->chunks[i] = (int *)malloc((size/divisor * sizeof(int)) + 1);
    }   
    else
        perror("\n\t\033[0;31mO divisor tem de ser 2 ou 4 ou 11");
    printf("\n\n\tMalloc arrays DONE!");
    return (chunks);
}

void    get_attr_chunks(chunk_t *chunks, int sizeA, int divisor, int *org)
{
    chunks->size = sizeA;
    chunks->middle_in_stack = sizeA/2;
    // chunks->chunk2 = malloc((chunks->size/2 * 4) + 1);
    chunks = malloc_arrays(sizeA, divisor, chunks);
    chunks = get_divisor_chunk(org , chunks, divisor, sizeA);
}