/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:31:49 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/06 05:17:44 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_stx_err(char *str)
{
	ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
}

static void	init_array_maker(t_am *am)
{
	am->i = 0;
	am->sq = 0;
	am->dq = 0;
	am->last_token_spe = -1;
}

t_token	**make_token_array(char *line, t_token **token_array, t_state *s)
{
	t_am	am;

	init_array_maker(&am);
	while (line[am.i])
	{
		while (line[am.i] && ft_is_space(line[am.i]))
			am.i++;
		set_quotes_mode(&am.sq, &am.dq, line[am.i]);
		if (noquote(am.sq, am.dq))
		{
			while (line[am.i] && ft_is_space(line[am.i]))
				am.i++;
			if (line[am.i] == '<' && line[am.i + 1] == '<')
			{
				if (am.last_token_spe == 1
					&& token_array[array_len(token_array) - 1]-> type != PIPE)
					return (s->exit_code = 2, ft_stx_err("<<"), NULL);
				token_array = mt_append(HEREDOC, NULL, token_array, s);
				am.i += 2;
				am.last_token_spe = 1;
			}
			else if (line[am.i] == '<')
			{
				if (am.last_token_spe == 1
					&& token_array[array_len(token_array) - 1]-> type != PIPE)
					return (s->exit_code = 2, ft_stx_err("<"), NULL);
				token_array = mt_append(INFILE, NULL, token_array, s);
				am.i += 1;
				am.last_token_spe = 1;
			}
			else if (line[am.i] == '>' && line[am.i + 1] == '>')
			{
				if (am.last_token_spe == 1
					&& token_array[array_len(token_array) - 1]-> type != PIPE)
					return (s->exit_code = 2, ft_stx_err(">>"), NULL);
				token_array = mt_append(OUTFILE_APPEND, NULL, token_array, s);
				am.i += 2;
				am.last_token_spe = 1;
			}
			else if (line[am.i] == '>')
			{
				if (am.last_token_spe == 1
					&& token_array[array_len(token_array) - 1]-> type != PIPE)
					return (s->exit_code = 2, ft_stx_err(">"), NULL);
				token_array = mt_append(OUTFILE_TRUNCATE, NULL, token_array, s);
				am.i += 1;
				am.last_token_spe = 1;
			}
			else if (line[am.i] == '|')
			{
				if (am.last_token_spe == 1 || am.last_token_spe == -1)
					return (s->exit_code = 2, ft_stx_err("|"), NULL);
				token_array = mt_append(PIPE, NULL, token_array, s);
				am.i += 1;
				am.last_token_spe = 1;
			}
			else
			{
				am.word_len = find_word_len(line, am.i);
				am.msh.i = am.i;
				am.msh.sep = NOQUOTE_SEP;
				token_array = ms_append(line, token_array, s, am.msh);
				am.i += am.word_len;
				am.last_token_spe = 0;
			}
		}
		else if (am.sq == 1)
		{
			am.next_quote = get_next_quote(line, (am.i + 1), SQUOTE);
			if (am.next_quote == -1)
				return (ft_stx_err("'"), s->exit_code = 2, NULL);
			am.msh.i = am.i;
			am.msh.sep = SQUOTE;
			token_array = ms_append(line, token_array, s, am.msh);
			am.i = am.next_quote + 1;
			am.sq = 0;
			am.last_token_spe = 0;
		}
		else if (am.dq == 1)
		{
			am.next_quote = get_next_quote(line, (am.i + 1), DQUOTE);
			if (am.next_quote == -1)
				return (ft_stx_err("\""), s->exit_code = 2, NULL);
			am.msh.i = am.i;
			am.msh.sep = DQUOTE;
			token_array = ms_append(line, token_array, s, am.msh);
			am.i = am.next_quote + 1;
			am.dq = 0;
			am.last_token_spe = 0;
		}
		while (line[am.i] && ft_is_space(line[am.i]))
			am.i++;
	}
	return (token_array);
}

t_token	***parseline(t_state *s, char *line)
{
	t_token	**token_array;
	t_token	***main_array;

	line = replace_vars(line, s);
	if (!line)
		return (NULL);
	token_array = ft_malloc(sizeof(t_token *), &(s->gc), s);
	if (!token_array)
		return (NULL);
	*token_array = NULL;
	token_array = make_token_array(line, token_array, s);
	if (!token_array)
		return (NULL);
	if (last_array_elem_valid(token_array) == 0)
		return (s->exit_code = 2, NULL);
	main_array = ft_split_array_tokens(token_array, PIPE, s);
	if (!main_array)
		return (NULL);
	return (main_array);
}
