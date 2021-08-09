#include "../push_swap.h"

// // stacks_t *do_rotate_x_times(stacks_t *main, int times, int option)
// // {
// //     if (option == 0)
// //         while (times--)
// //             *main = rra_funct(*main, 1);
// //     else if (option == 1)
// //         while (times--)
// //         {
// //             exit(0);
// //             *main = rrb_funct(*main, 1);
// //         }
// //     if (option == 2)
// //         while (times--)
// //             *main = ra_funct(*main, 1);
// //     else if (option == 3)
// //         while (times--)
// //             *main = rb_funct(*main, 1);
// //     *main = pb_funct(*main);
// //     return(main);
// // }

// stacks_t *combo1(stacks_t *main)
// {
//     int temp;
//     moves_t cmd;

//     int size = main->sizeB - 1;
//     // printf("\n\n\t\t ENTERED IN COMBO 1");
//     // sleep(1);
//     temp = main->stackB[main->sizeB - 1];
//     // printf("\n\t(combo1) main->stackA[0] %d\n", main->stackA[0]);
//     // printf("\n\t(combo1) main->stackB[sizeB] %d\n", main->stackB[main->sizeB - 1]);
//     while (main->stackA[0] > main->stackB[size])
//     {
//         size--;
//         cmd.rrb++;
//     }
//     // printf("combo1");
//     // printf("\n\t(combo1) third pb\n");
//     while (cmd.rrb-- != 0 && cmd.rra-- != 0)
//         *main = rrr_funct(*main);
//     if (cmd.rra == 0 && cmd.rrb == 0)
//         *main = pb_funct(*main);
//     else if (cmd.rra != 0)
//         main = do_rotate_x_times(main, cmd.rra, 0);
//     else if (cmd.rrb != 0)
//         main = do_rotate_x_times(main, cmd.rrb, 1);
//     while (main->stackB[main->sizeB - 1] != temp)
//         *main = rb_funct(*main, 1);
//     return (main);
// }

// stacks_t *combo2(stacks_t *main)
// {
//     int temp;
//     int i;
//     moves_t cmd;
//     i = 0;
//     // printf("\n\n\t\t ENTERED IN COMBO 2");
//     // sleep(1);
//     // printf("\n\t(combo2) main->stackA[0] %d\n", main->stackA[0]);
//     // printf("\n\t(combo2) main->stackB[sizeB] %d\n", main->stackB[main->sizeB - 1]);
// 	temp = main->stackB[main->sizeB - 1];
//     while (main->stackA[0] < main->stackB[i++])
// 	{
// 		if (cmd.ra != -1 && main->stackA[0] < main->stackB[i++])
//         {
//             cmd.ra--;
// 			*main = rr_funct(*main);
//         }
// 		else
//         	*main = rb_funct(*main, 1);
// 	}
//     if (cmd.ra != -1)
//         main = do_rotate_x_times(main, cmd.ra, 4);
//     *main = pb_funct(*main);
//     while (main->stackB[main->sizeB - 1] != temp)
//     {
//         exit(0);
//         *main = rrb_funct(*main, 1);
//     }
//     // printf("\n\t(combo2 b) fourt pb\n");
//     // printf("combo2");
//     return (main);
// }