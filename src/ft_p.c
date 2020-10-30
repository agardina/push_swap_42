/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:03:22 by agardina          #+#    #+#             */
/*   Updated: 2020/03/30 19:03:06 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static void	apply_p(t_stack *dest, t_stack *source)
{
	if (source->size - source->begin > 0)
	{
		dest->begin--;
		dest->tab[dest->begin] = source->tab[source->begin];
		source->begin++;
	}
}

void		ft_p(t_struct *ps, int instr_nb, char write_it)
{
	if (instr_nb == PA)
	{
		apply_p(&ps->stack_a, &ps->stack_b);
		if (write_it)
			write(1, "pa\n", 3);
	}
	else
	{
		apply_p(&ps->stack_b, &ps->stack_a);
		if (write_it)
			write(1, "pb\n", 3);
	}
}
