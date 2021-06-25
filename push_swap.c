#include "push_swap.h"

stacks_t do_easy_one(stacks_t main)
{
    print_stacks(main);
    main = pb(main);

    print_stacks(main);
    main = pb(main);
    print_stacks(main);
    main = pa(main);
    print_stacks(main);

    return (main);
}

stacks_t do_not_so_easy_one(stacks_t main)
{

    main = pb(main);
    return (main);
}

stacks_t beast_mode(stacks_t main)
{
    main = pb(main);
    return (main);
}
