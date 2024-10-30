/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:11:02 by frmarian          #+#    #+#             */
/*   Updated: 2024/09/23 12:47:51 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	char	*str;

	if (!s)
		return (NULL);
	ss = (char *)s;
	if (start > (unsigned int)ft_strlen(ss))
		return (ft_strdup(""));
	if (len > (size_t)ft_strlen(ss + start))
		len = (size_t)ft_strlen(ss + start);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
