/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:04:49 by agardina          #+#    #+#             */
/*   Updated: 2020/03/30 19:05:00 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static void	find_instr(t_struct *ps)
{
	if (stack_size(&ps->stack_a) <= 20)
		selection_sort_loop(ps);
	else if (ps->stack_a.size <= 100)
		chunk_sort_loop(ps, 5);
	else if (ps->stack_a.size <= 200)
		chunk_sort_loop(ps, 7);
	else if (ps->stack_a.size <= 300)
		chunk_sort_loop(ps, 9);
	else if (ps->stack_a.size <= 400)
		chunk_sort_loop(ps, 10);
	else
		chunk_sort_loop(ps, 11);
}

int			main(int argc, char **argv)
{
	t_struct	ps;

	if (argc == 1)
		return (0);
	ft_init(&ps);
	if (!deal_args(argc, argv, &ps))
	{
		write(2, "Error\n", 6);
		return (ft_free_and_return(&ps));
	}
	if (!replace_values_by_rank(&ps.stack_a))
		return (ft_free_and_return(&ps));
	if (!(ps.stack_b.tab = (int*)malloc(sizeof(int) * ps.stack_a.size)))
		return (ft_free_and_return(&ps));
	ft_bzero(ps.stack_b.tab, ps.stack_a.size * sizeof(int));
	ps.stack_b.size = ps.stack_a.size;
	ps.stack_b.begin = ps.stack_b.size;
	if (!check_order(ps.stack_a))
		find_instr(&ps);
	ft_free_and_return(&ps);
	return (0);
}
