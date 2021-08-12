#include "../push_swap.h"

void free_all_stacks_t(stacks_t *main)
{
    free(main->A);
    main->A = NULL;
    if (main->sizeB)
    {
        free(main->B);
        main->B = NULL;    
    }
        
}

void free_all_moves_t(moves_t *cmd)
{
    free(cmd);
    cmd = NULL;
}