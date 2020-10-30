/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_last_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:02:55 by agardina          #+#    #+#             */
/*   Updated: 2020/03/30 19:02:50 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static int	sort_last_two(t_struct *ps)
{
	if (!check_order(ps->stack_a))
		apply_instr(ps, SA, 1);
	return (0);
}

int			sort_last_three(t_struct *ps)
{
	int tmp[3];

	if (stack_size(&ps->stack_a) != 3)
		return (sort_last_two(ps));
	tmp[0] = ps->stack_a.tab[ps->stack_a.begin];
	tmp[1] = ps->stack_a.tab[ps->stack_a.begin + 1];
	tmp[2] = ps->stack_a.tab[ps->stack_a.begin + 2];
	if (tmp[0] > tmp[1] && tmp[1] < tmp[2] && tmp[0] < tmp[2])
		apply_instr(ps, SA, 1);
	else if (tmp[0] > tmp[1] && tmp[1] > tmp[2] && tmp[0] > tmp[2])
	{
		apply_instr(ps, SA, 1);
		apply_instr(ps, RRA, 1);
	}
	else if (tmp[0] > tmp[1] && tmp[1] < tmp[2] && tmp[0] > tmp[2])
		apply_instr(ps, RA, 1);
	else if (tmp[0] < tmp[1] && tmp[1] > tmp[2] && tmp[0] < tmp[2])
	{
		apply_instr(ps, SA, 1);
		apply_instr(ps, RA, 1);
	}
	else if (tmp[0] < tmp[1] && tmp[1] > tmp[2] && tmp[0] > tmp[2])
		apply_instr(ps, RRA, 1);
	return (0);
}
