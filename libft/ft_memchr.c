/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:55:55 by tcohen            #+#    #+#             */
/*   Updated: 2024/05/24 13:05:21 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	tofind;
	unsigned char	*tolook;
	size_t			i;
	void			*output;

	tofind = (unsigned char)c;
	tolook = (unsigned char *)s;
	output = (void *)s;
	i = 0;
	while (i < n)
	{
		if (tolook[i] == tofind)
			return (output + i);
		i++;
	}
	return (NULL);
}
