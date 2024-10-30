/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:19:43 by frmarian          #+#    #+#             */
/*   Updated: 2024/05/01 12:59:51 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_putstr(int n);
static int	ft_checksign(int n);
static int	ft_strlendigit(int n);

static int	ft_strlendigit(int n)
{
	int		strlen;

	strlen = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		strlen++;
	}
	return (strlen);
}

static int	ft_checksign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static char	ft_putstr(int n)
{
	char	c;
	int		aux;

	if (n <= -2147483648)
	{
		aux = n % 10;
		aux *= -1;
		c = aux + '0';
		return (c);
	}
	if (n > 0)
		c = (n % 10) + '0';
	else
		c = (-(n) % 10) + '0';
	return (c);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		len;

	sign = ft_checksign(n);
	len = sign + ft_strlendigit(n) + 1;
	str = (char *)malloc(len);
	if (!str)
		return (NULL);
	str[len - 1] = '\0';
	while ((len - 1) != sign)
	{
		str[len - 2] = ft_putstr(n);
		n /= 10;
		len--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
