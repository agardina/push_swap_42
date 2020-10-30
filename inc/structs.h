/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:21:02 by agardina          #+#    #+#             */
/*   Updated: 2020/03/30 19:06:47 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H

# define STRUCTS_H

typedef struct	s_chunk
{
	int			stack_min;
	int			stack_max;
	int			chunk_min;
	int			chunk_max;
	int			interval;
	int			chunk_nb;
}				t_chunk;

typedef struct	s_stack
{
	int			*tab;
	int			begin;
	int			size;
}				t_stack;

typedef struct	s_struct
{
	t_stack		stack_a;
	t_stack		stack_b;
}				t_struct;

#endif
