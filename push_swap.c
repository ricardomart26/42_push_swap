#include "push_swap.h"
/* Exprimentar com 0 no av  */

stacks_t peanuts(stacks_t main)
{
    chunk_t chunks;
    int *org;

    org = organize_array(main.stackA, main.sizeA - 1);
    get_attr_chunks(&chunks, main.sizeA, 2, org);
    print_stacks(main);
    main = pb(main);
    print_stacks(main);
    return (main);
}

stacks_t do_easy_one(stacks_t main)
{
    chunk_t chunks;
    int *org;

    org = organize_array(main.stackA, main.sizeA - 1);
    get_attr_chunks(&chunks, main.sizeA, 2, org);
    print_stacks(main);
    main = pb(main);
    print_stacks(main);
    main = start_loop(main, chunks);
    return (main);
}

stacks_t do_not_so_easy_one(stacks_t main)
{
    chunk_t chunks;
    int *org;
    org = organize_array(main.stackA, main.sizeA - 1);
    get_attr_chunks(&chunks, main.sizeA, 4, org);
    print_stacks(main);
    main = pb(main);
    print_stacks(main);
    main = start_loop(main, chunks);
    return (main);
}

stacks_t beast_mode(stacks_t main)
{
    chunk_t chunks;
    int *org;

    org = organize_array(main.stackA, main.sizeA - 1);
    get_attr_chunks(&chunks, main.sizeA, 11, org);
    print_stacks(main);
    main = pb(main);
    print_stacks(main);
    main = start_loop(main, chunks);
    return (main);
}

stacks_t    start_loop(stacks_t main, chunk_t chunks)
{
    
}