/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:51:36 by tcohen            #+#    #+#             */
/*   Updated: 2024/06/04 17:53:46 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	char	tofind;
	char	*str;

	s_len = ft_strlen(s);
	tofind = (char)c;
	str = (char *)s;
	while (str[s_len] != tofind && s_len >= 0)
	{
		if (s_len == 0)
			break ;
		s_len--;
	}
	if (str[s_len] == tofind)
		return (str + s_len);
	else
		return (NULL);
}
