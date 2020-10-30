/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:06:02 by agardina          #+#    #+#             */
/*   Updated: 2020/03/30 19:05:54 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int		get_max_index(t_stack stack)
{
	int max;
	int max_index;
	int i;

	max = stack.tab[stack.begin];
	max_index = stack.begin;
	i = stack.begin + 1;
	while (i < stack.size)
	{
		if (stack.tab[i] > max)
		{
			max = stack.tab[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int		get_min_index(t_stack stack)
{
	int min;
	int min_index;
	int i;

	min = stack.tab[stack.begin];
	min_index = stack.begin;
	i = stack.begin + 1;
	while (i < stack.size)
	{
		if (stack.tab[i] < min)
		{
			min = stack.tab[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int		ft_free_and_return(t_struct *ps)
{
	if (ps->stack_a.tab)
	{
		free(ps->stack_a.tab);
		ps->stack_a.tab = NULL;
	}
	if (ps->stack_b.tab)
	{
		free(ps->stack_b.tab);
		ps->stack_b.tab = NULL;
	}
	return (0);
}

int		stack_size(t_stack *stack)
{
	return (stack->size - stack->begin);
}
