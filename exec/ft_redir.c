/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:30:55 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/23 18:58:34 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int heredoc_tab_tofd(t_file_lst *file, t_info_exec *cmd, t_info_exec **lst)
{
	int	i;
	int	fd;

	i = 0;
	fd = ft_open(file->name, 'w', cmd, lst);
	while(file->heredoc_content[i])
	{
		ft_putendl_fd(file->heredoc_content[i], fd);
		i++;
	}
	close(fd);
	return (0);
}

static int ft_heredoc(t_info_exec *cmd, t_file_lst *file, t_info_exec **lst)
{
	if (file->type == 'h')
	{
		heredoc_tab_tofd(file, cmd, lst);
		cmd->in_fd = ft_open(file->name, 'r', cmd, lst);
		if (ft_dup2(cmd->in_fd, 0) == -1)
		{
			if (ft_pipelst_size(*lst) > 1)
				ft_close_remaining_pipes(cmd, lst);
			garbage_destroy();
			exit(1);
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
			if (ft_pipelst_size(*lst) > 1)
				ft_close_remaining_pipes(cmd, lst);
			garbage_destroy();
			exit(1);
		}
	}
	if (file->type == 'r')
	{
		cmd->in_fd = ft_open(file->name, file->type, cmd, lst);
		if (ft_dup2(cmd->in_fd, 0) == -1)
		{
			if (ft_pipelst_size(*lst) > 1)
				ft_close_remaining_pipes(cmd, lst);
			garbage_destroy();
			exit(1);
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
