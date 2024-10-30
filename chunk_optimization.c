/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_optimization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:22:31 by frmarian          #+#    #+#             */
/*   Updated: 2024/09/27 12:27:20 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_to_the_top(t_stack *stack, t_chunk *to_sort)
{
	if (to_sort->loc == BOTTOM_B && current_size(&stack->b) == to_sort->size)
		to_sort->loc = TOP_B;
	if (to_sort->loc == BOTTOM_A && current_size(&stack->a) == to_sort->size)
		to_sort->loc = TOP_A;
}
