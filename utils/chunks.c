#include "../push_swap.h"

void    get_attr_chunks(int **chunks, int sizeA, int *org)
{
    int i;

    *chunks = (int *)malloc(sizeof(int) * sizeA + 1);  
    i = 0;
    while (i < sizeA)
    {
        (*chunks)[i] = *org;
        i++;
        org++;
    }
    (*chunks)[i] = '\0';
}
