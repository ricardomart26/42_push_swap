/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 11:34:58 by rimartin          #+#    #+#             */
/*   Updated: 2021/09/11 11:34:59 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct stacks_s
{
	int		mv[4];
	int		*a;
	int		*b;
	int		size_a;
	int		size_chunk;
	int		size_b;
	int		ac;
	int		lowest;
	int		lowest_pos;
	int		middle_size;
	int		*chunks;
	bool	alloc_chunks;
}				t_stacks;

typedef struct moves_s
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
	int	total;
	int	num;
	int	pos_b;
}				t_moves;

# define PB 1
# define PA 1

t_stacks	fuck_norm3(t_stacks stack);
t_stacks	check_stacka_real(t_stacks stack, int size);
int			check_stacka(t_stacks stack, int size);
void		free2(int **org, int **chunks);
void		*ft_calloc(size_t count, size_t size);
void		print_array(int *stack, int size);
void		print_stacks(t_stacks stack);
int			search_in_chunk(t_stacks temp, int *chunk, int sizeA);
int			see_if_is_equal(t_stacks stack, t_stacks temp, int value, int i);
t_stacks	last3_a(t_stacks stack);
void		organize4_a(t_stacks *stack);
t_moves		b_correct(t_stacks *stack, int size);
void		not_so_easy_one(t_stacks stack);
void		moves_rrb(t_moves *cmd);
void		moves_rb(t_moves *cmd);
t_moves		get_cmds(t_stacks stack, t_moves cmd, int size);
t_moves		place_to_put_nbr(t_stacks stack, t_moves cmd, int size);
int			num1(t_stacks **temp, t_moves cmd);
int			num2(t_stacks **temp, t_moves cmd);
int			num1_fake(t_stacks **temp, t_moves cmd);
int			num2_fake(t_stacks **temp, t_moves cmd);
void		free_all_stacks_t(t_stacks *stack, int sizeB);
int			check_four_opt(t_stacks stack, int *chunks);
int			check_two_opt(t_stacks stack, int *chunks);
t_stacks	do_opt(t_stacks stack, int *chunks, int option);
int			real_num2(t_stacks *temp, int *chunks);
int			real_num1(t_stacks *temp, int *chunks);
int			place_in_array(int *stack, int num);
int			is_lowest_array(int x, int *array, int size);
int			biggest_num(int *stack, int size);
t_stacks	combo_opt(t_stacks stack, int *chunks, int option);
void		error_mes(t_stacks *stack);
void		init_cmd(t_moves *cmd);
int			return_best_opt(t_stacks stack, t_stacks temp, int num_in_chunk);
int			simulate_num1(t_stacks *temp, int *chunks, int opt);
int			simulate_num2(t_stacks *temp, int *chunks, int opt);
t_stacks	gen_moves_fake(t_stacks stack, int option, int counter, int pb_pa);
t_stacks	gen_moves_real(t_stacks stack, int option, int counter, int pb_pa);
int			simulate_next_f(t_stacks temp, int *chunks, int moves);
int			simulate_next_s(t_stacks temp, int *chunks, int moves);
t_stacks	pass_stacks_to_temp(t_stacks stack);
t_stacks	pass_stacks_to_temp0(t_stacks stack);
t_stacks	pass_stacks_to_temp1(t_stacks stack);
t_stacks	pass_stacks_to_temp2(t_stacks stack);
t_stacks	do_only3(t_stacks stack);
int			how_many_moves(t_stacks temp, int *chunks, int i);
int			closer_to_beg(t_stacks m, int *c, int size, t_moves *cmd);
int			closer_to_end(t_stacks stack, int *chunk, t_moves *cmd);
void		do_easy_one(t_stacks stack);
t_stacks	push_chunk_to_b(t_stacks stack);
t_stacks	pa_funct(t_stacks stack, int opt);
t_stacks	pb_funct(t_stacks stack, int opt);
t_stacks	ra_funct(t_stacks stack, int option);
t_stacks	rb_funct(t_stacks stack, int option);
t_stacks	rr_funct(t_stacks stack, int opt);
t_stacks	rra_funct(t_stacks stack, int option);
t_stacks	rrb_funct(t_stacks stack, int option);
t_stacks	rrr_funct(t_stacks stack, int opt);
t_stacks	sa_funct(t_stacks stack, int option);
t_stacks	sb_funct(t_stacks stack, int option);
t_stacks	ss_funct(t_stacks stack);
int			ft_strlen(char *str);
long int	ft_atoi(char *str, t_stacks stack);
int			find(int number, int *arr);
int			*ft_swap(int *stack, int i);
int			ft_isntdigit(char c);
int			is_valid(t_stacks stack);
int			is_correct(int *stack, int size);
int			is_correct_b(int *B, int size);
void		init_struct(t_stacks *stack, int ac);
int			lowest_num(int *stack, int size);
void		attr_chunks(t_stacks *stack, int *org, int divisor);
int			*organize_array(int *stack, int size);
void		init_stacks_loop(t_stacks *stack, int *org);

#endif
