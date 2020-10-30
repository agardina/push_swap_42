/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_values_by_rank.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 15:08:59 by agardina          #+#    #+#             */
/*   Updated: 2020/05/09 15:09:03 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	replace_values_by_rank(t_stack *stack)
{
	t_stack	rank;
	int		i;
	int		j;
	int		res;

	rank.begin = 0;
	rank.size = stack_size(stack);
	if (!(rank.tab = (int*)malloc(sizeof(int) * rank.size)))
		return (0);
	i = -1;
	while (++i < rank.size)
	{
		j = -1;
		res = 1;
		while (++j < rank.size)
			if (stack->tab[j] < stack->tab[i])
				res++;
		rank.tab[i] = res;
	}
	i = -1;
	while (++i < rank.size)
		stack->tab[i] = rank.tab[i];
	free(rank.tab);
	rank.tab = NULL;
	return (1);
}
