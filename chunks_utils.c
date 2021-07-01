#include "push_swap.h"

// int array_cmp(int *arr, int number)
// {
//     while (*arr)
//     {
//         if (*arr == number)
//             return (1);
//         arr++;
//     }
//     return (0);
// }

chunk_t *get_divisor_chunk(int *org, chunk_t *chunks, int divisor, int size)
{
    int counter2;
    int counter;
    int new_size;
    int counter3;

    counter2 = 0;
    counter3 = 0;
    new_size = size/2;
    while (counter2 < divisor)
    {
        counter = 0;
        while (counter < new_size)
        {
            chunks->chunks[counter2][counter] = org[counter3];
            counter++;
            counter3++;

        }
        chunks->chunks[counter2][counter] = '\0';
        printf("\n\t%d array\n", counter2 + 1);
        print_array(chunks->chunks[counter2], new_size);
        counter2++;
    }
    printf("\n\t\033[0;31mGET DIVISOR CHUNK IS DONE\033[0m");    

    return (chunks);
}

