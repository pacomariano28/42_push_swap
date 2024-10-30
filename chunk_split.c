/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:45:36 by frmarian          #+#    #+#             */
/*   Updated: 2024/09/27 12:29:09 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_split(t_stack *stack, t_chunk *to_split, t_split_dest *dest)
{
	int	pivot_1;
	int	pivot_2;
	int	max_value;
	int	next_value;

	pivot_1 = 0;
	pivot_2 = 0;
	dest->min.size = 0;
	dest->mid.size = 0;
	dest->max.size = 0;
	split_loc(to_split->loc, &dest->min, &dest->mid, &dest->max);
	set_pivots(to_split->loc, to_split->size, &pivot_1, &pivot_2);
	max_value = chunk_max_value(stack, to_split);
	while (to_split->size--)
	{
		next_value = chunk_value(stack, to_split, 1);
		if (next_value > max_value - pivot_2)
			dest->max.size += move_from_to(stack, to_split->loc, dest->max.loc);
		else if (next_value > max_value - pivot_1)
			dest->mid.size += move_from_to(stack, to_split->loc, dest->mid.loc);
		else
			dest->min.size += move_from_to(stack, to_split->loc, dest->min.loc);
	}
}

void	split_loc(enum e_loc loc, t_chunk *min, t_chunk *mid, t_chunk *max)
{
	if (loc == TOP_A)
	{
		max->loc = BOTTOM_A;
		mid->loc = TOP_B;
		min->loc = BOTTOM_B;
	}
	else if (loc == TOP_B)
	{
		max->loc = TOP_A;
		mid->loc = BOTTOM_A;
		min->loc = BOTTOM_B;
	}
	else if (loc == BOTTOM_A)
	{
		max->loc = TOP_A;
		mid->loc = TOP_B;
		min->loc = BOTTOM_B;
	}
	else if (loc == BOTTOM_B)
	{
		max->loc = TOP_A;
		mid->loc = BOTTOM_A;
		min->loc = TOP_B;
	}
}

void	set_pivots(enum e_loc loc, int crt_size, int *pvt_1, int *pvt_2)
{
	*pvt_2 = crt_size / 3;
	if (loc == TOP_A || loc == BOTTOM_A)
		*pvt_1 = 2 * crt_size / 3;
	if (loc == TOP_B || loc == BOTTOM_B)
		*pvt_1 = crt_size / 2;
}
