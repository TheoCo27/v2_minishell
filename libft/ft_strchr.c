/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:36:29 by tcohen            #+#    #+#             */
/*   Updated: 2024/06/04 17:56:08 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	tofind;
	char	*str;
	int		i;

	str = (char *)s;
	tofind = (char)c;
	i = 0;
	while (str[i] != tofind && s[i])
		i++;
	if (str[i] == tofind)
		return (str + i);
	else
		return (NULL);
}
