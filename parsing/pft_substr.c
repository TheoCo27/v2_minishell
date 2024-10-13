/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:55:25 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/05 18:37:33 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*pft_substr(char const *s, int start, int len, t_state *state)
{
	char	*str;
	int		i;
	int		slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		start = slen;
	i = 0;
	while (*(s + start + i) && i < len)
		i++;
	str = ft_malloc(sizeof(char) * (i + 1), &(state->gc), state);
	if (!str)
		return (NULL);
	i = 0;
	while (*(s + start + i) && i < len)
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
