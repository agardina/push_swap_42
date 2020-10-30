/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:03:49 by agardina          #+#    #+#             */
/*   Updated: 2020/03/30 19:03:21 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static void	apply_r(t_stack *stack)
{
	int i;
	int top;

	i = stack->begin;
	top = stack->tab[i];
	while (i < stack->size - 1)
	{
		stack->tab[i] = stack->tab[i + 1];
		stack->tab[i + 1] = top;
		i++;
	}
}

void		ft_r(t_struct *ps, int instr_nb, char write_it)
{
	if (ps->stack_a.size - 1 - ps->stack_a.begin > 0
		&& (instr_nb == RA || instr_nb == RR))
		apply_r(&ps->stack_a);
	if (ps->stack_b.size - 1 - ps->stack_b.begin > 0
		&& (instr_nb == RB || instr_nb == RR))
		apply_r(&ps->stack_b);
	if (write_it)
	{
		if (instr_nb == RA)
			write(1, "ra\n", 3);
		else if (instr_nb == RB)
			write(1, "rb\n", 3);
		else if (instr_nb == RR)
			write(1, "rr\n", 3);
	}
}
