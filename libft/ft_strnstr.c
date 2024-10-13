/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:29:56 by tcohen            #+#    #+#             */
/*   Updated: 2024/05/27 19:12:52 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;
	char	*tofind;

	tofind = (char *)big;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return (tofind);
	i = 0;
	if (little[0] == 0)
		return (tofind);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && (i + j) < len)
			j++;
		if (j == little_len)
			return (tofind + i);
		i++;
	}
	return (0);
}
