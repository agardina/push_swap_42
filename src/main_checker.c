/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:04:34 by agardina          #+#    #+#             */
/*   Updated: 2020/03/30 19:04:44 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	main(int argc, char **argv)
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
	if (!(ps.stack_b.tab = (int*)malloc(sizeof(int) * ps.stack_a.size)))
		return (ft_free_and_return(&ps));
	ft_bzero(ps.stack_b.tab, ps.stack_a.size * sizeof(int));
	ps.stack_b.size = ps.stack_a.size;
	ps.stack_b.begin = ps.stack_b.size;
	if (!check_instr(&ps))
	{
		write(2, "Error\n", 6);
		return (ft_free_and_return(&ps));
	}
	if (check_order(ps.stack_a) && is_stack_empty(&ps.stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (ft_free_and_return(&ps));
}
