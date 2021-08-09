#include "../push_swap.h"


// void    organize_stackB2(stacks_t *main)
// {
//     int i_in_stackb;
//     i_in_stackb = where_to_putnbr2(main->stackA[0], main->stackB, main->sizeB); // Ver onde tem que ir o primeiro numero
//     // printf("\n\n\t\t ENTERED IN ORGANIZED ");
//     // // print_stacks(*main);
//     // printf("\n\t(organize stack b) main->stackA[0] %d\n", main->stackA[0]);
//     // printf("\n\t(organize stack b) i_in_stack %d\n", i_in_stackb);
//     // printf("\n\t(organize stack b) main->sizeB %d\n", main->sizeB/2);
//     // printf("\n\t(organize stack b) i_in_stack %d\n", i_in_stackb);

//     if (i_in_stackb == 0)
//     {
//         printf("\n\t(organize stack b) first pb\n");
//         *main = pb_funct(*main);
//     }
//     else if (i_in_stackb == main->sizeB)
//     {
//         // printf("\n\t(organize stack b) second pb\n");
//         *main = pb_funct(*main);
//         *main = rb_funct(*main, 1);
//     }
//     else if (i_in_stackb >= main->sizeB/2) // Se o i for acima do meio
//         main = combo1(main);
//     else if (i_in_stackb <= main->sizeB/2)
//         main = combo2(main);
//     // printf("\n\t(organize stack b)");
//     // print_stacks(*main);
//     // sleep(1);
// }

// void	set_two_numbers(stacks_t *main, moves_t *cmd)
// {
//     int temp;

//     temp = main->stackA[cmd->num - 1];
//     cmd->rra = cmd->num;
//     printf("\n\t(push_to_beg_stackA2) temp = %d\n", temp);
//     temp = main->stackA[cmd->num - 1];
//     printf("\t(push_to_beg_stackA2) htemp = %d\n", temp);
//     cmd->ra = cmd->num;
// }


// SPECIAL CASES

   // int hig;
    // int rrb;

    // if ((*temp)->lowest == cmd.num)
    // {
    //     printf("\n\t(special cases) If lowest number to stackB\n");
    //     if (cmd.ra)
    //     {
    //         printf("\n\t(special cases) Before ra's %d\n", cmd.ra);
    //         print_stacks(**temp);
    //         sleep(4);
    //         **temp = gen_moves(**temp, 0, cmd.ra, 0);
    //         printf("\n\t(special cases) After ra's\n");
    //         print_stacks(**temp);
    //         sleep(4);
    //     }
    //     else if (cmd.rra)
    //     {
    //         printf("\n\t(special cases) Before rra's %d\n", cmd.rra);
    //         print_stacks(**temp);
    //         sleep(4);
    //         **temp = gen_moves(**temp, 1, cmd.rra, 0);
    //         printf("\n\t(special cases) After rra's\n");
    //         print_stacks(**temp);
    //         sleep(4);
    //     }


    //     hig = higgest_num((*temp)->stackB);
    //     rrb = (*temp)->sizeB - hig;
    //     if (hig >= (*temp)->sizeB / 2)
    //     {
    //         printf("\n\t(special cases) Before rrb's %d\n", cmd.rrb);
    //         print_stacks(**temp);
    //         sleep(4);
    //         **temp = gen_moves(**temp, 3, rrb, 0);
    //         printf("\n\t(special cases) After rrb's\n");
    //         print_stacks(**temp);
    //         sleep(4);
    //     }
    //     else if (hig <= (*temp)->sizeB / 2)
    //     {
    //         printf("\n\t(special cases) Before rb's %d hig %d\n", cmd.rb, hig);
    //         print_stacks(**temp);
    //         sleep(4);
    //         **temp = gen_moves(**temp, 2, hig, 0);
    //         printf("\n\t(special cases) After rb's\n");
    //         print_stacks(**temp);
    //         sleep(4);
    //     }
    // }
 


// moves_t best_way_to_put_nbr_in_stackB(stacks_t main, moves_t cmd)
// {
//     int i;
//     int x;
//     int size;

//     size = 0;
//     while (main.stackB[size] != NULL)
//         size++;    
//     x = 0;

//     while (cmd.num > main.stackB[size - 1])
//     {
//         size--;
//         x++;
//     }
//     i = 0;
//     if (x == 0)
//         while (cmd.num < main.stackB[i])
//             i++;
//     if (x)
//         cmd = set_b(cmd, 0, x);
//     else if (i)    
//         cmd = set_b(cmd, i, 0);
//     return (cmd);
// // }


// int where_to_putnbr(int x, int *stackB, int size)
// {
//     int i;

//     i = 0;
//     while (i < size)
//     {
//         while (x < stackB[i])
//             i++;
//         return (i);
//     }
//     return (0);
// }

// int find_closer_to_beginning(stacks_t main, int *chunk, int *hold_first, int size)
// {
//     int i;
//     int x;

//     i = 0;
//     while (size--)
//     {
//         x = 0;
//         while (main.stackA[i] != chunk[x] && x + 1 < main.middle_size)
//             x++;
//         if (x + 1 == main.middle_size)
//             i++;
//         else
//         {
//             *hold_first = i;
//             // printf("\n\t(find closer to beginning) stack[%d] %d\n", i, main.stackA[i]);
//             break;
//         }
//     }
//     if (size == 0)
//         return (-1);
//     return (1);
// }

// int find_closer_to_end(stacks_t main, int *chunk, int *hold_second)
// {
//     int size;
//     int x;

//     size = main.sizeA;
//     while (main.stackA[size - 1])
//     {
//         x = 0;
//         while (main.stackA[size - 1] != chunk[x] && x < main.middle_size)
//             x++;
//         if (x == main.middle_size)
//             size--;
//         else
//         {
//             *hold_second = x + 1;
//             // printf("\n\t(find closer to end) stack[%d] %d\n", size - 1, main.stackA[size - 1]);
//             return (size - 1);
//         }
//     }
//     return (-1);
// }

// void    organize_stackB(stacks_t *main)
// {
//     int i_in_stackb;
//     i_in_stackb = where_to_putnbr(main->stackA[0], main->stackB, main->sizeB); // Ver onde tem que ir o primeiro numero
//     // printf("\n\n\t\t ENTERED IN ORGANIZED ");
//     // // print_stacks(*main);
//     // printf("\n\t(organize stack b) main->stackA[0] %d\n", main->stackA[0]);
//     // printf("\n\t(organize stack b) i_in_stack %d\n", i_in_stackb);
//     // printf("\n\t(organize stack b) main->sizeB %d\n", main->sizeB/2);
//     // printf("\n\t(organize stack b) i_in_stack %d\n", i_in_stackb);

//     if (i_in_stackb == 0)
//     {
//         // printf("\n\t(organize stack b) first pb\n");
//         *main = pb_funct(*main);
//     }
//     else if (i_in_stackb == main->sizeB)
//     {
//         // printf("\n\t(organize stack b) second pb\n");
//         *main = pb_funct(*main);
//         *main = rb_funct(*main, 1);
//     }
//     else if (i_in_stackb >= main->sizeB/2) // Se o i for acima do meio
//         main = combo1(main);
//     else if (i_in_stackb <= main->sizeB/2)
//         main = combo2(main);
//     // printf("\n\t(organize stack b)");
//     // print_stacks(*main);
//     // sleep(1);
// }

// // ver tamanho do stackB, e em que index o numero deve ficar, e para que lado e mais rapido
// stacks_t push_chunk_to_b(stacks_t main, int *chunks)
// {
//     int hold_first; // Guardar primeiro numero dentro do stackB a partir do inicio dentro do chunk
//     int hold_second; // Guardar primeiro numero dento do stackB a partir do final dentro do chunk
//     int counter;
//     // printf("\n\tsizeB %d", main.sizeB);
//     // printf("\n\tmiddle size %d", main.middle_size);
//     counter = 0;
//     while (counter < main.middle_size - 1)
//     {
//         // printf("\n\t(push_chunk_to_b) sizeA %d\n", main.sizeA);
//         if ((!find_closer_to_beginning(main, chunks, &hold_first, main.sizeA)))
//             perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
//         if ((!find_closer_to_end(main, chunks, &hold_second)))
//             perror("\n\n\tCannot find chunk number in stackA\n"); // Encontrar primeiro numero dentro do stackA do final
//         // printf("\n\t(push_chunk_to_b) hold_first %d hold_second %d\n", hold_first, hold_second);
//         if (hold_first >= hold_second) // Se estiver mais perto do final fazer rra ate ao inicio
//             while (hold_second-- != 1)
//                 main = rra_funct(main, 1);
//         if (hold_first < hold_second) // Se estiver mais perto do incio fazer rra ate ao inicio
//             while (hold_first-- != 0)
//                 main = ra_funct(main, 1);
//         if (main.sizeB > 1)
//             organize_stackB(&main); // Ver qual maneira e mais facil de enviar o numero
//         else
//             main = pb_funct(main);
//         // print_stacks(main);
//         counter++;
//     }
//     return (main);
// }

// stacks_t do_easy_one(stacks_t main)
// {
//     int *chunks;
//     int *org;

//     // Fazer um while com estes dois para poder dividir função
//     // O middle size tem de ser updated
//     while (main.sizeA != 3) // Enquanto nao houver 3 numeros no stackA
//     {
//         org = organize_array(main.stackA, main.sizeA - 1); // Organizar o array
//         if (main.sizeA % 2 != 0) // ver se tamanho e par ou impar para saber onde esta o meio
//             main.middle_size = main.sizeA/2 + 1; // Se for impar, como a divisao arredonda para baixo, aumentar 1
//         else
//             main.middle_size = main.sizeA/2; // Se for par so e preciso dividir por 2
//         get_attr_chunks(&chunks, main.middle_size, org); // Receber a chunk1 e a chunk 2
//         main = push_chunk_to_b(main, chunks); // Empurrar a chunk para o stackB
//     }

//     return (main);
// }

// int do_rr_top(moves_t *cmd, stacks_t ***temp) // Dont know if it works
// {
//     if (cmd->rb == cmd->ra)
//     {
//         cmd = rr_sim(cmd, cmd->ra, 0, 0);
//         ***temp = gen_moves(***temp, 4, cmd->rr, 1);
//         return (cmd->total);
//     }
//     else if (cmd->rb > cmd->ra)
//     {
//         cmd = rr_sim(cmd, cmd->ra, cmd->rb -= cmd->ra, 0);
//         ***temp = gen_moves(***temp, 4, cmd->rr, 0);
//         ***temp = gen_moves(***temp, 2, cmd->rb, 1);
//         return (cmd->total);
//     }
//     else if (cmd->rb < cmd->ra)
//     {
//         cmd = rr_sim(cmd, cmd->rb, 0, cmd->ra -= cmd->rb);
//         ***temp = gen_moves(***temp, 4, cmd->rr, 0);
//         ***temp = gen_moves(***temp, 0, cmd->ra, 1);
//         return (cmd->total);
//     }
//     return (0);
// }

// int do_rrr_bottom(moves_t *cmd, stacks_t ***temp)
// {
//     if (cmd->rrb == cmd->rra)
//     {
//         cmd = rrr_sim(cmd, cmd->rra, 0, 0);
//         ***temp = gen_moves(***temp, 5, cmd->rrr, 1);
//         return (cmd->total);
//     }
//     else if (cmd->rrb > cmd->rra)
//     {
//         cmd = rrr_sim(cmd, cmd->rra, cmd->rrb -= cmd->rra, 0);
//         ***temp = gen_moves(***temp, 5, cmd->rrr, 0);
//         ***temp = gen_moves(***temp, 3, cmd->rrb, 1);
//         return (cmd->total);
//     }
//     else if (cmd->rrb < cmd->rra)
//     {
//         cmd = rrr_sim(cmd, cmd->rrb, 0, cmd->rra -= cmd->rrb);
//         ***temp = gen_moves(***temp, 5, cmd->rrr, 0);
//         ***temp = gen_moves(***temp, 1, cmd->rra, 1);
//         return (cmd->total);
//     }
//     return (0);
// }

// int move_down_the_stack(stacks_t **temp, int place, moves_t cmd)
// {
//     int size;

//     size = (*temp)->sizeB;
//     cmd.rrb = size - place;
//     if (cmd.ra)
//     {
//         **temp = gen_moves(**temp, 0, cmd.ra, 0);
//         **temp = gen_moves(**temp, 3, cmd.rrb, 1);
//         return (cmd.ra + cmd.rrb + pb);
//     }
//     else if (cmd.rra)
//         return (do_rrr_bottom(&cmd, &temp));
//     else
//     {
//         **temp = gen_moves(**temp, 3, cmd.rrb, 1);
//         return (cmd.rrb + pb);
//     }

// }

// int move_top_of_stack(stacks_t **temp, int place, moves_t cmd)
// {
//     cmd.rb = place;
//     if (cmd.num == 21)
//     {
//         printf("(move top of stack) rb %d\n", cmd.rb);
//         print_stacks(**temp);
//         sleep(3);
//     }
    
//     if (cmd.rra)
//     {
//         **temp = gen_moves(**temp, 1, cmd.rra, 0);
//         **temp = gen_moves(**temp, 2, cmd.rb, 1);
//         return (cmd.ra + cmd.rrb + pb);
//     }
//     else if (cmd.ra)
//         return (do_rr_top(&cmd, &temp));
//     else
//         **temp = gen_moves(**temp, 2, cmd.rb, 1);

//     return (cmd.rra + pb);
// }

// int special_cases(stacks_t **temp, moves_t cmd, int place)
// {
//     if (place == 0)
//     {
//         // if (cmd.num == 21)
//         // {
//             // print_stacks(**temp);
//             // sleep(5);
//             // exit(0);
//         // }
//         if (cmd.ra)
//             **temp = gen_moves(**temp, 0, cmd.ra, 1);
//         else if (cmd.rra)
//             **temp = gen_moves(**temp, 1, cmd.rra, 1);
//         else
//             **temp = gen_moves(**temp, 1, 0, 1);
//         return (cmd.ra + cmd.rra + pb);
//     }
//     else if (place == (*temp)->sizeB && cmd.num != (*temp)->lowest)
//     {
//         if ((*temp)->sizeB <= 1)
//         {
//             **temp = gen_moves(**temp, 0, cmd.ra, 0);
//             **temp = gen_moves(**temp, 1, cmd.rra, 1);
//             return (cmd.ra + cmd.rra + pb);
//         }
//         return (put_last(&temp, cmd));
//     }
//     return (0);
// }


// moves_t *set_cmd_num(moves_t *cmd, int i, int number, int *counter)
// {
//     cmd->ra = i;
//     cmd->rra = 0;
//     cmd->num[*counter] = number;
//     (*counter)++;
// }

// int sec_closer_to_beginning2(stacks_t *main, int *chunk, int size, moves_t *cmd)
// {
//     int i;
//     int x;
//     int counter;

//     counter = 0;
//     i = 0;
//     while (size--)
//     {
//         x = 0;
//         while (main->stackA[i] != chunk[x] && x + 1 < main->middle_size)
//             x++;
//         if (x + 1 == main->middle_size)
//             i++;
//         else
//             cmd = set_cmd_num(cmd, i, main->stackA[i], &counter);
//         printf("\n\t(find closer to beginning) stack[%d] %d\n", i, main->stackA[i]);
//         if (counter >= 2)
//             break;
//     }
//     if (size == 0)
//         return (-1);
//     return (1);
// }   

// int sec_closer_to_end2(stacks_t *main, int *chunk, moves_t *cmd)
// {
//     int size;
//     int x;

//     size = main->sizeA - 1;
//     // printf("\t(find closer to end) 1 stack[%d] %d\n", size, main->stackA[size]);
//     while (size)
//     {
//         x = 0;
//         // printf("\t(find closer to end) 2 stack[%d] %d\n", size, main->stackA[size]);
//         while (main->stackA[size] != chunk[x] && x < size)
//             x++;
//         // printf("\t(find closer to end) 69 x %d e size %d\n", x, size);
//         if (x == size)
//         {
//             size--;
//             // printf("\t(find closer to end) size diminui-o\n");
//         }
//         else
//         {
// 			cmd->rra = main->sizeA - size;
// 			cmd->ra = 0;
//             cmd->num[0] = main->stackA[size];
//             printf("\t(find closer to end) 3 stack[%d] %d\n", size, main->stackA[size]);
//             return (size);
//         }
//     }
//     return (-1);
// }s
