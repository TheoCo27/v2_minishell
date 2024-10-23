/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:48:02 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/23 20:14:33 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../signal/ft_signal.h"

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
		if (info->pid == 0 && ft_pipelst_size(*lst) > 1)
			ft_close_remaining_pipes(info, lst);
		if (info->pid != 0)
			return (-1);
		garbage_destroy();
		exit(1);
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
	char *error_str;

	if (execve(cmd->path, cmd->arg, cmd->state->env) == -1)
	{
		if (errno != ENOENT)
			perror(cmd->arg[0]);
		if (errno == ENOENT)
		{
			error_str = ft_strjoin(cmd->arg[0], ": Command not found\n");
			if (!error_str)
				return (garbage_destroy(), 1);
			ft_putstr_fd(error_str, 2);
		}
		if (ft_pipelst_size(*lst) > 1)
			ft_close_remaining_pipes(cmd, lst);
		garbage_destroy();
		exit (errno_to_exit_code(errno));
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
		perror("pipe failed");
		return (-1);
	}
	return (0);
}

int ft_fork(t_info_exec *cmd, t_info_exec **lst)
{
	(void)lst;
	cmd->pid = fork();
	if (cmd->pid < 0)
	{
		ft_putendl_fd("Error fork", 2);
		return (-1);
	}
	if (cmd->pid == 0)
		set_exec_sig();
	return (0);
}