/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_token_and_append.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:38:00 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/16 18:28:47 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_token	*make_token(int type, char *str, t_state *s)
{
	t_token	*token;

	token = ft_malloc(sizeof(t_token), &(s->gc), s);
	if (!token)
		return (NULL);
	token->type = type;
	token->content = str;
	if (token->type == CMD || token->type == ARG)
		token->is_special = 0;
	else
		token->is_special = 1;
	return (token);
}

static t_token	**append_array(t_token *token, t_token **array, t_state *s)
{
	t_token	**new_array;
	int		len;
	int		i;

	len = array_len(array);
	new_array = ft_malloc(sizeof(t_token *) * (len + 2), &(s->gc), s);
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[i] = token;
	new_array[i + 1] = NULL;
	return (new_array);
}

t_token	**mt_append(int type, char *str, t_token **array, t_state *s)
{
	t_token	*token;
	t_token	**token_array;

	token = make_token(type, str, s);
	if (!token)
		return (NULL);
	token_array = append_array(token, array, s);
	return (token_array);
}

t_token	**ms_append(char *line, t_token **array, t_state *s, t_msh msh)
{
	char	*str;
	int		len;
	int		type;

	len = 0;
	if (msh.sep == NOQUOTE_SEP)
		len = find_word_len(line, msh.i);
	else
	{
		msh.i++;
		while (line[msh.i + len] && line[msh.i + len] != msh.sep)
			len++;
	}
	str = ft_malloc(sizeof(char) * (len + 1), &(s->gc), s);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &line[msh.i], (len + 1));
	if (is_cmd(array) == 1)
		type = CMD;
	else
		type = ARG;
	return (mt_append(type, str, array, s));
}
