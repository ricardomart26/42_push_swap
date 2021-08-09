#include "../push_swap.h"

stacks_t combo_opt0(stacks_t main, int *chunks)
{
    moves_t cmd;

    init_cmd(&cmd);

    real_num1(&main, cmd, chunks);   
    real_num1(&main, cmd, chunks);

    return (main);    
}

stacks_t combo_opt1(stacks_t main, int *chunks)
{
    moves_t cmd;
    
    init_cmd(&cmd);

    real_num1(&main, cmd, chunks);    
    real_num2(&main, cmd, chunks);

    return (main);
}

stacks_t combo_opt2(stacks_t main, int *chunks)
{
    moves_t cmd;
    
    init_cmd(&cmd);
    
    real_num1(&main, cmd, chunks);
    real_num2(&main, cmd, chunks);

    return (main);
}

stacks_t combo_opt3(stacks_t main, int *chunks)
{
    moves_t cmd;

    init_cmd(&cmd);
    
    real_num2(&main, cmd, chunks);
    real_num2(&main, cmd, chunks);

    return (main);
}
