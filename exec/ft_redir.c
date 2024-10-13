/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:30:55 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/11 18:18:42 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int ft_heredoc(t_info_exec *cmd, t_file_lst *file, t_info_exec **lst)
{
	if (file->type == 'h')
	{
		cmd->in_fd = ft_open(file->name, 'r', cmd, lst);
		if (ft_dup2(cmd->in_fd, 0) == -1)
		{
			close(cmd->out_fd);
			ft_close_pipe(cmd->pipe_fd);//I think just close pipd_fd[1]
			ft_close_remaining_pipes(cmd, lst);
			ft_pipelst_clear(lst);
			exit(errno);
		}
	}
	return (0);
}

static int ft_redir_one(t_info_exec *cmd, t_file_lst *file, t_info_exec **lst)
{
	ft_heredoc(cmd, file, lst);
	if (file->type == 'a' || file->type == 'w')
	{
		cmd->out_fd = ft_open(file->name, file->type, cmd, lst);
		if (ft_dup2(cmd->out_fd, 1) == -1)
		{
			close(cmd->out_fd);
			ft_close_pipe(cmd->pipe_fd);//I think just close pipd_fd[1]
			ft_close_remaining_pipes(cmd, lst);
			ft_pipelst_clear(lst);
			exit(errno);
		}
	}
	if (file->type == 'r')
	{
		cmd->in_fd = ft_open(file->name, file->type, cmd, lst);
		if (ft_dup2(cmd->in_fd, 0) == -1)
		{
			close(cmd->out_fd);
			ft_close_pipe(cmd->pipe_fd);//I think just close pipd_fd[1]
			ft_close_remaining_pipes(cmd, lst);
			ft_pipelst_clear(lst);
			exit(errno);
		}
	}
	return (0);
}

int ft_redir_all(t_info_exec *cmd, t_info_exec **lst)
{
	t_file_lst	*file;

	file = cmd->file_lst;
	while(file)
	{
		ft_redir_one(cmd, file, lst);
		file = file->next;
	}
	return (0);
}
