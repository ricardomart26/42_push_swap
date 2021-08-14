/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 02:19:58 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/12 02:20:01 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	moves_rb(t_moves *cmd)
{
	if (cmd->ra == cmd->rb)
	{
		cmd->rr = cmd->ra;
		cmd->ra = 0;
		cmd->rb = 0;
	}
	else if (cmd->ra > cmd->rb)
	{
		cmd->rr = cmd->rb;
		cmd->ra -= cmd->rb;
		cmd->rb = 0;
	}
	else if (cmd->ra < cmd->rb)
	{
		cmd->rr = cmd->ra;
		cmd->rb -= cmd->ra;
		cmd->ra = 0;
	}
}

void	moves_rrb(t_moves *cmd)
{
	if (cmd->rra == cmd->rrb)
	{
		cmd->rrr = cmd->rra;
		cmd->rra = 0;
		cmd->rrb = 0;
	}
	else if (cmd->rra > cmd->rrb)
	{
		cmd->rrr = cmd->rrb;
		cmd->rra -= cmd->rrb;
		cmd->rrb = 0;
	}
	else if (cmd->rra < cmd->rrb)
	{
		cmd->rrr = cmd->rra;
		cmd->rrb -= cmd->rra;
		cmd->rra = 0;
	}
}
