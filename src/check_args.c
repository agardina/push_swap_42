/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:05:07 by agardina          #+#    #+#             */
/*   Updated: 2020/05/13 18:05:22 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static int	split_args(char ***agregate_split, int argc, char **argv)
{
	char *agregate;

	agregate = NULL;
	if (!agregate_args(&agregate, argc, argv))
		return (0);
	if (!(*agregate_split = ft_split(agregate, " ")))
	{
		free(agregate);
		agregate = NULL;
		return (0);
	}
	free(agregate);
	agregate = NULL;
	return (1);
}

static int	check_args(char **agregate_split, t_struct *ps)
{
	int i;
	int nb_to_add;

	nb_to_add = 0;
	i = 0;
	while (agregate_split[i])
	{
		if (!check_line(ps, agregate_split[i], &nb_to_add))
		{
			free(ps->stack_a.tab);
			ps->stack_a.tab = NULL;
			return (0);
		}
		if (!ft_realloc(&ps->stack_a, nb_to_add))
		{
			free(ps->stack_a.tab);
			ps->stack_a.tab = NULL;
			return (0);
		}
		i++;
	}
	return (1);
}

int			check_line(t_struct *ps, char *arg, int *nb)
{
	int		i;
	char	*end;

	i = 0;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) ||
			((arg[i] == '-' || arg[i] == '+') && !i && ft_isdigit(arg[i + 1])))
			i++;
		else
			return (0);
	}
	end = NULL;
	*nb = ft_atol(arg, &end);
	if (!end)
		return (0);
	i = 0;
	while (i < ps->stack_a.size)
	{
		if (*nb != (ps->stack_a.tab)[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int			ft_realloc(t_stack *stack, int nb_to_add)
{
	int *tmp;
	int i;

	tmp = (int*)malloc(sizeof(int) * (stack->size + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (i < stack->size)
	{
		tmp[i] = stack->tab[i];
		i++;
	}
	tmp[i] = nb_to_add;
	if (stack->tab)
		free(stack->tab);
	stack->tab = tmp;
	stack->size++;
	return (1);
}

int			deal_args(int argc, char **argv, t_struct *ps)
{
	char **agregate_split;

	agregate_split = NULL;
	if (!split_args(&agregate_split, argc, argv))
		return (free_agregate_split(&agregate_split));
	if (!check_args(agregate_split, ps))
		return (free_agregate_split(&agregate_split));
	free_agregate_split(&agregate_split);
	return (1);
}
