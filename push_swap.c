#include "push_swap.h"


chunk_t get_divisor_chunk(int *org, chunk_t chunks, int divisor, int size)
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
            chunks.chunks[counter2][counter] = org[counter3];
            counter++;
            counter3++;

        }
        chunks.chunks[counter2][counter] = '\0';
        printf("\n\t%d array\n", counter2 + 1);
        print_array(chunks.chunks[counter2], new_size);
        counter2++;
    }
    printf("\n\t\033[0;31mGET DIVISOR CHUNK IS DONE\033[0m");    

    return (chunks);
}
/* Exprimentar com 0 no av  */

stacks_t do_easy_one(stacks_t main)
{
    // print_stacks(main);
    // main = pb(main);
    // print_stacks(main);
    // main = pb(main);
    // print_stacks(main);
    // main = rr(main);
    // print_stacks(main);
    // main = rra(main, 1);
    // print_stacks(main);
    // main = rrb(main, 1);
    // print_stacks(main);
    chunk_t chunks;
    int *org;

    org = organize_array(main.stackA, main.sizeA - 1);
    get_attr_chunks(&chunks, main.sizeA, 2);
    chunks = get_divisor_chunk(org , chunks, 2, main.sizeA);
    print_stacks(main);
    main = pb(main);
    print_stacks(main);
    return (main);
}

stacks_t do_not_so_easy_one(stacks_t main)
{
    main = pb(main);
    return (main);
}

// chunk_t get_chunks(int *org, chunk_t chunks, int divisor)
// {
//     int i;
//     int x;

//     i = -1;
//     x = 0;
//     printf("\n\tchunk size = %d", chunks.size);
//     // while (i++ < divisor)
//         // *chunks.chunks[i] = get_half_chunk(org, &x, divisor);
    
//     return (chunks);
// }

// chunk_t get_chunks4(int *stackA, chunk_t chunks, int lower_in_stack)
// {
//     int bigger;
//     bigger = do_chunk1(stackA, &chunks, lower_in_stack, 4);
//     bigger = do_chunk2(stackA, &chunks, bigger, 4);
//     bigger = do_chunk3(stackA, &chunks, bigger, 4);
//     bigger = do_chunk4(stackA, &chunks, bigger, 4);
    
//     return (chunks);
// }

stacks_t beast_mode(stacks_t main)
{
    chunk_t chunks;
    int *org;

    org = organize_array(main.stackA, main.sizeA - 1);
    get_attr_chunks(&chunks, main.sizeA, 2);
    chunks = get_divisor_chunk(org , chunks, 2, main.sizeA);
    print_stacks(main);
    main = pb(main);
    print_stacks(main);

    return (main);
}
