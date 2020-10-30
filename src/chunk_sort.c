/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:01:20 by agardina          #+#    #+#             */
/*   Updated: 2020/03/30 18:49:31 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static int		chunk_sort(t_struct *ps, t_chunk *ch, int nb)
{
	int rank_up;
	int rank_down;
	int rank_to_move;
	int instr;

	if ((rank_up = get_rank(ps->stack_a, *ch, 0)) < 0)
	{
		ch->chunk_min = ch->chunk_max + 1;
		ch->chunk_max = ch->chunk_min + ch->interval - 1;
		ch->chunk_nb++;
		if (ch->chunk_nb == nb && ch->chunk_max < ch->stack_max)
			ch->chunk_max = ch->stack_max;
		return (chunk_sort(ps, ch, nb));
	}
	rank_down = get_rank(ps->stack_a, *ch, 1);
	rank_to_move = (rank_up - ps->stack_a.begin < ps->stack_a.size
		- rank_down ? rank_up : rank_down);
	instr = (rank_to_move - ps->stack_a.begin < ps->stack_a.size
		- rank_to_move ? RA : RRA);
	ft_move_to_b(ps, rank_to_move, instr);
	return (0);
}

static void		init_chunk(t_struct *ps, t_chunk *ch, int nb)
{
	ch->stack_min = get_min(ps->stack_a);
	ch->stack_max = get_max(ps->stack_a);
	ch->chunk_min = ch->stack_min;
	ch->interval = (ch->stack_max - ch->stack_min) / nb;
	ch->chunk_max = ch->stack_min + ch->interval;
	ch->chunk_nb = 1;
}

void			chunk_sort_loop(t_struct *ps, int nb)
{
	t_chunk ch;

	init_chunk(ps, &ch, nb);
	while (ps->stack_a.begin < ps->stack_a.size)
		chunk_sort(ps, &ch, nb);
	while (!is_stack_empty(&ps->stack_b))
		ft_move_back_to_a(ps);
}
