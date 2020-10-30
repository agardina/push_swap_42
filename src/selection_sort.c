/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:05:38 by agardina          #+#    #+#             */
/*   Updated: 2020/03/30 19:05:29 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static void	selection_sort(t_struct *ps)
{
	int min;
	int min_index;
	int middle;
	int instr;

	min = get_min(ps->stack_a);
	min_index = get_min_index(ps->stack_a);
	middle = (ps->stack_a.size - ps->stack_a.begin) / 2 + ps->stack_a.begin;
	instr = (min_index <= middle ? RA : RRA);
	while (ps->stack_a.tab[ps->stack_a.begin] != min)
	{
		apply_instr(ps, instr, 1);
		if (check_order(ps->stack_a))
			return ;
	}
	if (!check_order(ps->stack_a))
		apply_instr(ps, PB, 1);
}

void		selection_sort_loop(t_struct *ps)
{
	while (stack_size(&ps->stack_a) > 3 && !check_order(ps->stack_a))
		selection_sort(ps);
	if (stack_size(&ps->stack_a) <= 3)
		sort_last_three(ps);
	while (!is_stack_empty(&ps->stack_b))
		apply_instr(ps, PA, 1);
}
