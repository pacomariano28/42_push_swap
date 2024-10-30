/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:29:05 by frmarian          #+#    #+#             */
/*   Updated: 2024/09/27 12:31:05 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile *pile)
{
	int	tmp;

	if (pile->array[next_down(pile, pile->top)] == 0)
		return ;
	tmp = pile->array[pile->top];
	pile->array[pile->top] = pile->array[next_down(pile, pile->top)];
	pile->array[next_down(pile, pile->top)] = tmp;
}

void	swap_a(t_stack *stack)
{
	swap(&stack->a);
	ft_printf("sa\n");
}

void	swap_b(t_stack *stack)
{
	swap(&stack->b);
	ft_printf("sb\n");
}

void	swap_ab(t_stack *stack)
{
	swap(&stack->a);
	swap(&stack->b);
	ft_printf("ss\n");
}
