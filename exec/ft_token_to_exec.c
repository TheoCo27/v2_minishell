/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_to_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 04:41:59 by theog             #+#    #+#             */
/*   Updated: 2024/10/16 14:05:36 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int ft_is_redir_token(t_token *token)
{
	if (token->type == INFILE)
		return (1);
	if (token->type == OUTFILE_APPEND)
		return (1);
	if (token->type == OUTFILE_TRUNCATE)
		return (1);
	if (token->type == HEREDOC)
		return (1);
	return (0);
}

t_info_exec *ft_convert_redir_token(t_info_exec *cmd, t_token **array, int *i)
{
	t_file_lst *new;

    if (array[*i]->type == INFILE && array[(*i) + 1]->type == ARG)
    {
		new = ft_newfile(array[(*i) + 1]->content, 'r');
		if (!new)
			return (NULL);
        ft_fileadd_back(&cmd->file_lst, new);
    }
    if (array[*i]->type == OUTFILE_APPEND && array[(*i) + 1]->type == ARG)
    {
		new = ft_newfile(array[(*i) + 1]->content, 'a');
		if (!new)
			return (NULL);
        ft_fileadd_back(&cmd->file_lst, new);
    }
    if (array[*i]->type == OUTFILE_TRUNCATE && array[(*i) + 1]->type == ARG)
    {
		new = ft_newfile(array[(*i) + 1]->content, 'w');
		if (!new)
			return (NULL);
        ft_fileadd_back(&cmd->file_lst, new);
    }
    return (cmd);
}

static t_info_exec	*ft_token_to_cmd(t_token *token, t_info_exec *cmd)
{
	cmd->cmd = ft_strdup(token->content);
	if (!cmd->cmd)
		return (NULL);
	cmd->arg = ft_tabstr_addback(token->content, cmd->arg);
	if (!cmd->arg)
		return (NULL);
	return (cmd);
}

static t_info_exec *ft_convert_heredoc_token(t_info_exec *cmd, t_token **array, int *i)
{
	t_file_lst *new;

    if (array[*i]->type == HEREDOC && array[(*i) + 1]->type == ARG)
    {
		new = ft_newfile(array[(*i) + 1]->content, 'h');
		if (!new)
			return (NULL);
        ft_fileadd_back(&cmd->file_lst, new);
    }
	return (cmd);
}
t_info_exec *ft_token_to_exec(t_token **array)
{
	t_info_exec *cmd;
	int			i;

	i = 0;
	cmd = ft_pipelst_new();
	if (!cmd)
		return (NULL);
	while(array[i])
	{
		if (ft_convert_redir_token(cmd, array, &i) == NULL)
			return (NULL);
		ft_convert_heredoc_token(cmd, array, &i);
		if (array[i]->type == CMD)
			if (ft_token_to_cmd(array[i], cmd) == NULL)
				return (NULL);
		if (i > 0 && array[i]->type == ARG && ft_is_redir_token(array[i - 1]) == 0)
		{
			cmd->arg = ft_tabstr_addback(array[i]->content, cmd->arg);
			if (!cmd->arg)
				return (NULL);
		}
		i++;
	}
	return (cmd);
}
