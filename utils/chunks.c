#include "../push_swap.h"

int    get_attr_chunks(int **chunks, int sizeA, int *org)
{
    int i;
    // printf("\n\tmiddle size %d\n", sizeA);
    *chunks = (int *)malloc(sizeof(int) * sizeA + 1);  
    i = 0;
    while (i < sizeA)
    {
        (*chunks)[i] = *org;
        i++;
        org++;
    }
    (*chunks)[i] = '\0';
    return (sizeA - 1);
}
