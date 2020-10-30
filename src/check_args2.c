/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:05:07 by agardina          #+#    #+#             */
/*   Updated: 2020/05/13 18:53:41 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static int	free_agregate_var(char **tmp)
{
	free(*tmp);
	*tmp = NULL;
	return (0);
}

static int	add_to_agregate(char **agregate, char *argv)
{
	char *tmp;

	if (!(*agregate = ft_strjoin(*agregate, " ")))
		return (0);
	tmp = *agregate;
	*agregate = ft_strjoin(*agregate, argv);
	free(tmp);
	if (!*agregate)
		return (0);
	return (1);
}

int			agregate_args(char **agregate, int argc, char **argv)
{
	int		i;
	char	*tmp;

	i = 1;
	while (i < argc)
	{
		tmp = *agregate;
		if (!*agregate)
		{
			if (!(*agregate = ft_strdup(argv[i])))
				return (free_agregate_var(&tmp));
		}
		else
		{
			if (!add_to_agregate(agregate, argv[i]))
				return (free_agregate_var(&tmp));
		}
		free(tmp);
		i++;
	}
	tmp = NULL;
	return (1);
}

int			free_agregate_split(char ***agregate_split)
{
	int i;

	if (!*agregate_split)
		return (0);
	i = 0;
	while ((*agregate_split)[i])
	{
		free((*agregate_split)[i]);
		(*agregate_split)[i] = NULL;
		i++;
	}
	free((*agregate_split)[i]);
	(*agregate_split)[i] = NULL;
	free(*agregate_split);
	*agregate_split = NULL;
	return (0);
}
