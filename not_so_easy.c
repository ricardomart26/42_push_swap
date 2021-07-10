#include "push_swap.h"

stacks_t do_not_so_easy_one(stacks_t main)
{
    chunk_t chunks;
    int *org;
    org = organize_array(main.stackA, main.sizeA - 1);
    get_attr_chunks(&chunks, main.sizeA, 4, org);
    return (main);
}
