/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:01:06 by agardina          #+#    #+#             */
/*   Updated: 2020/03/30 18:48:44 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	check_order(t_stack stack_a)
{
	int i;

	i = stack_a.begin;
	while (i < stack_a.size - 1)
	{
		if (stack_a.tab[i] < stack_a.tab[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
