/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:40:22 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/05 20:50:05 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	array_len(t_token **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

int	main_array_len(t_token ***array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

int	ft_is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	set_quotes_mode(int *sq, int *dq, char c)
{
	if (c == SQUOTE && *sq == 0 && *dq == 0)
		*sq = 1;
	else if (c == DQUOTE && *sq == 0 && *dq == 0)
		*dq = 1;
	else if (c == SQUOTE && *sq == 1)
		*sq = 0;
	else if (c == DQUOTE && *dq == 1)
		*dq = 0;
}
