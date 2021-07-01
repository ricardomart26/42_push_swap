#include "push_swap.h"

// int *do_chunks(int *stackA, chunk_t *chunks, int lower_in_stack, int divisor)
// {
//     int x;
//     int size;
//     int bigger;

//     *chunks->chunks[0] = lower_in_stack;
//     x = 1;
//     size = chunks->size/divisor;
//     while (size - 1)
//     {
//         // printf("size = %d\n", size);
//         lower_in_stack = find_lower(stackA, lower_in_stack);
//         *chunks->chunks[x] = lower_in_stack;
//         x++; 
//         size--;
//     }
//     bigger = *chunks->chunks[x - 1];
//     return (bigger);
// }



// int do_chunk2(int *stackA, chunk_t *chunks, int bigger, int divisor)
// {
//     int x;
//     int size;
//     int lower;

//     x = 0;
//     size = chunks->size/divisor;
//     lower = bigger;
//     while (size)
//     {
//         // printf("size = %d\n", size);
//         lower = find_lower_limit(stackA, lower, bigger);
//         *chunks->chunks[x] = lower;
//         x++; 
//         size--;

//     }
//     bigger = *chunks->chunks[x - 1];
//     return (bigger);
// }


// int do_chunk3(int *stackA, chunk_t *chunks, int bigger, int divisor)
// {
//     int x;
//     int size;
//     int lower;


//     x = 0;
//     size = chunks->size/divisor;
//     while (size)
//     {
//         lower = find_lower_limit(stackA, lower, bigger);
//         *chunks->chunks[x] = lower;
//         x++; 
//         size--;

//     }
//     bigger = *chunks->chunks[x - 1];
//     return (bigger);
// }

// int do_chunk4(int *stackA, chunk_t *chunks, int bigger, int divisor)
// {
//     int x;
//     int size;
//     int lower;


//     x = 0;
//     size = chunks->size/divisor;
//     while (size)
//     {
//         lower = find_lower(stackA, lower);
//         *chunks->chunks[x] = lower;
//         x++;
//         size--;
//     }
//     bigger = *chunks->chunks[x - 1];
//     return (bigger);
// }


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

// void    get_attr_chunks2(chunk_t *chunks, int sizeA)
// {
//     chunks->size = sizeA;
//     // chunks->chunk2 = malloc((chunks->size/2 * 4) + 1);
//     chunks = malloc_arrays(sizeA, 2, chunks);
// }


void    get_attr_chunks(chunk_t *chunks, int sizeA, int divisor)
{
    chunks->size = sizeA;
    chunks->middle_in_stack = sizeA/2;
    // chunks->chunk2 = malloc((chunks->size/2 * 4) + 1);
    chunks = malloc_arrays(sizeA, divisor, chunks);
}