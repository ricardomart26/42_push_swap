#include "../push_swap.h"

void free_all_stacks_t(stacks_t *main)
{
    free(main->stackA);
    main->stackA = NULL;
    if (main->sizeB)
    {
        free(main->stackB);
        main->stackB = NULL;    
    }
        
}

void free_all_moves_t(moves_t *cmd)
{
    free(cmd);
    cmd = NULL;
}