/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:20:51 by frmarian          #+#    #+#             */
/*   Updated: 2024/05/02 11:12:10 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ptr2;
	const unsigned char	*ptr1;

	i = -1;
	ptr1 = (const unsigned char *)src;
	ptr2 = (unsigned char *)dst;
	if (!src && !dst)
		return (0);
	if (ptr2 > ptr1)
	{
		while (len != 0)
		{
			len--;
			ptr2[len] = ptr1[len];
		}
	}
	else
		while (++i < len)
			ptr2[i] = ptr1[i];
	return (dst);
}
