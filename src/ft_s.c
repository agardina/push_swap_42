/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:04:19 by agardina          #+#    #+#             */
/*   Updated: 2020/03/30 19:04:00 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static void	apply_s(t_stack *stack)
{
	int tmp;

	if (1 <= stack->size - stack->begin)
	{
		tmp = stack->tab[stack->begin];
		stack->tab[stack->begin] = stack->tab[stack->begin + 1];
		stack->tab[stack->begin + 1] = tmp;
	}
}

void		ft_s(t_struct *ps, int instr_nb, char write_it)
{
	if (instr_nb == SA || instr_nb == SS)
		apply_s(&ps->stack_a);
	if (instr_nb == SB || instr_nb == SS)
		apply_s(&ps->stack_b);
	if (write_it)
	{
		if (instr_nb == SA)
			write(1, "sa\n", 3);
		else if (instr_nb == SB)
			write(1, "sb\n", 3);
		else if (instr_nb == SS)
			write(1, "ss\n", 3);
	}
}
