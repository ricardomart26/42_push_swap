#include "push_swap.h"

stacks_t *do_rotate_x_times(stacks_t *main, int times, int option)
{
    if (option == 0)
        while (times--)
            *main = rra(*main, 1);
    else if (option == 1)
        while (times--)
            *main = rrb(*main, 1);
    if (option == 2)
        while (times--)
            *main = ra(*main, 1);
    else if (option == 3)
        while (times--)
            *main = rb(*main, 1);
    *main = pb(*main);
    return(main);
}

stacks_t *combo1(stacks_t *main)
{
    int temp;
    int size = main->sizeB - 1;
    // printf("\n\n\t\t ENTERED IN COMBO 1");
    // sleep(1);
    temp = main->stackB[main->sizeB - 1];
    // printf("\n\t(combo1) main->stackA[0] %d\n", main->stackA[0]);
    // printf("\n\t(combo1) main->stackB[sizeB] %d\n", main->stackB[main->sizeB - 1]);
    while (main->stackA[0] > main->stackB[size])
    {
        size--;
        main->rrb_counter++;
    }
    // printf("combo1");
    // printf("\n\t(combo1) third pb\n");
    while (main->rrb_counter-- != 0 && main->rra_counter-- != 0)
        *main = rrr(*main);
    if (main->rra_counter == 0 && main->rrb_counter == 0)
        *main = pb(*main);
    else if (main->rra_counter != 0)
        main = do_rotate_x_times(main, main->rra_counter, 0);
    else if (main->rrb_counter != 0)
        main = do_rotate_x_times(main, main->rrb_counter, 1);
    while (main->stackB[main->sizeB - 1] != temp)
        *main = rb(*main, 1);
    return (main);
}

stacks_t *combo2(stacks_t *main)
{
    int temp;
    int i;

    i = 0;
    // printf("\n\n\t\t ENTERED IN COMBO 2");
    // sleep(1);
    // printf("\n\t(combo2) main->stackA[0] %d\n", main->stackA[0]);
    // printf("\n\t(combo2) main->stackB[sizeB] %d\n", main->stackB[main->sizeB - 1]);
	temp = main->stackB[main->sizeB - 1];
    while (main->stackA[0] < main->stackB[i++])
	{
		if (main->ra_counter != -1 && main->stackA[0] < main->stackB[i++])
        {
            main->ra_counter--;
			*main = rr(*main);
        }
		else
        	*main = rb(*main, 1);
	}
    if (main->ra_counter != -1)
        main = do_rotate_x_times(main, main->ra_counter, 4);
    *main = pb(*main);
    while (main->stackB[main->sizeB - 1] != temp)
        *main = rrb(*main, 1);
    // printf("\n\t(combo2 b) fourt pb\n");
    // printf("combo2");
    return (main);
}