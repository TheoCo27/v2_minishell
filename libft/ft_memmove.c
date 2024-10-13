/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:00:16 by tcohen            #+#    #+#             */
/*   Updated: 2024/05/27 16:15:30 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dst_tmp;
	char	*src_tmp;

	dst_tmp = (char *)dest;
	src_tmp = (char *)src;
	if (dst_tmp > src_tmp)
		while (n--)
			dst_tmp[n] = src_tmp[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
