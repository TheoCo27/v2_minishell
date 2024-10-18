/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 01:01:13 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/14 04:43:00 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	nqstr(t_am *am, char **line, t_token ***token_array, t_state *s)
{
	am->word_len = find_word_len(line[0], am->i);
	am->msh.i = am->i;
	am->msh.sep = NOQUOTE_SEP;
	token_array[0] = ms_append(line[0], token_array[0], s, am->msh);
	if (!(token_array[0]))
	{
		am->error = 1;
		return ;
	}
	am->i += am->word_len;
	am->last_token_spe = 0;
}

int	sqstr(t_am *am, char **line, t_token ***token_array, t_state *s)
{
	if (am->sq != 1)
		return (0);
	am->next_quote = get_next_quote(line[0], (am->i + 1), SQUOTE);
	if (am->next_quote == -1)
	{
		s->exit_code = 2;
		ft_stx_err("'");
		am->error = 1;
		return (1);
	}
	am->msh.i = am->i;
	am->msh.sep = SQUOTE;
	token_array[0] = ms_append(line[0], token_array[0], s, am->msh);
	if (!(token_array[0]))
	{
		am->error = 1;
		return (1);
	}
	am->i = am->next_quote + 1;
	am->sq = 0;
	am->last_token_spe = 0;
	return (1);
}

void	dqstr(t_am *am, char **line, t_token ***token_array, t_state *s)
{
	if (am->dq != 1)
		return ;
	am->next_quote = get_next_quote(line[0], (am->i + 1), DQUOTE);
	if (am->next_quote == -1)
	{
		s->exit_code = 2;
		ft_stx_err("\"");
		am->error = 1;
		return ;
	}
	am->msh.i = am->i;
	am->msh.sep = DQUOTE;
	token_array[0] = ms_append(line[0], token_array[0], s, am->msh);
	if (!(token_array[0]))
	{
		am->error = 1;
		return ;
	}
	am->i = am->next_quote + 1;
	am->dq = 0;
	am->last_token_spe = 0;
	return ;
}
