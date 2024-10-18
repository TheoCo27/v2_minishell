/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:31:49 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/16 18:36:04 by tcohen           ###   ########.fr       */
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
	am->error = 0;
}

/* t_a : token_array */
t_token	**make_token_array(char *line, t_token **t_a, t_state *s)
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
			if (!h(&am, &line, &t_a, s) && !i(&am, &line, &t_a, s)
				&& !oa(&am, &line, &t_a, s) && !ot(&am, &line, &t_a, s)
				&& !p(&am, &line, &t_a, s))
				nqstr(&am, &line, &t_a, s);
		}
		else if (!sqstr(&am, &line, &t_a, s))
			dqstr(&am, &line, &t_a, s);
		if (am.error == 1)
			return (NULL);
		while (line[am.i] && ft_is_space(line[am.i]))
			am.i++;
	}
	return (t_a);
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
