/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:23:37 by frmarian          #+#    #+#             */
/*   Updated: 2024/09/27 12:28:53 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_stack *stack)
{
	t_chunk	chunk_all;

	chunk_all.loc = TOP_A;
	chunk_all.size = stack->a.size;
	rec_chunk_sort(stack, &chunk_all);
}

void	rec_chunk_sort(t_stack *stack, t_chunk *to_sort)
{
	t_split_dest	dest;

	chunk_to_the_top(stack, to_sort);
	if (to_sort->size < 3)
	{
		if (to_sort->size == 2)
			sort_two(stack, to_sort);
		else if (to_sort->size == 1)
			sort_one(stack, to_sort);
		return ;
	}
	chunk_split(stack, to_sort, &dest);
	rec_chunk_sort(stack, &dest.max);
	rec_chunk_sort(stack, &dest.mid);
	rec_chunk_sort(stack, &dest.min);
}

void	sort_two(t_stack *stack, t_chunk *to_sort)
{
	if (to_sort->loc == BOTTOM_A || to_sort->loc == BOTTOM_B
		|| to_sort->loc == TOP_B)
	{
		move_from_to(stack, to_sort->loc, TOP_A);
		move_from_to(stack, to_sort->loc, TOP_A);
	}
	if (value(&stack->a, 1) > value(&stack->a, 2))
		swap_a(stack);
	to_sort->size = to_sort->size - 2;
}

void	sort_one(t_stack *stack, t_chunk *to_sort)
{
	if (to_sort->loc == BOTTOM_A || to_sort->loc == BOTTOM_B
		|| to_sort->loc == TOP_B)
		move_from_to(stack, to_sort->loc, TOP_A);
	to_sort->size = to_sort->size - 1;
}
