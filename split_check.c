/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:20:06 by frmarian          #+#    #+#             */
/*   Updated: 2024/09/27 12:32:13 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_check(t_stack *stacks, char **split_av, bool flag)
{
	int	i;

	i = 0;
	if (flag)
	{
		while (split_av[i])
		{
			if (!valid_av(split_av[i]))
			{
				free_split(split_av);
				error(stacks);
			}
			i++;
		}
	}
}
