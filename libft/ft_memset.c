/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:07:30 by tcohen            #+#    #+#             */
/*   Updated: 2024/05/27 15:22:29 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*filler;

	filler = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		filler[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
