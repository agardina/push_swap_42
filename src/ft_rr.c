/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:04:03 by agardina          #+#    #+#             */
/*   Updated: 2020/03/30 19:03:37 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static void	apply_rr(t_stack *stack)
{
	int i;
	int bottom;

	i = stack->size - 1;
	bottom = stack->tab[i];
	while (stack->begin < i)
	{
		stack->tab[i] = stack->tab[i - 1];
		stack->tab[i - 1] = bottom;
		i--;
	}
}

void		ft_rr(t_struct *ps, int instr_nb, char write_it)
{
	if (ps->stack_a.size - 1 - ps->stack_a.begin > 0
		&& (instr_nb == RRA || instr_nb == RRR))
		apply_rr(&ps->stack_a);
	if (ps->stack_b.size - 1 - ps->stack_b.begin > 0
		&& (instr_nb == RRB || instr_nb == RRR))
		apply_rr(&ps->stack_b);
	if (write_it)
	{
		if (instr_nb == RRA)
			write(1, "rra\n", 4);
		else if (instr_nb == RRB)
			write(1, "rrb\n", 4);
		else if (instr_nb == RRR)
			write(1, "rrr\n", 4);
	}
}
