/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:48:02 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/13 20:41:23 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open(char *file_name, char mode, t_info_exec *info, t_info_exec **lst)
{
	int	fd;

	if (mode == 'w')
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (mode == 'a')
		fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (mode == 'r')
		fd = open(file_name, O_RDONLY);
	if (mode == 'h')
		fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
	{
		perror(file_name);
		ft_close_pipe(info->pipe_fd);
		ft_close_remaining_pipes(info, lst);
		ft_pipelst_clear(lst);
		ft_destroy_garbage();
		exit(errno);
	}
	return (fd);
}

int	ft_dup2(int old_fd, int new_fd)
{
	if (dup2(old_fd, new_fd) == -1)
	{
		close(old_fd);
		perror("dup2 failed");
		return (-1);
	}
	close(old_fd);
	return (0);
}

int	ft_execve(t_info_exec *cmd, t_info_exec **lst)
{
	if (execve(cmd->path, cmd->arg, cmd->env) == -1)
	{
		perror(cmd->path);
		ft_clean_info(cmd);
		if (ft_pipelst_size(*lst) > 1)
			ft_close_remaining_pipes(cmd, lst);
		ft_pipelst_clear(lst);
		ft_destroy_garbage();
		exit (errno);
	}
	return (-1);
}

int	ft_pipe(int fd[2], t_info_exec	**lst, t_info_exec *cmd)
{
	t_info_exec	*temp;

	temp = *lst;
	if (pipe(fd) == -1)
	{
		while(temp)
		{
			if (temp == cmd)
				break;
			ft_close_pipe(temp->pipe_fd);
		}
		ft_pipelst_clear(lst);
		perror("pipe failed");
		ft_destroy_garbage();
		exit(errno);
	}
	return (0);
}

int ft_fork(t_info_exec *cmd, t_info_exec **lst)
{
	int status;

	status = 0;
	cmd->pid = fork();
	if (cmd->pid < 0)
	{
		ft_putendl_fd("Error fork", 2);
		status = ft_wait_pids(*lst, status);
		ft_close_allpipes(*lst);
		ft_pipelst_clear(lst);
		ft_destroy_garbage();
		exit(status);
	}
	return (status);
}