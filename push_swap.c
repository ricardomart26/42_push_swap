#include "push_swap.h"
/* Exprimentar com 0 no av  */

// int    is_lowest(int *middle_size, int *lowest_pos, int size, int *stackA)
// {
//     int i;
//     int x;
//     int lowest;

//     *middle_size = size/2;
//     i = 0;
//     x = 0;
//     // printf("size = %d\n", size);
//     while (x + i != size)
//     {
//         if (stackA[i] > stackA[i + x] && x + i != size)
//             i++;
//         else if (x + i != size)
//             x++;
//     }
//     lowest = stackA[i];
//     *lowest_pos = i;
//     printf("lowest = %d\n", lowest);
//     printf("lowest_pos = %d\n", *lowest_pos);
//     printf("middle_size = %d\n", *middle_size);
//     return (lowest);
// }


// void    push_chunk_to_b(stacks_t *main, int *chunk, int size, int divisor)
// {
//     while (main->sizeA/divisor != 0)
//     {
//         main->lowest = *chunk;
//         main->middle_size = main->sizeA/2;
//         main->lowest_pos = find(*chunk, main->stackA);
//         // printf("teste\n");
//         // if (main->stackA[0] > main->stackA[1])
//         //     *main = sa(*main, 1);
//         if (main->lowest_pos == 0)
//             *main = pb(*main);
//         else if (main->lowest_pos > main->middle_size && main->sizeA != 0)
//         {
//             while (main->lowest_pos++ != main->sizeA)
//                 *main = rra(*main, 1);
//             *main = pb(*main);
//         }
//         else if (main->lowest_pos <= main->middle_size && main->sizeA != 0)
//         {
//             while (main->lowest_pos-- != 0)
//                 *main = ra(*main, 1);
//             *main = pb(*main);
//         }
//         chunk++;
//         // print_stacks(*main);    
//     }
// }


// stacks_t    start_loop(stacks_t main, chunk_t chunks)
// {

// }