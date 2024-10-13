/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token_and_append_helpers.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:41:28 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/05 18:43:35 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	cmd_present(t_token **array)
{
	int	i;
	int	start;

	if (array_len(array) == 0)
		return (0);
	start = array_len(array) - 1;
	i = start;
	while (i >= 0)
	{
		if (array[i]->type == CMD)
			return (1);
		if (array[i]->type == PIPE)
			return (0);
		i--;
	}
	return (0);
}

int	is_cmd(t_token **array)
{
	if (array_len(array) == 0 || array[array_len(array) - 1]->type == PIPE
		|| (cmd_present(array) == 0 && array_len(array) > 1
			&& array[array_len(array) - 1]->type == ARG
			&& (array[array_len(array) - 2]->is_special == 1
				&& array[array_len(array) - 2]->type != PIPE)))
		return (1);
	else
		return (0);
}
