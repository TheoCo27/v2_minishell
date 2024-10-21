/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:27:54 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/21 20:32:01 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_pipe(int pipe_fd[2])
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

void	ft_close_all(int pipe_fd[2], int in_out_fd)
{
	ft_close_pipe(pipe_fd);
	close(in_out_fd);
}

int	exit_status(int status, t_info_exec *lst)
{
	if (WIFEXITED(status))
	{
		lst->state->exit_code = WEXITSTATUS(status);
		return (WEXITSTATUS(status));
	}
	else if (WIFSTOPPED(status))
	{
		lst->state->exit_code = 128 + WSTOPSIG(status);
		return (128 + WSTOPSIG(status));
	}
	else if (WIFSIGNALED(status))
	{
		lst->state->exit_code = 128 + WTERMSIG(status);
		return (128 + WTERMSIG(status));
	}
	return (-1);
}

int	ft_wait_pids(t_info_exec *lst, int status)
{
	t_info_exec	*temp;

	temp = lst;
	while(temp)
	{
		if (temp->pid != -1)
			waitpid(temp->pid, &status, 0);
		if (WIFSTOPPED(status))
			lst->state->test = 128 + WSTOPSIG(status);
		else if (WIFSIGNALED(status))
			lst->state->test = 128 + WTERMSIG(status);
		temp = temp->next;
	}
	return (exit_status(status, lst));
}

int	ft_clean_info(t_info_exec *cmd)
{
	g_free(cmd->cmd);
	g_free(cmd->path);
	ft_free_all(cmd->arg);
	ft_free_all(cmd->t_path);
	return (0);
}
