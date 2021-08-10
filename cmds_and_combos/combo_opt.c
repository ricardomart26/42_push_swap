#include "../push_swap.h"

stacks_t combo_opt0(stacks_t main, int *chunks)
{
    real_num1(&main, chunks);   
    real_num1(&main, chunks);

    return (main);    
}

stacks_t combo_opt1(stacks_t main, int *chunks)
{
    real_num1(&main, chunks);    
    real_num2(&main, chunks);

    return (main);
}

stacks_t combo_opt2(stacks_t main, int *chunks)
{  
    real_num1(&main, chunks);
    real_num2(&main, chunks);

    return (main);
}

stacks_t combo_opt3(stacks_t main, int *chunks)
{
    real_num2(&main, chunks);
    real_num2(&main, chunks);

    return (main);
}
