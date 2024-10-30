/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:59:27 by frmarian          #+#    #+#             */
/*   Updated: 2024/09/27 12:30:51 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_pile *pile)
{
	if (is_full(pile))
	{
		pile->bottom = pile->top;
		pile->top = next_down(pile, pile->top);
	}
	else
	{
		pile->bottom = next_down(pile, pile->bottom);
		pile->array[pile->bottom] = pile->array[pile->top];
		pile->array[pile->top] = 0;
		pile->top = next_down(pile, pile->top);
	}
}

void	rotate_a(t_stack *stack)
{
	rotate(&stack->a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack *stack)
{
	rotate(&stack->b);
	ft_printf("rb\n");
}

void	rotate_ab(t_stack *stack)
{
	rotate(&stack->a);
	rotate(&stack->b);
	ft_printf("rr\n");
}
