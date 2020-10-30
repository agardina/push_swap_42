/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:05:51 by agardina          #+#    #+#             */
/*   Updated: 2020/03/30 19:05:42 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	ft_init(t_struct *ps)
{
	ps->stack_a.tab = NULL;
	ps->stack_a.begin = 0;
	ps->stack_a.size = 0;
	ps->stack_b.tab = NULL;
	ps->stack_b.begin = 0;
	ps->stack_b.size = 0;
}

int		is_stack_empty(t_stack *stack)
{
	if (stack_size(stack) < 1)
		return (1);
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		get_max(t_stack stack)
{
	int max;
	int i;

	max = stack.tab[stack.begin];
	i = stack.begin + 1;
	while (i < stack.size)
	{
		if (stack.tab[i] > max)
			max = stack.tab[i];
		i++;
	}
	return (max);
}

int		get_min(t_stack stack)
{
	int min;
	int i;

	min = stack.tab[stack.begin];
	i = stack.begin + 1;
	while (i < stack.size)
	{
		if (stack.tab[i] < min)
			min = stack.tab[i];
		i++;
	}
	return (min);
}
