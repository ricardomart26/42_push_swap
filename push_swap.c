#include "push_swap.h"

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

    return (main);
}

stacks_t do_not_so_easy_one(stacks_t main)
{

    main = pb(main);
    return (main);
}


chunks_t get_chunks(int *stackA, chunks_t chunks, int lower_in_stack)
{
    int bigger;
    bigger = do_chunk1(stackA, &chunks, lower_in_stack);
    bigger = do_chunk2(stackA, &chunks, bigger);
    bigger = do_chunk3(stackA, &chunks, bigger);
    bigger = do_chunk4(stackA, &chunks, bigger);
    
    return (chunks);
}

stacks_t beast_mode(stacks_t main)
{
    chunks_t chunks;
    get_attr_chunks(&chunks, main.sizeA);
    chunks = get_chunks(main.stackA, chunks, main.lower_in_stack);
    main = pb(main);
    return (main);
}
