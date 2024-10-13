/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:54:45 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/05 12:47:11 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*pft_strdup(const char *s1, t_state *state)
{
	int		i;
	int		len;
	char	*dup;

	if (!s1)
		return (NULL);
	i = 0;
	len = 0;
	while (*(s1 + len))
		len++;
	dup = ft_malloc(sizeof(char) * (len + 1), &(state->gc), state);
	if (!dup)
		return (NULL);
	while (*(s1 + i))
	{
		*(dup + i) = *(s1 + i);
		i++;
	}
	*(dup + i) = '\0';
	return (dup);
}
