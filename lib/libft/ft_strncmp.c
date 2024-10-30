/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:18:16 by frmarian          #+#    #+#             */
/*   Updated: 2024/05/02 10:16:39 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (ptr1[i] || ptr2[i]))
	{
		if (ptr1[i] != ptr2[i]
			|| !ptr1[i] || !ptr2[i])
			return ((int)ptr1[i] - (int)ptr2[i]);
		i++;
	}
	return (0);
}
