/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:41:18 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/05 21:01:20 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	noquote(int sq, int dq)
{
	if (sq == 0 && dq == 0)
		return (1);
	return (0);
}

int	get_next_quote(char *line, int start, int quote)
{
	int	i;

	i = start;
	while (line[i])
	{
		if (line[i] == quote)
			return (i);
		i++;
	}
	return (-1);
}

int	find_word_len(char *line, int i)
{
	int	len;

	len = 0;
	while (line[i + len] && line[i + len] != SQUOTE && line[i + len] != DQUOTE
		&& line[i + len] != '<' && line[i + len] != '>' && line[i + len] != '|'
		&& !ft_is_space(line[i + len]))
		len++;
	return (len);
}

int	last_array_elem_valid(t_token **array)
{
	int	type;
	int	spe;
	int	i;

	i = 0;
	type = -1;
	spe = -1;
	while (array[i])
	{
		type = array[i]->type;
		spe = array[i]->is_special;
		i++;
	}
	if (spe == 0)
		return (1);
	if (spe == 1 && type == PIPE)
		ft_stx_err("|");
	else if (spe == 1)
		ft_stx_err("'newline'");
	return (0);
}
