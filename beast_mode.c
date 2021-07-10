#include "push_swap.h"

stacks_t beast_mode(stacks_t main)
{
    chunk_t chunks;
    int *org;

    org = organize_array(main.stackA, main.sizeA - 1);
    get_attr_chunks(&chunks, main.sizeA, 11, org);
    print_stacks(main);
    main = pb(main);
    // main = start_loop(main, chunks);
    return (main);
}
