/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:00:40 by agardina          #+#    #+#             */
/*   Updated: 2020/05/13 18:05:06 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static int	get_ft_nb(int instr)
{
	if (instr <= 2)
		return (0);
	else if (instr <= 4)
		return (1);
	else if (instr <= 7)
		return (2);
	return (3);
}

int			apply_instr(t_struct *ps, int instr, char write_it)
{
	static void (*f[4])(t_struct *ps, int instr_nb, char write_it) = {&ft_s,
		&ft_p, &ft_r, &ft_rr};

	f[get_ft_nb(instr)](ps, instr, write_it);
	return (1);
}
