/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 01:00:59 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/14 04:38:52 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	h(t_am *am, char **line, t_token ***token_array, t_state *s)
{
	if (line[0][am->i] == '<' && line[0][am->i + 1] == '<')
	{
		if (am->last_token_spe == 1
			&& token_array[0][array_len(token_array[0]) - 1]-> type != PIPE)
		{
			s->exit_code = 2;
			ft_stx_err("<<");
			am->error = 1;
			return (1);
		}
		token_array[0] = mt_append(HEREDOC, NULL, token_array[0], s);
		if (!(token_array[0]))
		{
			am->error = 1;
			return (1);
		}
		am->i += 2;
		am->last_token_spe = 1;
		return (1);
	}
	return (0);
}

int	i(t_am *am, char **line, t_token ***token_array, t_state *s)
{
	if (line[0][am->i] == '<')
	{
		if (am->last_token_spe == 1
			&& token_array[0][array_len(token_array[0]) - 1]-> type != PIPE)
		{
			s->exit_code = 2;
			ft_stx_err("<");
			am->error = 1;
			return (1);
		}
		token_array[0] = mt_append(INFILE, NULL, token_array[0], s);
		if (!(token_array[0]))
		{
			am->error = 1;
			return (1);
		}
		am->i += 1;
		am->last_token_spe = 1;
		return (1);
	}
	return (0);
}

int	oa(t_am *am, char **line, t_token ***token_array, t_state *s)
{
	if (line[0][am->i] == '>' && line[0][am->i + 1] == '>')
	{
		if (am->last_token_spe == 1
			&& token_array[0][array_len(token_array[0]) - 1]-> type != PIPE)
		{
			s->exit_code = 2;
			ft_stx_err(">>");
			am->error = 1;
			return (1);
		}
		token_array[0] = mt_append(OUTFILE_APPEND, NULL, token_array[0], s);
		if (!(token_array[0]))
		{
			am->error = 1;
			return (1);
		}
		am->i += 2;
		am->last_token_spe = 1;
		return (1);
	}
	return (0);
}

int	ot(t_am *am, char **line, t_token ***token_array, t_state *s)
{
	if (line[0][am->i] == '>')
	{
		if (am->last_token_spe == 1
			&& token_array[0][array_len(token_array[0]) - 1]-> type != PIPE)
		{
			s->exit_code = 2;
			ft_stx_err(">");
			am->error = 1;
			return (1);
		}
		token_array[0] = mt_append(OUTFILE_TRUNCATE, NULL, token_array[0], s);
		if (!(token_array[0]))
		{
			am->error = 1;
			return (1);
		}
		am->i += 1;
		am->last_token_spe = 1;
		return (1);
	}
	return (0);
}

int	p(t_am *am, char **line, t_token ***token_array, t_state *s)
{
	if (line[0][am->i] == '|')
	{
		if (am->last_token_spe == 1 || am->last_token_spe == -1)
		{
			s->exit_code = 2;
			ft_stx_err("|");
			am->error = 1;
			return (1);
		}
		token_array[0] = mt_append(PIPE, NULL, token_array[0], s);
		if (!(token_array[0]))
		{
			am->error = 1;
			return (1);
		}
		am->i += 1;
		am->last_token_spe = 1;
		return (1);
	}
	return (0);
}
